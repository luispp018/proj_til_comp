#include <string>
#include "targets/xml_writer.h"
#include "targets/type_checker.h"
#include ".auto/all_nodes.h"  // automatically generated


#include "til_parser.tab.h"
static std::string qualifier_name(int qualifier) {
  switch (qualifier) {
    case tEXTERNAL: return "external";
    case tFORWARD: return "forward";
    case tPUBLIC: return "public";
    case tPRIVATE: return "private";
    default: return "[unknown qualifier]";
  };
} 

//---------------------------------------------------------------------------



void til::xml_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void til::xml_writer::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}
void til::xml_writer::do_double_node(cdk::double_node * const node, int lvl) {
  process_literal(node, lvl);
}
void til::xml_writer::do_not_node(cdk::not_node * const node, int lvl) {
    do_unary_operation(node, lvl);
}
void til::xml_writer::do_and_node(cdk::and_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void til::xml_writer::do_or_node(cdk::or_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}

//---------------------------------------------------------------------------

void til::xml_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  os() << std::string(lvl, ' ') << "<sequence_node size='" << node->size() << "'>" << std::endl;
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void til::xml_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  process_literal(node, lvl);
}

void til::xml_writer::do_string_node(cdk::string_node * const node, int lvl) {
  process_literal(node, lvl);
}

//---------------------------------------------------------------------------

void til::xml_writer::do_unary_operation(cdk::unary_operation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void til::xml_writer::do_unary_minus_node(cdk::unary_minus_node * const node, int lvl) {
  do_unary_operation(node, lvl);
}

void til::xml_writer::do_unary_plus_node(cdk::unary_plus_node * const node, int lvl) {
  do_unary_operation(node, lvl);
}

//---------------------------------------------------------------------------

void til::xml_writer::do_binary_operation(cdk::binary_operation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void til::xml_writer::do_add_node(cdk::add_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void til::xml_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void til::xml_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void til::xml_writer::do_div_node(cdk::div_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void til::xml_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void til::xml_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void til::xml_writer::do_le_node(cdk::le_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void til::xml_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void til::xml_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void til::xml_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void til::xml_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}

//---------------------------------------------------------------------------

void til::xml_writer::do_variable_node(cdk::variable_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->name() << "</" << node->label() << ">" << std::endl;
}

void til::xml_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

void til::xml_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

  node->lvalue()->accept(this, lvl);
  reset_new_symbol();

  node->rvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void til::xml_writer::do_evaluation_node(til::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void til::xml_writer::do_print_node(til::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  if (node->arguments() != nullptr) {
    node->arguments()->accept(this, lvl + 2);
  }
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void til::xml_writer::do_read_node(til::read_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  if (node != nullptr) {
    node->accept(this, lvl + 2);
  }
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void til::xml_writer::do_loop_node(til::loop_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void til::xml_writer::do_if_node(til::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  closeTag(node, lvl);
}

void til::xml_writer::do_if_else_node(til::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->thenblock()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  openTag("else", lvl + 2);
  node->elseblock()->accept(this, lvl + 4);
  closeTag("else", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void til::xml_writer::do_block_node(til::block_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  _symtab.push();
  openTag("declarations", lvl + 2);
  if (node->declarations() != nullptr) {
    node->declarations()->accept(this, lvl + 4);
  }
  closeTag("declarations", lvl + 2);
  openTag("instructions", lvl + 2);
  if (node->instructions() != nullptr) {
    node->instructions()->accept(this, lvl + 4);
  }
  closeTag("instructions", lvl + 2);
  _symtab.pop();
  closeTag(node, lvl);
}

void til::xml_writer::do_stop_node(til::stop_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<" << node->label()
        << " level=\"" << node->level() << "\" />" << std::endl;
}

void til::xml_writer::do_next_node(til::next_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<" << node->label()
        << " level=\"" << node->level() << "\" />" << std::endl;
}

void til::xml_writer::do_return_node(til::return_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  if (node->rvalue() == nullptr) {
      os() << std::string(lvl, ' ') << "<" << node->label() << " />" << std::endl;
  } else {
      openTag(node, lvl);
      node->rvalue()->accept(this, lvl + 2);
      closeTag(node, lvl);
  }
}

void til::xml_writer::do_address_node(til::address_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  if (node->lvalue() != nullptr) {
    node->lvalue()->accept(this, lvl + 2);
  }
  closeTag(node, lvl);
}

void til::xml_writer::do_pointer_index_node(til::pointer_index_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("base", lvl + 2);
  if (node->base() != nullptr) {
    node->base()->accept(this, lvl + 4);
  }
  closeTag("base", lvl + 2);
  openTag("index", lvl + 2);
  if (node->index() != nullptr) {
    node->index()->accept(this, lvl + 4);
  }
  closeTag("index", lvl + 2);
  closeTag(node, lvl);
}

void til::xml_writer::do_function_node(til::function_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  os() << std::string(lvl, ' ') + "<" + node->label() + " is_main="" "
       << (node->is_main() ? "true" : "false") << " />" << std::endl;
  openTag("arguments", lvl + 2);
  if (node->arguments() != nullptr) {
    node->arguments()->accept(this, lvl + 4);
  }
  closeTag("arguments", lvl + 2);
  openTag("block", lvl + 2);
  if (node->block() != nullptr) {
    node->block()->accept(this, lvl + 4);
  }
  closeTag("block", lvl + 2);
  closeTag(node, lvl);
}

void til::xml_writer::do_declaration_node(til::declaration_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  if (node->type() != nullptr) {
     os() << std::string(lvl, ' ') << "<" << node->label() << " name='" << node->identifier() << "' qualifier='"
             << qualifier_name(node->qualifier()) << "' type='" << cdk::to_string(node->type()) << " />" << std::endl;
  }
  if (node->initializer() == nullptr) {
      os() << std::string(lvl, ' ') << "<" << "initializer" << " />" << std::endl;
    } else {
      openTag("initializer", lvl + 2);
      node->initializer()->accept(this, lvl + 4);
      closeTag("initializer", lvl + 2);
    }
    closeTag(node, lvl);
} 

void til::xml_writer::do_sizeof_node(til::sizeof_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  if (node->argument() != nullptr) {
    node->argument()->accept(this, lvl + 2);
  }
  closeTag(node, lvl);
}

void til::xml_writer::do_alloc_node(til::alloc_node * const node, int lvl) {
  do_unary_operation(node, lvl);
}

void til::xml_writer::do_function_call_node(til::function_call_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("function", lvl + 2);
  if (node->function() == nullptr) {
    os() << std::string(lvl, ' ') << "<" << "recursive" << " />" << std::endl;
  } else {
    node->function()->accept(this, lvl + 4);
  }
  closeTag("function", lvl + 2);
  openTag("arguments", lvl + 2);
  if (node->arguments() != nullptr) {
    node->arguments()->accept(this, lvl + 4);
  }
  closeTag("arguments", lvl + 2);
  closeTag(node, lvl);
}

void til::xml_writer::do_null_node(til::null_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  os() << std::string(lvl, ' ') << "<" << node->label() << " />" << std::endl;
}