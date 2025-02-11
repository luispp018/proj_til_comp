#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "targets/frame_size_calculator.h"
#include ".auto/all_nodes.h"  // all_nodes.h is automatically generated

#include "til_parser.tab.h"

#include <stack>
#include <optional>

//---------------------------------------------------------------------------

void til::postfix_writer::acceptCovariantNode(std::shared_ptr<cdk::basic_type> const target_type, cdk::expression_node * const node, int lvl) {

  if (target_type == nullptr || node == nullptr) {
    return; // Target_type and node should not be null
  }
  if (target_type->name() != cdk::TYPE_FUNCTIONAL || !node->is_typed(cdk::TYPE_FUNCTIONAL)) {
    node->accept(this, lvl);
    if (target_type->name() == cdk::TYPE_DOUBLE && node->is_typed(cdk::TYPE_INT)) {
      _pf.I2D();
    }
    return;
  }

  auto lfunc_type = cdk::functional_type::cast(target_type);
  auto rfunc_type = cdk::functional_type::cast(node->type());

  bool needsWrap = false;

  if (lfunc_type->output(0)->name() == cdk::TYPE_DOUBLE && rfunc_type->output(0)->name() == cdk::TYPE_INT) {
    needsWrap = true; // Output type conversion needed
  } else {
    for (size_t i = 0; i < lfunc_type->input_length(); i++) {
      if (lfunc_type->input(i)->name() == cdk::TYPE_INT && rfunc_type->input(i)->name() == cdk::TYPE_DOUBLE) {
        needsWrap = true; // Input type conversion needed
        break;
      }
    }
  }

  if (!needsWrap) {
    node->accept(this, lvl);
    return;
  }

  auto lineno = node->lineno();

  // Unique wrapper name and declaration generation
  auto aux_global_decl_name = "_wrapper_target_" + std::to_string(_lbl++);
  auto aux_global_decl = new til::declaration_node(lineno, tPRIVATE, rfunc_type, aux_global_decl_name, nullptr);
  auto aux_global_var = new cdk::variable_node(lineno, aux_global_decl_name);

  _forceOutsideFunction = true;
  aux_global_decl->accept(this, lvl);
  _forceOutsideFunction = false;

  if (!_functionLabels.empty() && !_forceOutsideFunction){
    _pf.TEXT(_functionLabels.top());
  } else {
    _pf.DATA();
  }
  _pf.ALIGN();

  auto aux_global_assignment = new cdk::assignment_node(lineno, aux_global_var, node);
  aux_global_assignment->accept(this, lvl);

  auto aux_global_rvalue = new cdk::rvalue_node(lineno, aux_global_var);

  auto args = new cdk::sequence_node(lineno);
  auto call_args = new cdk::sequence_node(lineno);
  for (size_t i = 0; i < lfunc_type->input_length(); i++) {
    auto arg_name = "_arg" + std::to_string(i); // Generate a unique name for the argument

    auto arg_decl = new til::declaration_node(lineno, tPRIVATE, lfunc_type->input(i), arg_name, nullptr);
    args = new cdk::sequence_node(lineno, arg_decl, args);

    auto arg_rvalue = new cdk::rvalue_node(lineno, new cdk::variable_node(lineno, arg_name)); // Create a rvalue node for the argument
    call_args = new cdk::sequence_node(lineno, arg_rvalue, call_args); // Add the rvalue to the call arguments sequence
  }

  auto function_call = new til::function_call_node(lineno, aux_global_rvalue, call_args); // Create a function call node with the global variable and arguments
  auto return_node = new til::return_node(lineno, function_call); // Create a return node for the function call
  auto block = new til::block_node(lineno, new cdk::sequence_node(lineno), new cdk::sequence_node(lineno, return_node)); // Create a block node with the return node

  auto wrapping_function = new til::function_node(lineno, args, lfunc_type->output(0), block);

  wrapping_function->accept(this, lvl);
}

//---------------------------------------------------------------------------

void til::postfix_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void til::postfix_writer::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}
void til::postfix_writer::do_double_node(cdk::double_node * const node, int lvl) {

  if (!_functionLabels.empty() && !_forceOutsideFunction) {
      _pf.DOUBLE(node->value());
  } else {
      _pf.SDOUBLE(node->value());
  }
}
void til::postfix_writer::do_not_node(cdk::not_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;

    node->argument()->accept(this, lvl + 2);
    _pf.INT(0);
    _pf.EQ();
}
void til::postfix_writer::do_and_node(cdk::and_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;

    int lbl;
    node->left()->accept(this, lvl);
    _pf.DUP32();
    _pf.JZ(mklbl(lbl = ++_lbl));
    node->right()->accept(this, lvl);
    _pf.AND();
    _pf.ALIGN();
    _pf.LABEL(mklbl(lbl));
}
void til::postfix_writer::do_or_node(cdk::or_node * const node, int lvl) {
    ASSERT_SAFE_EXPRESSIONS;

    int lbl;
    node->left()->accept(this, lvl);
    _pf.DUP32();
    _pf.JNZ(mklbl(lbl = ++_lbl));
    node->right()->accept(this, lvl);
    _pf.OR();
    _pf.ALIGN();
    _pf.LABEL(mklbl(lbl));
}

//---------------------------------------------------------------------------

void til::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

void til::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
   if (!_functionLabels.empty() && !_forceOutsideFunction) {
     _pf.INT(node->value());
   } else {
     _pf.SINT(node->value());
   }
}

void til::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1;

  // string generation
  _pf.RODATA();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl1 = ++_lbl));
  _pf.SSTRING(node->value());

  if (!_functionLabels.empty() && !_forceOutsideFunction) {
    _pf.TEXT(_functionLabels.top());
    _pf.ADDR(mklbl(lbl1));
  } else {
    _pf.DATA();
    _pf.SADDR(mklbl(lbl1));
  }
}

//---------------------------------------------------------------------------

void til::postfix_writer::do_unary_minus_node(cdk::unary_minus_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl);
  _pf.NEG();
}

void til::postfix_writer::do_unary_plus_node(cdk::unary_plus_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl);
}

//---------------------------------------------------------------------------

void til::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.ADD();
}
void til::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.SUB();
}
void til::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MUL();
}
void til::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.DIV();
}
void til::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}
void til::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LT();
}
void til::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LE();
}
void til::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GE();
}
void til::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GT();
}
void til::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.NE();
}
void til::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.EQ();
}

//---------------------------------------------------------------------------

void til::postfix_writer::do_variable_node(cdk::variable_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  auto symbol = _symtab.find(node->name());

  if (symbol->qualifier() == tEXTERNAL) {
    _externalFunctionName = symbol->name();
  } else if (symbol->global()) {
    _pf.ADDR(node->name());
  } else {
    _pf.LOCAL(symbol->offset());
  }
}

void til::postfix_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->lvalue()->accept(this, lvl);
  _pf.LDINT();
}

void til::postfix_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  acceptCovariantNode(node->type(), node->rvalue(), lvl);
  if (node->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.DUP64();
  } else {
    _pf.DUP32();
  }

  node->lvalue()->accept(this, lvl);
  if (node->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.STDOUBLE();
  } else {
    _pf.STINT();
  }
}

//---------------------------------------------------------------------------

void til::postfix_writer::do_evaluation_node(til::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  node->argument()->accept(this, lvl);

  if (node->argument()->type()->size() > 0) {
    _pf.TRASH(node->argument()->type()->size());
  }
}

void til::postfix_writer::do_print_node(til::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  for (size_t ix = 0; ix < node->arguments()->size(); ix++) {
    auto child = dynamic_cast<cdk::expression_node*>(node->arguments()->node(ix));

    child->accept(this, lvl);
    if (child->is_typed(cdk::TYPE_INT)) {
      _externalFunctionsToDeclare.insert("printi");
      _pf.CALL("printi");
      _pf.TRASH(4);
    } else if (child->is_typed(cdk::TYPE_DOUBLE)) {
      _externalFunctionsToDeclare.insert("printd");
      _pf.CALL("printd");
      _pf.TRASH(8);
    } else if (child->is_typed(cdk::TYPE_STRING)) {
      _externalFunctionsToDeclare.insert("prints");
      _pf.CALL("prints");
      _pf.TRASH(4);
    }
  }

  if (node->newline()) {
    _externalFunctionsToDeclare.insert("println");
    _pf.CALL("println");
  }
}


//---------------------------------------------------------------------------

void til::postfix_writer::do_read_node(til::read_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  _pf.CALL("readi");
  _pf.LDFVAL32();
  node->accept(this, lvl);
  _pf.STINT();
}

//---------------------------------------------------------------------------

void til::postfix_writer::do_loop_node(til::loop_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  int condLabel, endLabel;

  _pf.ALIGN();
  _pf.LABEL(mklbl(condLabel = ++_lbl));
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(endLabel = ++_lbl));

  _currentFunctionLoopLabels->push_back(std::make_pair(mklbl(condLabel), mklbl(endLabel)));
  node->block()->accept(this, lvl + 2);
  _visitedFinalInstruction = false; // reset flag
  _currentFunctionLoopLabels->pop_back();

  _pf.JMP(mklbl(condLabel));
  _pf.ALIGN();
  _pf.LABEL(mklbl(endLabel));
}

//---------------------------------------------------------------------------

void til::postfix_writer::do_if_node(til::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _visitedFinalInstruction = false; // reset flag
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl1));

}

//---------------------------------------------------------------------------

void til::postfix_writer::do_if_else_node(til::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1, lbl2;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  _visitedFinalInstruction = false;  // reset flag
  _pf.JMP(mklbl(lbl2 = ++_lbl));
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl1));
  node->elseblock()->accept(this, lvl + 2);
  _visitedFinalInstruction = false;  // reset flag
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl1 = lbl2));

}

//---------------------------------------------------------------------------

void til::postfix_writer::do_block_node(til::block_node * const node, int lvl) {
  _symtab.push();
  node->declarations()->accept(this, lvl + 2);

  _visitedFinalInstruction = false;
  for (size_t i = 0; i < node->instructions()->size(); i++) {
    auto child = node->instructions()->node(i);

    if (_visitedFinalInstruction) {
      std::cerr << child->lineno() << ": " << "unreachable code!" << std::endl;
    }

    child->accept(this, lvl + 2);
  }
  _visitedFinalInstruction = false;

  _symtab.pop();
}

// ---------------------------------------------------------------------------

template<size_t P, typename T>
void til::postfix_writer::executeLoopControlInstruction(T *const node) {
  ASSERT_SAFE_EXPRESSIONS;

  size_t level = static_cast<size_t>(node->level());

  if (level == 0) {
    std::cerr << node->lineno() << ": invalid loop control instruction level" << std::endl;
    return;
  }

  if (_currentFunctionLoopLabels->size() < level) {
    std::cerr << node->lineno() << ": loop control instruction not within sufficient loops (expected at most "
              << _currentFunctionLoopLabels->size() << ")" << std::endl;
    return;
  }

  size_t index = _currentFunctionLoopLabels->size() - level;
  auto label = std::get<P>(_currentFunctionLoopLabels->at(index));
  _pf.JMP(label);

  _visitedFinalInstruction = true;
}



void til::postfix_writer::do_stop_node(til::stop_node * const node, int lvl) {
  executeLoopControlInstruction<1>(node);
}

void til::postfix_writer::do_next_node(til::next_node * const node, int lvl) {
  executeLoopControlInstruction<0>(node);
}

void til::postfix_writer::do_return_node(til::return_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  auto symbol = _symtab.find("@", 1);
  auto rettype = cdk::functional_type::cast(symbol->type())->output(0);
  auto rettype_name = rettype->name();

  if (rettype_name != cdk::TYPE_VOID) {
    acceptCovariantNode(rettype, node->rvalue(), lvl + 2);

    if (rettype_name == cdk::TYPE_DOUBLE) {
      _pf.STFVAL64();
    } else {
      _pf.STFVAL32();
    }
  }

  _pf.JMP(_currentFunctionReturnLabel);

  _visitedFinalInstruction = true;
}

void til::postfix_writer::do_address_node(til::address_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  node->lvalue()->accept(this, lvl + 2);
}

void til::postfix_writer::do_pointer_index_node(til::pointer_index_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  node->base()->accept(this, lvl + 2);
  node->index()->accept(this, lvl + 2);
  _pf.INT(node->type()->size());
  _pf.MUL();
  _pf.ADD();
}

void til::postfix_writer::do_function_node(til::function_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  std::string functionLabel;
  if (node->is_main()) {
    functionLabel = "_main";
  } else {
    functionLabel = mklbl(++_lbl);
  }
  _functionLabels.push(functionLabel); // Push the function label onto the stack

  _pf.TEXT(_functionLabels.top());
  _pf.ALIGN();
  if (node->is_main()) {
    _pf.GLOBAL("_main", _pf.FUNC());
  }
  _pf.LABEL(_functionLabels.top());

  auto oldOffset = _offset;
  _offset = 8; // function arguments start at offset 8
  _symtab.push(); // Push a new scope for the symbol table

  _inFunctionArguments = true;
  node->arguments()->accept(this, lvl);
  _inFunctionArguments = false;

  // compute local variables size
  frame_size_calculator fsc(_compiler, _symtab);
  node->block()->accept(&fsc, lvl);
  _pf.ENTER(fsc.localsize()); // Enter the function with the size of local variables

  auto oldFunctionRetLabel = _currentFunctionReturnLabel;
  _currentFunctionReturnLabel = mklbl(++_lbl);

  auto oldFunctionLoopLabels = _currentFunctionLoopLabels;
  _currentFunctionLoopLabels = new std::vector<std::pair<std::string, std::string>>();

  _offset = 0; // Reset offset for local variables

  node->block()->accept(this, lvl);

  if (node->is_main()) {
    // Main has no return statement, ensure it returns 0
    _pf.INT(0);
    _pf.STFVAL32();
  }

  _pf.ALIGN();
  _pf.LABEL(_currentFunctionReturnLabel);
  _pf.LEAVE();
  _pf.RET();

  delete _currentFunctionLoopLabels;
  _currentFunctionLoopLabels = oldFunctionLoopLabels;
  _currentFunctionReturnLabel = oldFunctionRetLabel;
  _offset = oldOffset; // Restore old offset
  _symtab.pop(); // Pop the symbol table scope
  _functionLabels.pop();

  if (node->is_main()) {
    for (auto name : _externalFunctionsToDeclare) {
      _pf.EXTERN(name);
    }
    return;
  }

  if (!_functionLabels.empty() && !_forceOutsideFunction){
    _pf.TEXT(_functionLabels.top());
    _pf.ADDR(functionLabel);
  } else {
    _pf.DATA(); // Switch to data section if outside function
    _pf.SADDR(functionLabel);
  }
}

void til::postfix_writer::do_declaration_node(til::declaration_node *const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  auto symbol = new_symbol();
  reset_new_symbol();

  int offset = 0;
  int typesize = node->type()->size();
  if (_inFunctionArguments) {
    offset = _offset;
    _offset += typesize;
  } else if (!_functionLabels.empty() && !_forceOutsideFunction) {
    _offset -= typesize;
    offset = _offset;
  } else {
    offset = 0;
  }
  symbol->offset(offset);

  if (!_functionLabels.empty() && !_forceOutsideFunction) {
    // nothing to do for function args or local variables without initializer
    if (_inFunctionArguments || node->initializer() == nullptr) {
      return;
    }

    acceptCovariantNode(node->type(), node->initializer(), lvl);
    if (node->is_typed(cdk::TYPE_DOUBLE)) {
      _pf.LOCAL(symbol->offset());
      _pf.STDOUBLE();
    } else {
      _pf.LOCAL(symbol->offset());
      _pf.STINT();
    }

    return;
  }

  if (symbol->qualifier() == tFORWARD || symbol->qualifier() == tEXTERNAL) {
    _externalFunctionsToDeclare.insert(symbol->name());
    return;
  }

  _externalFunctionsToDeclare.erase(symbol->name());

  if (node->initializer() == nullptr) {
    _pf.BSS();
    _pf.ALIGN();

    if (symbol->qualifier() == tPUBLIC) {
      _pf.GLOBAL(symbol->name(), _pf.OBJ());
    }

    _pf.LABEL(symbol->name());
    _pf.SALLOC(typesize);
    return;
  }

  if (!isInstanceOf<cdk::integer_node, cdk::double_node, cdk::string_node,
        til::null_node, til::function_node>(node->initializer())) {
    std::cerr << node->lineno() << ": non-literal initializer for global variable '" << symbol->name() << "'" << std::endl;
  }

  _pf.DATA();
  _pf.ALIGN();

  if (symbol->qualifier() == tPUBLIC) {
    _pf.GLOBAL(symbol->name(), _pf.OBJ());
  }

  _pf.LABEL(symbol->name());

  if (node->is_typed(cdk::TYPE_DOUBLE) && node->initializer()->is_typed(cdk::TYPE_INT)) {
    auto int_node = dynamic_cast<cdk::integer_node*>(node->initializer());
    _pf.SDOUBLE(int_node->value());
  } else {
    node->initializer()->accept(this, lvl);
  }
}

void til::postfix_writer::do_sizeof_node(til::sizeof_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  _pf.INT(node->argument()->type()->size());
}

void til::postfix_writer::do_alloc_node(til::alloc_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  auto ref = cdk::reference_type::cast(node->type())->referenced();
  node->argument()->accept(this, lvl);
  _pf.INT(std::max(static_cast<size_t>(1), ref->size()));
  _pf.MUL();
  _pf.ALLOC();
  _pf.SP();
}

void til::postfix_writer::do_function_call_node(til::function_call_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  std::shared_ptr<cdk::functional_type> func_type;

  // Determine the function type (recursive call if function is nullptr)
  if (node->function() == nullptr) {
    auto symbol = _symtab.find("@", 1);
    func_type = cdk::functional_type::cast(symbol->type());
  } else {
    func_type = cdk::functional_type::cast(node->function()->type());
  }

  int args_size = 0;

  // Visit arguments in reverse order
  for (size_t i = node->arguments()->size(); i > 0; --i) {
    auto arg = dynamic_cast<cdk::expression_node*>(node->arguments()->node(i - 1));
    args_size += arg->type()->size();
    acceptCovariantNode(func_type->input(i - 1), arg, lvl + 2);
  }

  _externalFunctionName = std::nullopt;

  // Handle function call (recursive call if function is nullptr)
  if (node->function() == nullptr) {
    _pf.ADDR(_functionLabels.top());
  } else {
    node->function()->accept(this, lvl);
  }

  // Generate function call or branch
  if (_externalFunctionName) {
    _pf.CALL(*_externalFunctionName);
    _externalFunctionName = std::nullopt;
  } else {
    _pf.BRANCH();
  }

  // Clean up the stack if there are arguments
  if (args_size > 0) {
    _pf.TRASH(args_size);
  }

  // Load the function return value
  if (node->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.LDFVAL64();
  } else if (!node->is_typed(cdk::TYPE_VOID)) {
    _pf.LDFVAL32();
  }
}


void til::postfix_writer::do_null_node(til::null_node * const node, int lvl) {
  if (!_functionLabels.empty() && !_forceOutsideFunction) {
    _pf.INT(0);
  } else {
    _pf.SINT(0);
  }
}

void til::postfix_writer::do_process_node(til::process_node * const node, int lvl) {

   ASSERT_SAFE_EXPRESSIONS;

   int condLabel, endLabel, index;
   condLabel = node->low();
   endLabel = node->high();
   til::variable_node* aux_index = new til::variable_node(node->lineno(), condLabel);

    _pf.ALIGN();
    _pf.LABEL(mklbl(condLabel = ++_lbl));
    node->condition()->accept(this, lvl);
    _pf.JZ(mklbl(endLabel = ++_lbl));

    _currentFunctionLoopLabels->push_back(std::make_pair(mklbl(condLabel), mklbl(endLabel)));

    std::string function_name = node->function->name();
    std::vector<cdk::expression_node*> vector = node->vector();

    vector.push_back(aux_index);

    til::function_call_node* function_call = new til::function_call_node(node->lineno(), node->function, new cdk::sequence_node(node->lineno(), vector));
    function_call->accept(this, lvl);

    node->block()->accept(this, lvl + 2);
    _visitedFinalInstruction = false; // reset flag
    _currentFunctionLoopLabels->pop_back();

    _pf.INC(aux_index->value());

    _pf.JMP(mklbl(condLabel));
    _pf.ALIGN();
    _pf.LABEL(mklbl(endLabel));


}