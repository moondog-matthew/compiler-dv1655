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
%token <std::string> CLASS STATIC VOID MAIN PUBLIC RETURN
%token <std::string> PERIOD COMMA EXCLAMATION SEMICOLON INTTYPE BOOLTYPE STRING
%token <std::string> IF ELSE WHILE NEW LENGTH PRINT IDENTIFIER TRUE FALSE THIS
%token END 0 "end of file"

//defition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl
%right ASSIGN

%left AND OR 
%left EQ  
%left LT GT
%left PLUSOP MINUSOP
%left MULTOP DIVOP 
%left LHB
%left EXCLAMATION
%left PERIOD


%nonassoc NO_ELSE
%nonassoc ELSE

// definition of the production rules. All production rules are of type Node
%type <Node *> root expression factor identifier type statement statements
%type <Node *> exprlist experiment stmt_if vardeclaration vardeclarations mainclass goal
%type <Node *> methoddeclaration methoddeclarations methodbody parameters classdeclaration classdeclarations

%%
// Change this later to be the class 
root:         goal {root = $1;};

goal:
              mainclass classdeclarations END {
                      $$ = new GoalNode("Goal", "", yylineno);
                      $$->children.push_back($1); // mainclass
                      $$->children.push_back($2); // classdeclarations
              }
              | mainclass END {
                      $$ = new GoalNode("Goal", "", yylineno);
                      $$->children.push_back($1); // mainclass 
              }
              ;

mainclass: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRING LHB RHB identifier RP LCB statement RCB RCB {
                      $$ = new MainClassDeclaration("MainClass", "", yylineno);
                      $$->children.push_back($3); // identifier
                      $$->children.push_back($13);  // identifier
                      $$->children.push_back($16);  // statement
              }
              ;

classdeclaration: CLASS identifier LCB vardeclarations methoddeclarations RCB {
                      $$ = new ClassDeclaration("classDeclaration", "", yylineno);
                      $$->children.push_back($2); // identifier
                      $$->children.push_back($4); // vardeclarations
                      $$->children.push_back($5); // methoddeclarations
              }
              | CLASS identifier LCB methoddeclarations RCB {
                      $$ = new ClassDeclaration("classDeclaration", "", yylineno);
                      $$->children.push_back($2); // identifier
                      $$->children.push_back($4); // methoddeclarations
              }
              | CLASS identifier LCB vardeclarations RCB {
                      $$ = new ClassDeclaration("classDeclaration", "", yylineno);
                      $$->children.push_back($2); // identifier
                      $$->children.push_back($4); // vardeclarations
              }
              | CLASS identifier LCB RCB {
                      $$ = new ClassDeclaration("classDeclaration", "", yylineno);
                      $$->children.push_back($2); // identifier
              }
              ;

classdeclarations:
            classdeclaration {$$=$1;}
            | classdeclarations classdeclaration {
                      $$ = new ClassDeclarationMult("ClassDeclarations", "", yylineno);
                      $$->children.push_back($1); // recursion
                      $$->children.push_back($2); // class declaration
            }
            ;

methoddeclaration: PUBLIC type identifier LP parameters RP LCB methodbody RETURN expression SEMICOLON RCB {
                      $$ = new Method("Method", "", yylineno);
                      $$->children.push_back($2); // type
                      $$->children.push_back($3); // identifier
                      $$->children.push_back($5); // param
                      $$->children.push_back($8); // method body
                      $$->children.push_back($10); // return expression
              }
              | PUBLIC type identifier LP RP LCB methodbody RETURN expression SEMICOLON RCB {
                      $$ = new Method("Method", "", yylineno);
                      $$->children.push_back($2); // type
                      $$->children.push_back($3); // identifier
                      $$->children.push_back($7); // method body
                      $$->children.push_back($9); // return expression
              }
              | PUBLIC type identifier LP parameters RP LCB RETURN expression SEMICOLON RCB {
                      $$ = new Method("Method", "", yylineno);
                      $$->children.push_back($2); // type
                      $$->children.push_back($3); // identifier
                      $$->children.push_back($5); // param
                      $$->children.push_back($9); // return expression
              }
              | PUBLIC type identifier LP RP LCB RETURN expression SEMICOLON RCB {
                      $$ = new Method("Method", "", yylineno);
                      $$->children.push_back($2); // type
                      $$->children.push_back($3); // identifier
                      $$->children.push_back($8); // return expression
              };

methoddeclarations:
            methoddeclaration {$$ = $1;}
            | methoddeclarations methoddeclaration {
                      $$ = new MethodDeclarations("MethodDeclarations", "", yylineno);
                      $$->children.push_back($1);
                      $$->children.push_back($2);
            }
            ;

methodbody: 
            vardeclaration {$$ = $1;}
            | statement {$$ = $1;}
            | methodbody vardeclaration {
                      $$ = new MethodBody("Method body", "", yylineno);
                      $$->children.push_back($1); // methodbody
                      $$->children.push_back($2); // variable
            }
            | methodbody statement {
                      $$ = new MethodBody("Method body", "", yylineno);
                      $$->children.push_back($1); // method body
                      $$->children.push_back($2); // statement
            }
            ;

vardeclaration: type identifier SEMICOLON {
                      $$ = new Variable("Variable", "", yylineno);
                      $$->children.push_back($1); // type
                      $$->children.push_back($2); // identifier
              }

vardeclarations: 
            vardeclaration {$$ = $1;}
            | vardeclarations vardeclaration {
                      $$ = new VariableList("Variables", "", yylineno);
                      $$->children.push_back($1); // recursion
                      $$->children.push_back($2); // variable
            }
            ;

parameters: 
            type identifier {
                      $$ = new Parameter("Parameter", "", yylineno);
                      $$->children.push_back($1); // type
                      $$->children.push_back($2); // identifier
            }
            | type identifier COMMA parameters {
                      $$ = new ParameterList("Parameters", "", yylineno);
                      $$->children.push_back($1); // type
                      $$->children.push_back($2); // identifier
                      $$->children.push_back($4); // undef nr of prams
            }
            ;

type: INTTYPE LHB RHB {
            $$ = new ArrayType("int[]", "", yylineno);
              }
      | BOOLTYPE {
            $$ =  new BoolType("bool", "", yylineno);
              }
      | INTTYPE {
            $$ = new IntType("int", "", yylineno);
              }
      | identifier {
            $$ = new IdenType("IdentifierType", "", yylineno);
              }
        ;

statement:  LCB RCB  { 
              $$ = new NonStmt("NonStatements", "", yylineno);
            }
            | LCB statements RCB  { 
              $$ = $2;
            }
            | stmt_if
            | WHILE LP expression RP statement {
              $$ = new WhileStmt("While", "", yylineno);
              $$->children.push_back($3); // expression
              $$->children.push_back($5); // statement
            }
            | PRINT LP expression RP SEMICOLON {
              $$ = new PrintStmt("Print", "", yylineno);
              $$->children.push_back($3); // expresssion
            }
            | identifier ASSIGN expression SEMICOLON {
              $$ = new AssignStmt("Assign", "", yylineno);
              $$->children.push_back($1); // identifier
              $$->children.push_back($3); // expression
            } 
            | identifier LHB expression RHB ASSIGN expression SEMICOLON {
              $$ = new ArrayIndexAssign("indexAssign", "", yylineno);
              $$->children.push_back($1); // identifier
              $$->children.push_back($3); // expression
              $$->children.push_back($6); // expression
            }
            ;

statements:
            statement {
                  $$ = $1;
                }
            | statements statement { 
              $$ = new Statements("Statements", "", yylineno);
              $$->children.push_back($1); // recursion
              $$->children.push_back($2); // statement
                }
            ;

stmt_if: IF LP expression RP statement %prec NO_ELSE { // To solve dangling else ambiguity
              $$ = new IfStmt("IF", "", yylineno);
              $$->children.push_back($3); // expression
              $$->children.push_back($5); // statement
            }
            | IF LP expression RP statement ELSE statement {
              $$ = new IfElseStmt("IfElse", "", yylineno);
              $$->children.push_back($3); // expression
              $$->children.push_back($5); // statement
              $$->children.push_back($7); // statement
            };


expression: expression PLUSOP expression {      
                            $$ = new PlusOP("AddExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression MINUSOP expression {
                            $$ = new MinusOP("SubExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression MULTOP expression {
                            $$ = new MultOP("MultExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression DIVOP expression {
                            $$ = new DivOP("DivExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression ASSIGN expression {
                            $$ = new AssignExpr("Assign", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);                            
                          }
            | expression GT expression {
                            $$ = new GreaterThan("GreaterThan", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);                            
                          }
            | expression LT expression {
                            $$ = new LessThan("LessThan", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);                            
                          }
            | expression EQ expression {
                            $$ = new Equals("Equals", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);                            
                          }
            | expression OR expression {
                            $$ = new Or("OR", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);                            
                          }
            | expression AND expression {
                            $$ = new And("AND", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);                            
                          }
            
            | experiment
                
            | expression PERIOD LENGTH {
                            $$ = new LengthOf("LenghtOfExpression", "", yylineno);
                            $$->children.push_back($1);
                            // printf("LEN: %d\n", yylineno);
                          }
            | expression PERIOD identifier LP exprlist RP {  // recursive grammar, follows recursive rules
                              $$ = new MethCall("Method call", "", yylineno);
                              $$->children.push_back($1); // expression
                              $$->children.push_back($3); // identifier
                              $$->children.push_back($5); // expression list
                          }
            | expression PERIOD identifier LP RP {  // for the empty case
                              $$ = new MethCall("Method call", "", yylineno);
                              $$->children.push_back($1); // expression
                              $$->children.push_back($3); // identifier
                          }
            | TRUE {
                  $$ = new TrueVal("True", "", yylineno);
                }
            | FALSE {
                  $$ = new FalseVal("False", "", yylineno);
                }
            | identifier {
                  $$ = $1;
                }
            | THIS  {
                  $$ = new ThisOP("this", "", yylineno);
                }
            | NEW INTTYPE LHB expression RHB {
                      $$ = new IntArray("int[]", "", yylineno);
                      $$->children.push_back($4);  // Size of int array
                  }
            | NEW identifier LP RP {
                      $$ = new IdenAlloc("new ID()", "", yylineno);
                      $$->children.push_back($2);  
                      // printf("NEW ident: %d\n", yylineno);
                  }
            | EXCLAMATION expression {
                      $$ = new Negation("Negation", "", yylineno); // expression
                      $$->children.push_back($2); 
                  }
            | factor      {$$ = $1; /* printf("r4 ");*/}
            ;

experiment: expression LHB expression RHB { //??
                      $$ = new Index("index", "", yylineno);
                      $$->children.push_back($1);  // what to take index of
                      $$->children.push_back($3);  // index value
                  }
                  ;

exprlist: expression {
                      $$ = new Expression("(Expression)", "", yylineno);
                      $$->children.push_back($1);
                  }
            | exprlist COMMA expression {
                      $$ = new ExpressionList("ExpressionList", "", yylineno);
                      $$->children.push_back($1);
                      $$->children.push_back($3);
                  }
                  ;

factor: INT {
                      $$ = new IntVal("int", $1, yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
            | LP expression RP { 
                      $$ = $2; /* printf("r6 ");  simply return the expression */
                  }
                  ;

identifier: IDENTIFIER {
                    $$ = new Identifier("Identifier", $1, yylineno); 
            }
            ;
