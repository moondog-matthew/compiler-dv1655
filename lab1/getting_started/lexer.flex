%top{
#include "parser.tab.h"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h"
int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 
%%

"class"                     { return yy::parser::make_CLASS(yytext);  }
"static"                    { return yy::parser::make_STATIC(yytext); }
"void"                      { return yy::parser::make_VOID(yytext);   }
"main"                      { return yy::parser::make_MAIN(yytext);   }
"public"                    { return yy::parser::make_PUBLIC(yytext); }

"+"                         { return yy::parser::make_PLUSOP(yytext); }
"-"                         { return yy::parser::make_MINUSOP(yytext);}
"*"                         { return yy::parser::make_MULTOP(yytext); }
"/"                         { return yy::parser::make_DIVOP(yytext);  }
"("                         { return yy::parser::make_LP(yytext);     } 
")"                         { return yy::parser::make_RP(yytext);     } 
0|[1-9][0-9]*               { return yy::parser::make_INT(yytext);    }
"["                         { return yy::parser::make_LHB(yytext);    }
"]"                         { return yy::parser::make_RHB(yytext);    }
"{"                         { return yy::parser::make_LCB(yytext);    }
"}"                         { return yy::parser::make_RCB(yytext);    }
"="                         { return yy::parser::make_ASSIGN(yytext); }
"=="                        { return yy::parser::make_EQ(yytext);     }
"&&"                        { return yy::parser::make_AND(yytext);    }
"||"                        { return yy::parser::make_OR(yytext);     }
">"                         { return yy::parser::make_GT(yytext);     }
"<"                         { return yy::parser::make_LT(yytext);     }

"."                         { return yy::parser::make_PERIOD(yytext);     }
","                         { return yy::parser::make_COMMA(yytext);      }
"!"                         { return yy::parser::make_EXCLAMATION(yytext);}
";"                         { return yy::parser::make_SEMICOLON(yytext);  }

[ \t\n\r]+                  { } // Whitespaces

"int"                       { return yy::parser::make_INTTYPE(yytext);  }
"boolean"                   { return yy::parser::make_BOOLTYPE(yytext); }
"String"                    { return yy::parser::make_STRING(yytext);   }

"if"                        { return yy::parser::make_IF(yytext);   } 
"else"                      { return yy::parser::make_ELSE(yytext); }
"while"                     { return yy::parser::make_WHILE(yytext);}

"new"                       { return yy::parser::make_NEW(yytext);   }
"length"                    { return yy::parser::make_LENGTH(yytext);}
"System.out.println"        { return yy::parser::make_PRINT(yytext); }

[a-zA-Z]+[a-zA-Z0-9\-_]*    { return yy::parser::make_IDENTIFIER(yytext);}

"//".*                  { } // ignore inline comments

.                           { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); printf("Character %s is not recognized\n", yytext); lexical_errors = 1;}
<<EOF>>                     return yy::parser::make_END();
%%