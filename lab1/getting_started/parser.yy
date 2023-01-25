%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
}
%code{
  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;
  extern int yylineno;
  
}
// definition of set of tokens. All tokens are of type string
%token <std::string> PLUSOP MINUSOP MULTOP DIVOP INT LP RP LHB RHB LCB RCB ASSIGN EQ AND OR GT LT
%token <std::string> CLASS STATIC VOID MAIN PUBLIC COMMENT
%token <std::string> PERIOD COMMA EXCLAMATION SEMICOLON INTTYPE BOOLTYPE STRING
%token <std::string> IF ELSE WHILE NEW LENGTH PRINT IDENTIFIER
%token END 0 "end of file"

//defition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl
%left PLUSOP MINUSOP
%left MULTOP DIVOP

// definition of the production rules. All production rules are of type Node
%type <Node *> root expression factor

%%
root:       expression {root = $1;};

expression: 
  expression PLUSOP expression {      
    /*
    Create a subtree that corresponds to the AddExpression
    The root of the subtree is AddExpression
    The childs of the AddExpression subtree are the left hand side (
    expression accessed through $1) and right hand side of the expression (expression accessed through $3)
    */
    $$ = new Node("AddExpression", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    /* printf("r1 "); */
  }

  | expression MINUSOP expression {
      $$ = new Node("SubExpression", "", yylineno);
      $$->children.push_back($1);
      $$->children.push_back($3);
      /* printf("r2 "); */
    }

  | expression MULTOP expression {
      $$ = new Node("MultExpression", "", yylineno);
      $$->children.push_back($1);
      $$->children.push_back($3);
      /* printf("r3 "); */
    }

  | expression DIVOP expression {
      $$ = new Node("DIVExpression", "", yylineno);
      $$->children.push_back($1);
      $$->children.push_back($3);

    }

  | factor {
      $$ = $1; 
      /* printf("r4 ");*/
    }
  ;

factor:     
  INT {
    // Here we create a leaf node Int. The value of the leaf node is $1
    $$ = new Node("Int", $1, yylineno); 
    /* printf("r5 ");*/
  }
  // simply return the expression
  | LP expression RP {
      $$ = $2; 
      /* printf("r6 "); */}
  ;
