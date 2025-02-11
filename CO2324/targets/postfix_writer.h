#ifndef __SIMPLE_TARGETS_POSTFIX_WRITER_H__
#define __SIMPLE_TARGETS_POSTFIX_WRITER_H__

#include "targets/basic_ast_visitor.h"

#include <sstream>
#include <cdk/emitters/basic_postfix_emitter.h>
#include <optional>
#include <stack>
#include <set>

namespace til {

  //!
  //! Traverse syntax tree and generate the corresponding assembly code.
  //!
  class postfix_writer: public basic_ast_visitor {
    bool _forceOutsideFunction = false; // Flag to force code generation outside of function scope
    bool _visitedFinalInstruction = false; // Flag to check if the last instruction was visited
    bool _inFunctionArguments = false; // Flag to check if we are currently processing function arguments
    std::stack<std::string> _functionLabels; // Stack to hold function labels for nested function definitions
    std::set<std::string> _externalFunctionsToDeclare; // Set of external functions that need to be declared
    std::optional<std::string> _externalFunctionName; // Name of the external function being declared
    std::string _currentFunctionReturnLabel; // Label for the current function's return point
    std::vector<std::pair<std::string, std::string>> *_currentFunctionLoopLabels; // Vector to hold pairs of loop start and end labels for nested loops
    cdk::symbol_table<til::symbol> &_symtab;
    cdk::basic_postfix_emitter &_pf;
    int _lbl;
    int _offset; // Offset for local variables in the current function

  public:
    postfix_writer(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<til::symbol> &symtab,
                   cdk::basic_postfix_emitter &pf) :
        basic_ast_visitor(compiler), _symtab(symtab), _pf(pf), _lbl(0) {
    }

  public:
    ~postfix_writer() {
      os().flush();
    }

  protected:
    void acceptCovariantNode(std::shared_ptr<cdk::basic_type> const node_type, cdk::expression_node * const node, int lvl);
    template<size_t P, typename T> void executeLoopControlInstruction(T * const node);

  private:
    /** Method used to generate sequential labels. */
    inline std::string mklbl(int lbl) {
      std::ostringstream oss;
      if (lbl < 0)
        oss << ".L" << -lbl;
      else
        oss << "_L" << lbl;
      return oss.str();
    }

    template<class T>
    inline bool isInstanceOf(cdk::basic_node * const node) {
      return dynamic_cast<T*>(node) != nullptr;
    }
    template<class T, class... Rest, typename std::enable_if<sizeof...(Rest) != 0, int>::type = 0>
    inline bool isInstanceOf(cdk::basic_node * const node) {
      return dynamic_cast<T*>(node) != nullptr || isInstanceOf<Rest...>(node);
    }



  public:
  // do not edit these lines
#define __IN_VISITOR_HEADER__
#include ".auto/visitor_decls.h"       // automatically generated
#undef __IN_VISITOR_HEADER__
  // do not edit these lines: end

  };

} // til

#endif
