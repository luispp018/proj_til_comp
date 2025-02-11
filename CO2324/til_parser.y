%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!
%}

%parse-param {std::shared_ptr<cdk::compiler> compiler}

%union {
  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;          /* integer value */
  double                d;          /* double value */
  std::string          *s;          /* symbol name or string literal */
  cdk::basic_node      *node;       /* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  til::block_node      *block;
  std::vector<std::shared_ptr<cdk::basic_type>> *type_vector;
};

%token <i> tINTEGER
%token <d> tDOUBLE
%token <s> tIDENTIFIER tSTRING
%token tTYPE_INT tTYPE_DOUBLE tTYPE_STRING tTYPE_VOID
%token tEXTERNAL tFORWARD tPUBLIC tPRIVATE tVAR
%token tBLOCK tLOOP tSTOP tNEXT tRETURN
%token tIF
%token tREAD tNULL tSET tINDEX tOBJECTS tSIZEOF tFUNCTION
%token tPROGRAM
%token tPRINT tPRINTLN
%token tAND tOR
%token tPROCESS


%token '~'
%token tGE tLE tEQ tNE '>' '<'
%token '+' '-'
%token '*' '/' '%'
%token tUNARY
%token '(' ')'

%type <sequence> fdecls exprs insts decls function_args
%type <node> program fdecl inst decl function_arg
%type <type> type referable_type function_return_type function_type ref_type ref_type_void
%type <type_vector> types
%type <block> decls_insts block
%type <expression> expr function_def
%type <lvalue> lval

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file    : fdecls program  { compiler ->ast(new cdk::sequence_node(LINE, $2, $1)); }
        | fdecls          { compiler ->ast($1); }
        |        program  { compiler ->ast(new cdk::sequence_node(LINE, $1)); }
        |                 { compiler ->ast(new cdk::sequence_node(LINE)); }
        ;

fdecls  : fdecls fdecl    { $$ = new cdk::sequence_node(LINE, $2, $1); }
        |        fdecl    { $$ = new cdk::sequence_node(LINE, $1); }
        ;

fdecl   : '(' tEXTERNAL type tIDENTIFIER ')'                 { $$ = new til::declaration_node(LINE, tEXTERNAL, $3, *$4, nullptr); delete $4; }
        | '(' tFORWARD type tIDENTIFIER  ')'                 { $$ = new til::declaration_node(LINE, tEXTERNAL, $3, *$4, nullptr); delete $4; }
        | '(' tPUBLIC type tIDENTIFIER   ')'                 { $$ = new til::declaration_node(LINE, tPUBLIC, $3, *$4, nullptr); delete $4; }
        | '(' tPUBLIC type tIDENTIFIER expr ')'              { $$ = new til::declaration_node(LINE, tPUBLIC, $3, *$4, $5); delete $4; }
        | '(' tPUBLIC tVAR tIDENTIFIER expr ')'              { $$ = new til::declaration_node(LINE, tPUBLIC, nullptr, *$4, $5); delete $4; }
        | '(' tPUBLIC      tIDENTIFIER expr ')'              { $$ = new til::declaration_node(LINE, tPUBLIC, nullptr, *$3, $4); delete $3; }
        |             decl                                   { $$ = $1; }
        ;

type    : referable_type        { $$ = $1; }
        | ref_type_void         { $$ = $1; }
        ;

referable_type   : tTYPE_INT            { $$ = cdk::primitive_type::create(4, cdk::TYPE_INT); }
                 | tTYPE_DOUBLE         { $$ = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE); }
                 | tTYPE_STRING         { $$ = cdk::primitive_type::create(4, cdk::TYPE_STRING); }
                 | function_type        { $$ = $1; }
                 | ref_type             { $$ = $1; }
                 ;

function_type : '(' function_return_type  ')'                 { $$ = cdk::functional_type::create($2); }
              | '(' function_return_type '(' types ')' ')'    { $$ = cdk::functional_type::create(*$4, $2); delete $4; }
              ;

function_return_type : type                { $$ = $1; }
                     | tTYPE_VOID          { $$ = cdk::primitive_type::create(0, cdk::TYPE_VOID); }
                     ;

types      : types type                 { $$ = $1; $$->push_back($2); }
           | type                       { $$ = new std::vector<std::shared_ptr<cdk::basic_type>>(1, $1); }
           ;

ref_type   : referable_type '!'         { $$ = cdk::reference_type::create(4, $1); }
           ;


ref_type_void : ref_type_void '!'       { $$ = $1; }
              | tTYPE_VOID '!'          { $$ = cdk::reference_type::create(4, cdk::primitive_type::create(0, cdk::TYPE_VOID));}
              ;

program    : '(' tPROGRAM decls_insts ')'       { $$ = new til::function_node(LINE, $3); }
           ;

decls_insts :  decls insts              { $$ = new til::block_node(LINE, $1, $2); }
            |  decls                    { $$ = new til::block_node(LINE, $1, new cdk::sequence_node(LINE)); }
            |        insts              { $$ = new til::block_node(LINE, new cdk::sequence_node(LINE), $1); }
            |                           { $$ = new til::block_node(LINE, new cdk::sequence_node(LINE), new cdk::sequence_node(LINE)); }
            ;

decls     : decls decl                 { $$ = new cdk::sequence_node(LINE, $2, $1); }
          |       decl                 { $$ = new cdk::sequence_node(LINE, $1); }
          ;

decl      : '(' type tIDENTIFIER ')'             { $$ = new til::declaration_node(LINE, tPRIVATE, $2, *$3, nullptr); delete $3; }
          | '(' type tIDENTIFIER expr ')'        { $$ = new til::declaration_node(LINE, tPRIVATE, $2, *$3, $4); delete $3; }
          | '(' tVAR tIDENTIFIER expr ')'        { $$ = new til::declaration_node(LINE, tPRIVATE, nullptr, *$3, $4); delete $3; }
          ;

insts     : insts inst                 { $$ = new cdk::sequence_node(LINE, $2, $1); }
          |       inst                 { $$ = new cdk::sequence_node(LINE, $1); }
          ;

inst      : expr                                        { $$ = new til::evaluation_node(LINE, $1); }
          | '(' tPRINT exprs ')'                        { $$ = new til::print_node(LINE, $3, false); }
          | '(' tPRINTLN exprs ')'                      { $$ = new til::print_node(LINE, $3, true); }
          | '(' tSTOP tINTEGER ')'                      { $$ = new til::stop_node(LINE, $3); }
          | '(' tSTOP ')'                               { $$ = new til::stop_node(LINE, 1); }
          | '(' tNEXT tINTEGER ')'                      { $$ = new til::next_node(LINE, $3); }
          | '(' tNEXT ')'                               { $$ = new til::next_node(LINE, 1); }
          | '(' tRETURN expr ')'                        { $$ = new til::return_node(LINE, $3); }
          | '(' tRETURN ')'                             { $$ = new til::return_node(LINE, nullptr); }
          | '(' tIF expr inst ')'                       { $$ = new til::if_node(LINE, $3, $4); }
          | '(' tIF expr inst inst ')'                  { $$ = new til::if_else_node(LINE, $3, $4, $5); }
          | '(' tLOOP expr inst ')'                     { $$ = new til::loop_node(LINE, $3, $4); }
          | block                                       { $$ = $1; }
          ;


block     : '(' tBLOCK decls_insts ')'                  { $$ = $3; }
          ;

exprs     : exprs expr                 { $$ = new cdk::sequence_node(LINE, $2, $1); }
          |       expr                 { $$ = new cdk::sequence_node(LINE, $1); }
          ;

expr      :  tINTEGER                           { $$ = new cdk::integer_node(LINE, $1); }
          |  tDOUBLE                            { $$ = new cdk::double_node(LINE, $1);  }
          |  tSTRING                            { $$ = new cdk::string_node(LINE, *$1); delete $1; }
          |  tNULL                              { $$ = new til::null_node(LINE); }
          |  '(' tREAD ')'                      { $$ = new til::read_node(LINE); }
          | '(' '-' expr ')'                    { $$ = new cdk::unary_minus_node(LINE, $3); }
          | '(' '+' expr ')'                    { $$ = new cdk::unary_plus_node(LINE, $3); }
          | '(' '~' expr ')'                    { $$ = new cdk::not_node(LINE, $3); }
          | '(' '+' expr expr ')'               { $$ = new cdk::add_node(LINE, $3, $4); }
          | '(' '-' expr expr ')'               { $$ = new cdk::sub_node(LINE, $3, $4); }
          | '(' '*' expr expr ')'               { $$ = new cdk::mul_node(LINE, $3, $4); }
          | '(' '/' expr expr ')'               { $$ = new cdk::div_node(LINE, $3, $4); }
          | '(' '%' expr expr ')'               { $$ = new cdk::mod_node(LINE, $3, $4); }
          | '(' '<' expr expr ')'               { $$ = new cdk::lt_node(LINE, $3, $4); }
          | '(' '>' expr expr ')'               { $$ = new cdk::gt_node(LINE, $3, $4); }
          | '(' tGE expr expr ')'               { $$ = new cdk::ge_node(LINE, $3, $4); }
          | '(' tLE expr expr ')'               { $$ = new cdk::le_node(LINE, $3, $4); }
          | '(' tNE expr expr ')'               { $$ = new cdk::ne_node(LINE, $3, $4); }
          | '(' tEQ expr expr ')'               { $$ = new cdk::eq_node(LINE, $3, $4); }
          | '(' tAND expr expr ')'              { $$ = new cdk::and_node(LINE, $3, $4); }
          | '(' tOR expr expr ')'               { $$ = new cdk::or_node(LINE, $3, $4); }
          | '(' tOBJECTS expr ')'               { $$ = new til::alloc_node(LINE, $3); }
          | '(' tSIZEOF expr ')'                { $$ = new til::sizeof_node(LINE, $3); }
          |  lval                               { $$ = new cdk::rvalue_node(LINE, $1); }
          | '(' tSET lval expr ')'              { $$ = new cdk::assignment_node(LINE, $3, $4); }
          | '(' '?' lval ')'                    { $$ = new til::address_node(LINE, $3); }
          | '(' '@' exprs ')'                   { $$ = new til::function_call_node(LINE, nullptr, $3); }
          | '(' '@'  ')'                        { $$ = new til::function_call_node(LINE, nullptr, new cdk::sequence_node(LINE)); }
          | '(' expr exprs ')'                  { $$ = new til::function_call_node(LINE, $2, $3); }
          | '(' expr ')'                        { $$ = new til::function_call_node(LINE, $2, new cdk::sequence_node(LINE)); }
          | '(' tPROCESS expr expr expr expr ')'  { $$ = new til::process_node(LINE, $3, $4, $5, $6); }
          | function_def                        { $$ = $1; }
          ;

lval   : tIDENTIFIER                { $$ = new cdk::variable_node(LINE, $1); }
       | '(' tINDEX expr expr ')'   { $$ = new til::pointer_index_node(LINE, $3, $4); }
       ;


function_def  : '(' tFUNCTION '(' function_return_type                ')' decls_insts ')'       { $$ = new til::function_node(LINE, new cdk::sequence_node(LINE), $4, $6); }
              | '(' tFUNCTION '(' function_return_type function_args  ')' decls_insts ')'       { $$ = new til::function_node(LINE, $5, $4, $7); }
              ;

function_args : function_args function_arg        { $$ = new cdk::sequence_node(LINE, $2, $1); }
              | function_arg                      { $$ = new cdk::sequence_node(LINE, $1); }
              ;

function_arg  : '(' type tIDENTIFIER ')'          { $$ = new til::declaration_node(LINE, tPRIVATE, $2, *$3, nullptr); delete $3; }
              ;

%%
