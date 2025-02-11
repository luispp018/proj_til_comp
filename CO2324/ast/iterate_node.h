#ifndef __TIL_AST_ITERATE_NODE_H__
#define __TIL_AST_ITERATE_NODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/basic_node.h>

namespace til {

  /**
   * Class for describing next nodes.
   */

  class iterate_node: public cdk::basic_node {
    cdk::expression_node *_cond;
    cdk::expression_node *_vector;
    cdk::expression_node *_count;
    cdk::expression_node *_function;

  public:
    inline iterate_node(int lineno, cdk::expression_node *cond, cdk::expression_node *vector, cdk::expression_node *count, cdk::expression_node *function) :
        cdk::basic_node(lineno), _cond(cond), _vector(vector), _count(count), _function(function) {
        }

  public:
    inline cdk::expression_node *cond() {
      return _cond;
    }
    inline cdk::expression_node *vector() {
      return _vector;
    }
    inline cdk::expression_node *count() {
      return _count;
    }
    inline cdk::expression_node *function() {
      return _function;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_iterate_node(this, level);
    }

  };

} // til

#endif