#ifndef __TIL_AST_PROCESS_NODE_H__
#define __TIL_AST_PROCESS_NODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/basic_node.h>
#include <cdk/ast/integer_node.h>

namespace til {
    /**
        * Class for describing process nodes.
        */

    class process_node: public cdk::expression_node {
        cdk::expression_node *_low;
        cdk::expression_node *_high;
        cdk::expression_node *_pointer;
        cdk::expression_node *_function;
    }

    public:
        inline process_node(int lineno, cdk::expression_node *low, cdk::expression_node *high, cdk::expression_node *pointer,
         cdk::expression_node *function_call) :
            cdk::expression_node(lineno), _low(low), _high(high), _pointer(pointer), _function(function) {
        }

    public:
        inline cdk::expression_node *low() {
            return _low;
        }

        inline cdk::expression_node *high() {
            return _high;
        }

        inline cdk::expression_node *pointer() {
            return _pointer;
        }

        inline cdk::expression_node *function() {
            return _function;
        }

        void accept(basic_ast_visitor *sp, int level) {
            sp->do_process_node(this, level);
        }
    };
} //til

#endif