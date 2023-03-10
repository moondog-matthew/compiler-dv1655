// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.h"


// Unqualified %code blocks.
#line 11 "parser.y"

  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;
  extern int yylineno;
  

#line 56 "parser.tab.c"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 129 "parser.tab.c"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainclass: // mainclass
      case symbol_kind::S_classdeclaration: // classdeclaration
      case symbol_kind::S_classdeclarations: // classdeclarations
      case symbol_kind::S_methoddeclaration: // methoddeclaration
      case symbol_kind::S_methoddeclarations: // methoddeclarations
      case symbol_kind::S_methodbody: // methodbody
      case symbol_kind::S_vardeclaration: // vardeclaration
      case symbol_kind::S_vardeclarations: // vardeclarations
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_stmt_if: // stmt_if
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_experiment: // experiment
      case symbol_kind::S_exprlist: // exprlist
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_identifier: // identifier
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LHB: // LHB
      case symbol_kind::S_RHB: // RHB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PERIOD: // PERIOD
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_EXCLAMATION: // EXCLAMATION
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_INTTYPE: // INTTYPE
      case symbol_kind::S_BOOLTYPE: // BOOLTYPE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainclass: // mainclass
      case symbol_kind::S_classdeclaration: // classdeclaration
      case symbol_kind::S_classdeclarations: // classdeclarations
      case symbol_kind::S_methoddeclaration: // methoddeclaration
      case symbol_kind::S_methoddeclarations: // methoddeclarations
      case symbol_kind::S_methodbody: // methodbody
      case symbol_kind::S_vardeclaration: // vardeclaration
      case symbol_kind::S_vardeclarations: // vardeclarations
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_stmt_if: // stmt_if
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_experiment: // experiment
      case symbol_kind::S_exprlist: // exprlist
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_identifier: // identifier
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LHB: // LHB
      case symbol_kind::S_RHB: // RHB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PERIOD: // PERIOD
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_EXCLAMATION: // EXCLAMATION
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_INTTYPE: // INTTYPE
      case symbol_kind::S_BOOLTYPE: // BOOLTYPE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainclass: // mainclass
      case symbol_kind::S_classdeclaration: // classdeclaration
      case symbol_kind::S_classdeclarations: // classdeclarations
      case symbol_kind::S_methoddeclaration: // methoddeclaration
      case symbol_kind::S_methoddeclarations: // methoddeclarations
      case symbol_kind::S_methodbody: // methodbody
      case symbol_kind::S_vardeclaration: // vardeclaration
      case symbol_kind::S_vardeclarations: // vardeclarations
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_stmt_if: // stmt_if
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_experiment: // experiment
      case symbol_kind::S_exprlist: // exprlist
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_identifier: // identifier
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LHB: // LHB
      case symbol_kind::S_RHB: // RHB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PERIOD: // PERIOD
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_EXCLAMATION: // EXCLAMATION
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_INTTYPE: // INTTYPE
      case symbol_kind::S_BOOLTYPE: // BOOLTYPE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainclass: // mainclass
      case symbol_kind::S_classdeclaration: // classdeclaration
      case symbol_kind::S_classdeclarations: // classdeclarations
      case symbol_kind::S_methoddeclaration: // methoddeclaration
      case symbol_kind::S_methoddeclarations: // methoddeclarations
      case symbol_kind::S_methodbody: // methodbody
      case symbol_kind::S_vardeclaration: // vardeclaration
      case symbol_kind::S_vardeclarations: // vardeclarations
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_stmt_if: // stmt_if
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_experiment: // experiment
      case symbol_kind::S_exprlist: // exprlist
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_identifier: // identifier
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LHB: // LHB
      case symbol_kind::S_RHB: // RHB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PERIOD: // PERIOD
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_EXCLAMATION: // EXCLAMATION
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_INTTYPE: // INTTYPE
      case symbol_kind::S_BOOLTYPE: // BOOLTYPE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainclass: // mainclass
      case symbol_kind::S_classdeclaration: // classdeclaration
      case symbol_kind::S_classdeclarations: // classdeclarations
      case symbol_kind::S_methoddeclaration: // methoddeclaration
      case symbol_kind::S_methoddeclarations: // methoddeclarations
      case symbol_kind::S_methodbody: // methodbody
      case symbol_kind::S_vardeclaration: // vardeclaration
      case symbol_kind::S_vardeclarations: // vardeclarations
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_stmt_if: // stmt_if
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_experiment: // experiment
      case symbol_kind::S_exprlist: // exprlist
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_identifier: // identifier
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LHB: // LHB
      case symbol_kind::S_RHB: // RHB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PERIOD: // PERIOD
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_EXCLAMATION: // EXCLAMATION
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_INTTYPE: // INTTYPE
      case symbol_kind::S_BOOLTYPE: // BOOLTYPE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: goal
#line 50 "parser.y"
                   {root = yystack_[0].value.as < Node * > ();}
#line 840 "parser.tab.c"
    break;

  case 3: // goal: mainclass classdeclarations "end of file"
#line 53 "parser.y"
                                              {
                      yylhs.value.as < Node * > () = new GoalNode("Goal", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // mainclass
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // classdeclarations
              }
#line 850 "parser.tab.c"
    break;

  case 4: // goal: mainclass "end of file"
#line 58 "parser.y"
                              {
                      yylhs.value.as < Node * > () = new GoalNode("Goal", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // mainclass 
              }
#line 859 "parser.tab.c"
    break;

  case 5: // mainclass: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRING LHB RHB identifier RP LCB statement RCB RCB
#line 63 "parser.y"
                                                                                                                     {
                      yylhs.value.as < Node * > () = new MainClassDeclaration("MainClass", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ()); // identifier
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());  // identifier
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());  // statement
              }
#line 870 "parser.tab.c"
    break;

  case 6: // classdeclaration: CLASS identifier LCB vardeclarations methoddeclarations RCB
#line 70 "parser.y"
                                                                              {
                      yylhs.value.as < Node * > () = new ClassDeclaration("classDeclaration", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); // identifier
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // vardeclarations
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // methoddeclarations
              }
#line 881 "parser.tab.c"
    break;

  case 7: // classdeclaration: CLASS identifier LCB methoddeclarations RCB
#line 76 "parser.y"
                                                            {
                      yylhs.value.as < Node * > () = new ClassDeclaration("classDeclaration", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); // identifier
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // methoddeclarations
              }
#line 891 "parser.tab.c"
    break;

  case 8: // classdeclaration: CLASS identifier LCB vardeclarations RCB
#line 81 "parser.y"
                                                         {
                      yylhs.value.as < Node * > () = new ClassDeclaration("classDeclaration", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); // identifier
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // vardeclarations
              }
#line 901 "parser.tab.c"
    break;

  case 9: // classdeclaration: CLASS identifier LCB RCB
#line 86 "parser.y"
                                         {
                      yylhs.value.as < Node * > () = new ClassDeclaration("classDeclaration", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // identifier
              }
#line 910 "parser.tab.c"
    break;

  case 10: // classdeclarations: classdeclaration
#line 92 "parser.y"
                             {yylhs.value.as < Node * > ()=yystack_[0].value.as < Node * > ();}
#line 916 "parser.tab.c"
    break;

  case 11: // classdeclarations: classdeclarations classdeclaration
#line 93 "parser.y"
                                                 {
                      yylhs.value.as < Node * > () = new ClassDeclarationMult("ClassDeclarations", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // recursion
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // class declaration
            }
#line 926 "parser.tab.c"
    break;

  case 12: // methoddeclaration: PUBLIC type identifier LP parameters RP LCB methodbody RETURN expression SEMICOLON RCB
#line 99 "parser.y"
                                                                                                          {
                      yylhs.value.as < Node * > () = new Method("Method", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ()); // type
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ()); // identifier
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ()); // param
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); // method body
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // return expression
              }
#line 939 "parser.tab.c"
    break;

  case 13: // methoddeclaration: PUBLIC type identifier LP RP LCB methodbody RETURN expression SEMICOLON RCB
#line 107 "parser.y"
                                                                                            {
                      yylhs.value.as < Node * > () = new Method("Method", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ()); // type
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ()); // identifier
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); // method body
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // return expression
              }
#line 951 "parser.tab.c"
    break;

  case 14: // methoddeclaration: PUBLIC type identifier LP parameters RP LCB RETURN expression SEMICOLON RCB
#line 114 "parser.y"
                                                                                            {
                      yylhs.value.as < Node * > () = new Method("Method", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ()); // type
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ()); // identifier
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ()); // param
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // return expression
              }
#line 963 "parser.tab.c"
    break;

  case 15: // methoddeclaration: PUBLIC type identifier LP RP LCB RETURN expression SEMICOLON RCB
#line 121 "parser.y"
                                                                                 {
                      yylhs.value.as < Node * > () = new Method("Method", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ()); // type
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ()); // identifier
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // return expression
              }
#line 974 "parser.tab.c"
    break;

  case 16: // methoddeclarations: methoddeclaration
#line 129 "parser.y"
                              {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 980 "parser.tab.c"
    break;

  case 17: // methoddeclarations: methoddeclarations methoddeclaration
#line 130 "parser.y"
                                                   {
                      yylhs.value.as < Node * > () = new MethodDeclarations("MethodDeclarations", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 990 "parser.tab.c"
    break;

  case 18: // methodbody: vardeclaration
#line 137 "parser.y"
                           {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 996 "parser.tab.c"
    break;

  case 19: // methodbody: statement
#line 138 "parser.y"
                        {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 1002 "parser.tab.c"
    break;

  case 20: // methodbody: methodbody vardeclaration
#line 139 "parser.y"
                                        {
                      yylhs.value.as < Node * > () = new MethodBody("Method body", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // methodbody
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // variable
            }
#line 1012 "parser.tab.c"
    break;

  case 21: // methodbody: methodbody statement
#line 144 "parser.y"
                                   {
                      yylhs.value.as < Node * > () = new MethodBody("Method body", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // method body
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // statement
            }
#line 1022 "parser.tab.c"
    break;

  case 22: // vardeclaration: type identifier SEMICOLON
#line 150 "parser.y"
                                          {
                      yylhs.value.as < Node * > () = new Variable("Variable", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // type
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // identifier
              }
#line 1032 "parser.tab.c"
    break;

  case 23: // vardeclarations: vardeclaration
#line 157 "parser.y"
                           {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 1038 "parser.tab.c"
    break;

  case 24: // vardeclarations: vardeclarations vardeclaration
#line 158 "parser.y"
                                             {
                      yylhs.value.as < Node * > () = new VariableList("Variables", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // recursion
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // variable
            }
#line 1048 "parser.tab.c"
    break;

  case 25: // parameters: type identifier
#line 165 "parser.y"
                            {
                      yylhs.value.as < Node * > () = new Parameter("Parameter", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // type
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // identifier
            }
#line 1058 "parser.tab.c"
    break;

  case 26: // parameters: type identifier COMMA parameters
#line 170 "parser.y"
                                               {
                      yylhs.value.as < Node * > () = new ParameterList("Parameters", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); // type
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // identifier
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // undef nr of prams
            }
#line 1069 "parser.tab.c"
    break;

  case 27: // type: INTTYPE LHB RHB
#line 177 "parser.y"
                      {
            yylhs.value.as < Node * > () = new ArrayType("int[]", "", yylineno);
              }
#line 1077 "parser.tab.c"
    break;

  case 28: // type: BOOLTYPE
#line 180 "parser.y"
                 {
            yylhs.value.as < Node * > () =  new BoolType("bool", "", yylineno);
              }
#line 1085 "parser.tab.c"
    break;

  case 29: // type: INTTYPE
#line 183 "parser.y"
                {
            yylhs.value.as < Node * > () = new IntType("int", "", yylineno);
              }
#line 1093 "parser.tab.c"
    break;

  case 30: // type: identifier
#line 186 "parser.y"
                   {
            yylhs.value.as < Node * > () = new IdenType("classType", "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        }
#line 1102 "parser.tab.c"
    break;

  case 31: // statement: LCB RCB
#line 191 "parser.y"
                     { 
              yylhs.value.as < Node * > () = new NonStmt("NonStatements", "", yylineno);
            }
#line 1110 "parser.tab.c"
    break;

  case 32: // statement: LCB statements RCB
#line 194 "parser.y"
                                  { 
              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
            }
#line 1118 "parser.tab.c"
    break;

  case 33: // statement: stmt_if
#line 197 "parser.y"
              { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1124 "parser.tab.c"
    break;

  case 34: // statement: WHILE LP expression RP statement
#line 198 "parser.y"
                                               {
              yylhs.value.as < Node * > () = new WhileStmt("While", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // expression
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // statement
            }
#line 1134 "parser.tab.c"
    break;

  case 35: // statement: PRINT LP expression RP SEMICOLON
#line 203 "parser.y"
                                               {
              yylhs.value.as < Node * > () = new PrintStmt("Print", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // expresssion
            }
#line 1143 "parser.tab.c"
    break;

  case 36: // statement: identifier ASSIGN expression SEMICOLON
#line 207 "parser.y"
                                                     {
              yylhs.value.as < Node * > () = new AssignStmt("Assign", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); // identifier
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // expression
            }
#line 1153 "parser.tab.c"
    break;

  case 37: // statement: identifier LHB expression RHB ASSIGN expression SEMICOLON
#line 212 "parser.y"
                                                                        {
              yylhs.value.as < Node * > () = new ArrayIndexAssign("indexAssign", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ()); // identifier
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); // expression
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // expression
            }
#line 1164 "parser.tab.c"
    break;

  case 38: // statements: statement
#line 220 "parser.y"
                      {
                  yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                }
#line 1172 "parser.tab.c"
    break;

  case 39: // statements: statements statement
#line 223 "parser.y"
                                   { 
              yylhs.value.as < Node * > () = new Statements("Statements", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // recursion
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // statement
            }
#line 1182 "parser.tab.c"
    break;

  case 40: // stmt_if: IF LP expression RP statement
#line 229 "parser.y"
                                                     { // To solve dangling else ambiguity
              yylhs.value.as < Node * > () = new IfStmt("IF", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // expression
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // statement
            }
#line 1192 "parser.tab.c"
    break;

  case 41: // stmt_if: IF LP expression RP statement ELSE statement
#line 234 "parser.y"
                                                           {
              yylhs.value.as < Node * > () = new IfElseStmt("IfElse", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); // expression
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // statement
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // statement
            }
#line 1203 "parser.tab.c"
    break;

  case 42: // expression: expression PLUSOP expression
#line 242 "parser.y"
                                         {      
                            yylhs.value.as < Node * > () = new PlusOP("AddExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1213 "parser.tab.c"
    break;

  case 43: // expression: expression MINUSOP expression
#line 247 "parser.y"
                                            {
                            yylhs.value.as < Node * > () = new MinusOP("SubExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1223 "parser.tab.c"
    break;

  case 44: // expression: expression MULTOP expression
#line 252 "parser.y"
                                           {
                            yylhs.value.as < Node * > () = new MultOP("MultExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1233 "parser.tab.c"
    break;

  case 45: // expression: expression DIVOP expression
#line 257 "parser.y"
                                          {
                            yylhs.value.as < Node * > () = new DivOP("DivExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1243 "parser.tab.c"
    break;

  case 46: // expression: expression ASSIGN expression
#line 262 "parser.y"
                                           {
                            yylhs.value.as < Node * > () = new AssignExpr("Assign", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1253 "parser.tab.c"
    break;

  case 47: // expression: expression GT expression
#line 267 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new GreaterThan("GreaterThan", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1263 "parser.tab.c"
    break;

  case 48: // expression: expression LT expression
#line 272 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new LessThan("LessThan", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1273 "parser.tab.c"
    break;

  case 49: // expression: expression EQ expression
#line 277 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Equals("Equals", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1283 "parser.tab.c"
    break;

  case 50: // expression: expression OR expression
#line 282 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Or("OR", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1293 "parser.tab.c"
    break;

  case 51: // expression: expression AND expression
#line 287 "parser.y"
                                        {
                            yylhs.value.as < Node * > () = new And("AND", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1303 "parser.tab.c"
    break;

  case 52: // expression: experiment
#line 293 "parser.y"
              { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1309 "parser.tab.c"
    break;

  case 53: // expression: expression PERIOD LENGTH
#line 295 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new LengthOf("LenghtOfExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // expression
                          }
#line 1318 "parser.tab.c"
    break;

  case 54: // expression: expression PERIOD identifier LP exprlist RP
#line 299 "parser.y"
                                                          {  // recursive grammar, follows recursive rules
                              yylhs.value.as < Node * > () = new MethCall("Method call from class", "", yylineno);
                              yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ()); // expression
                              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); // identifier
                              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // expression list
                          }
#line 1329 "parser.tab.c"
    break;

  case 55: // expression: expression PERIOD identifier LP RP
#line 305 "parser.y"
                                                 {  // for the empty case
                              yylhs.value.as < Node * > () = new MethCall("Method call from class", "", yylineno);
                              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); // expression
                              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // identifier
                          }
#line 1339 "parser.tab.c"
    break;

  case 56: // expression: TRUE
#line 310 "parser.y"
                   {
                  yylhs.value.as < Node * > () = new TrueVal("True", "", yylineno);
                }
#line 1347 "parser.tab.c"
    break;

  case 57: // expression: FALSE
#line 313 "parser.y"
                    {
                  yylhs.value.as < Node * > () = new FalseVal("False", "", yylineno);
                }
#line 1355 "parser.tab.c"
    break;

  case 58: // expression: identifier
#line 316 "parser.y"
                         {
                  yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                }
#line 1363 "parser.tab.c"
    break;

  case 59: // expression: THIS
#line 319 "parser.y"
                    {
                  yylhs.value.as < Node * > () = new ThisOP("this", "", yylineno);
                }
#line 1371 "parser.tab.c"
    break;

  case 60: // expression: NEW INTTYPE LHB expression RHB
#line 322 "parser.y"
                                             {
                      yylhs.value.as < Node * > () = new IntArray("int[]", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // Size of int array
                  }
#line 1380 "parser.tab.c"
    break;

  case 61: // expression: NEW identifier LP RP
#line 326 "parser.y"
                                   {
                      yylhs.value.as < Node * > () = new IdenAlloc("new ID()", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());  
                      // printf("NEW ident: %d\n", yylineno);
                  }
#line 1390 "parser.tab.c"
    break;

  case 62: // expression: EXCLAMATION expression
#line 331 "parser.y"
                                     {
                      yylhs.value.as < Node * > () = new Negation("Negation", "", yylineno); // expression
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
                  }
#line 1399 "parser.tab.c"
    break;

  case 63: // expression: factor
#line 335 "parser.y"
                          {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); /* printf("r4 ");*/
              }
#line 1406 "parser.tab.c"
    break;

  case 64: // experiment: expression LHB expression RHB
#line 338 "parser.y"
                                          { //??
                      yylhs.value.as < Node * > () = new Index("index", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());  // what to take index of
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // index value
                  }
#line 1416 "parser.tab.c"
    break;

  case 65: // exprlist: expression
#line 344 "parser.y"
                     {
                      yylhs.value.as < Node * > () = new Expression("(Expression)", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                  }
#line 1425 "parser.tab.c"
    break;

  case 66: // exprlist: exprlist COMMA expression
#line 348 "parser.y"
                                        {
                      yylhs.value.as < Node * > () = new ExpressionList("ExpressionList", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                  }
#line 1435 "parser.tab.c"
    break;

  case 67: // factor: INT
#line 354 "parser.y"
            {
                      yylhs.value.as < Node * > () = new IntVal("int", yystack_[0].value.as < std::string > (), yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
#line 1442 "parser.tab.c"
    break;

  case 68: // factor: LP expression RP
#line 356 "parser.y"
                               { 
                      yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); /* printf("r6 ");  simply return the expression */
                  }
#line 1450 "parser.tab.c"
    break;

  case 69: // identifier: IDENTIFIER
#line 360 "parser.y"
                       {
                    yylhs.value.as < Node * > () = new Identifier("Identifier", yystack_[0].value.as < std::string > (), yylineno); 
            }
#line 1458 "parser.tab.c"
    break;


#line 1462 "parser.tab.c"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -51;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      16,     0,    50,   -51,    32,    17,   -51,   -51,    17,   -51,
      38,   -51,    58,    60,   -51,   -51,    53,   299,    63,   -51,
     -23,    75,   -51,   -51,    42,   -51,   301,    17,   -51,    66,
      17,    80,   -51,   -51,   -51,    44,   -51,    69,    72,    93,
     -51,   -51,   -51,    99,    -4,    79,   103,   107,    17,   108,
      -2,   119,    90,   121,    61,   105,   111,   128,   130,   125,
     -51,   -51,   -51,    73,   142,   -23,    17,   -51,   -51,   181,
      73,   -51,   105,   105,    23,   -51,   -51,   -51,   207,   -51,
     -51,   -51,   105,   105,   105,   105,   -51,   -51,   105,   105,
     105,   153,   -51,   139,   -51,   -51,   338,   113,   141,   144,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,    26,   136,   356,   374,   392,   224,   409,   241,   258,
     105,   145,   -51,   105,   152,     8,     8,    -9,    -9,   426,
     460,   494,   477,   477,   504,   504,   -51,   154,   -51,   162,
     162,   124,   155,   156,   -51,   166,   275,   162,   443,   -51,
     -51,    39,   132,   -51,   -51,   -51,   105,   -51,   169,   172,
     -51,   -51,   460,    15,   162,   292,   -51,   174,   -51,   105,
     -51,   -51,   -51,   460
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     0,     1,     4,     0,    10,
       0,    69,     0,     0,     3,    11,     0,     0,     0,     9,
       0,    29,    28,    16,     0,    23,     0,     0,    30,     0,
       0,     0,     7,    17,     8,     0,    24,     0,     0,     0,
      27,     6,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    33,    30,     0,     0,     0,    31,    38,     0,
       0,    67,     0,     0,     0,    56,    57,    59,     0,    52,
      63,    58,     0,     0,     0,     0,    20,    21,     0,     0,
       0,     0,    26,     0,    32,    39,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,     0,     0,    42,    43,    44,    45,     0,
      46,    49,    51,    50,    47,    48,    53,     0,    15,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,    61,
      64,     0,    40,    34,    35,    13,     0,    14,     0,     0,
      60,    55,    65,     0,     0,     0,    12,     0,    54,     0,
      41,    37,     5,    66
  };

  const short
  parser::yypgoto_[] =
  {
     -51,   -51,   -51,   -51,   159,   -51,    47,   164,   134,   -15,
     -51,   131,   -14,   -50,   -51,   -51,    20,   -51,   -51,   -51,
      -5
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,     9,    10,    23,    24,    59,    60,
      26,    47,    27,    61,    69,    62,    78,    79,   163,    80,
      81
  };

  const unsigned char
  parser::yytable_[] =
  {
      12,   104,    25,    13,    68,    46,    30,    21,    22,    87,
      54,    36,    28,   102,   103,    28,    11,   111,   104,    95,
       5,    28,    37,    55,   168,    39,    21,    22,    21,    22,
      48,    56,     7,    57,   111,    11,    58,    11,    14,    28,
       1,    87,   169,    52,    86,    63,    71,    72,   161,    70,
       6,    48,     8,    98,    63,    32,    11,    41,     8,    63,
      28,    93,    11,   136,    70,    11,    20,    73,    20,    99,
      16,    33,    17,    54,    67,    74,    86,    18,    11,    75,
      76,    77,    33,    88,    29,    31,    63,    89,    38,   152,
     153,    40,    96,    97,    56,    43,    57,   159,    42,    58,
      11,    44,   113,   114,   115,   116,   137,    45,   117,   118,
     119,    49,    71,    72,   170,    50,    51,    65,    53,    82,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    64,    66,    73,    70,    70,    83,    54,    84,   111,
     146,    74,    70,   148,    11,    75,    76,    77,   121,   138,
      85,   123,   124,   154,    54,    21,    22,   147,    56,    70,
      57,   149,   151,    58,    11,    54,   164,    90,   155,    15,
     156,   162,    21,    22,    54,    56,   165,    57,   120,   157,
      58,    11,   166,    21,    22,   167,    56,   172,    57,   173,
      35,    58,    11,    54,    94,    56,    92,    57,    91,     0,
      58,    11,     0,     0,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,    56,     0,    57,   104,     0,    58,
      11,   105,   106,   107,   108,   109,   110,   100,   101,   102,
     103,     0,     0,   111,   104,     0,   112,     0,   105,   106,
     107,   108,   109,   110,   100,   101,   102,   103,     0,     0,
     111,   104,     0,   142,     0,   105,   106,   107,   108,   109,
     110,   100,   101,   102,   103,     0,     0,   111,   104,     0,
     144,     0,   105,   106,   107,   108,   109,   110,   100,   101,
     102,   103,     0,     0,   111,   104,     0,   145,     0,   105,
     106,   107,   108,   109,   110,   100,   101,   102,   103,     0,
       0,   111,   104,     0,   158,     0,   105,   106,   107,   108,
     109,   110,    19,     0,    34,     0,     0,     0,   111,     0,
       0,   171,     0,    20,     0,    20,     0,     0,     0,    21,
      22,    21,    22,     0,     0,     0,     0,     0,    11,     0,
      11,   100,   101,   102,   103,     0,     0,   122,   104,     0,
       0,     0,   105,   106,   107,   108,   109,   110,     0,   100,
     101,   102,   103,     0,   111,   139,   104,     0,     0,     0,
     105,   106,   107,   108,   109,   110,     0,   100,   101,   102,
     103,     0,   111,   140,   104,     0,     0,     0,   105,   106,
     107,   108,   109,   110,     0,   100,   101,   102,   103,     0,
     111,   141,   104,     0,     0,     0,   105,   106,   107,   108,
     109,   110,   100,   101,   102,   103,     0,     0,   111,   104,
     143,     0,     0,   105,   106,   107,   108,   109,   110,   100,
     101,   102,   103,     0,     0,   111,   104,   150,     0,     0,
     105,   106,   107,   108,   109,   110,   100,   101,   102,   103,
       0,     0,   111,   104,   160,     0,     0,   105,   106,   107,
     108,   109,   110,   100,   101,   102,   103,     0,     0,   111,
     104,     0,     0,     0,   105,   106,   107,   108,   109,   110,
     100,   101,   102,   103,     0,     0,   111,   104,     0,     0,
       0,     0,   106,     0,     0,   109,   110,   100,   101,   102,
     103,     0,     0,   111,   104,     0,     0,   100,   101,   102,
     103,     0,   109,   110,   104,     0,     0,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111
  };

  const short
  parser::yycheck_[] =
  {
       5,    10,    17,     8,    54,     9,    20,    30,    31,    59,
      12,    26,    17,     5,     6,    20,    39,    26,    10,    69,
      20,    26,    27,    25,     9,    30,    30,    31,    30,    31,
      44,    33,     0,    35,    26,    39,    38,    39,     0,    44,
      24,    91,    27,    48,    59,    50,     7,     8,     9,    54,
       0,    65,    20,    30,    59,    13,    39,    13,    20,    64,
      65,    66,    39,    37,    69,    39,    24,    28,    24,    74,
      12,    24,    12,    12,    13,    36,    91,    24,    39,    40,
      41,    42,    35,    10,    21,    10,    91,    14,    22,   139,
     140,    11,    72,    73,    33,    23,    35,   147,    29,    38,
      39,     8,    82,    83,    84,    85,   111,     8,    88,    89,
      90,    32,     7,     8,   164,    12,     9,    27,    10,     8,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    12,    11,    28,   139,   140,     8,    12,     8,    26,
     120,    36,   147,   123,    39,    40,    41,    42,     9,    13,
      25,    10,     8,    29,    12,    30,    31,    12,    33,   164,
      35,     9,     8,    38,    39,    12,    34,    25,    13,    10,
      14,   151,    30,    31,    12,    33,   156,    35,    25,    13,
      38,    39,    13,    30,    31,    13,    33,    13,    35,   169,
      26,    38,    39,    12,    13,    33,    65,    35,    64,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    33,    -1,    35,    10,    -1,    38,
      39,    14,    15,    16,    17,    18,    19,     3,     4,     5,
       6,    -1,    -1,    26,    10,    -1,    29,    -1,    14,    15,
      16,    17,    18,    19,     3,     4,     5,     6,    -1,    -1,
      26,    10,    -1,    29,    -1,    14,    15,    16,    17,    18,
      19,     3,     4,     5,     6,    -1,    -1,    26,    10,    -1,
      29,    -1,    14,    15,    16,    17,    18,    19,     3,     4,
       5,     6,    -1,    -1,    26,    10,    -1,    29,    -1,    14,
      15,    16,    17,    18,    19,     3,     4,     5,     6,    -1,
      -1,    26,    10,    -1,    29,    -1,    14,    15,    16,    17,
      18,    19,    13,    -1,    13,    -1,    -1,    -1,    26,    -1,
      -1,    29,    -1,    24,    -1,    24,    -1,    -1,    -1,    30,
      31,    30,    31,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      39,     3,     4,     5,     6,    -1,    -1,     9,    10,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    -1,     3,
       4,     5,     6,    -1,    26,     9,    10,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    -1,     3,     4,     5,
       6,    -1,    26,     9,    10,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    -1,     3,     4,     5,     6,    -1,
      26,     9,    10,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,     3,     4,     5,     6,    -1,    -1,    26,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,     3,
       4,     5,     6,    -1,    -1,    26,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,     3,     4,     5,     6,
      -1,    -1,    26,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,     3,     4,     5,     6,    -1,    -1,    26,
      10,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
       3,     4,     5,     6,    -1,    -1,    26,    10,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    18,    19,     3,     4,     5,
       6,    -1,    -1,    26,    10,    -1,    -1,     3,     4,     5,
       6,    -1,    18,    19,    10,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26
  };

  const signed char
  parser::yystos_[] =
  {
       0,    24,    45,    46,    47,    20,     0,     0,    20,    48,
      49,    39,    64,    64,     0,    48,    12,    12,    24,    13,
      24,    30,    31,    50,    51,    53,    54,    56,    64,    21,
      56,    10,    13,    50,    13,    51,    53,    64,    22,    64,
      11,    13,    29,    23,     8,     8,     9,    55,    56,    32,
      12,     9,    64,    10,    12,    25,    33,    35,    38,    52,
      53,    57,    59,    64,    12,    27,    11,    13,    57,    58,
      64,     7,     8,    28,    36,    40,    41,    42,    60,    61,
      63,    64,     8,     8,     8,    25,    53,    57,    10,    14,
      25,    52,    55,    64,    13,    57,    60,    60,    30,    64,
       3,     4,     5,     6,    10,    14,    15,    16,    17,    18,
      19,    26,    29,    60,    60,    60,    60,    60,    60,    60,
      25,     9,     9,    10,     8,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    37,    64,    13,     9,
       9,     9,    29,    11,    29,    29,    60,    12,    60,     9,
      11,     8,    57,    57,    29,    13,    14,    13,    29,    57,
      11,     9,    60,    62,    34,    60,    13,    13,     9,    27,
      57,    29,    13,    60
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    45,    46,    46,    47,    48,    48,    48,    48,
      49,    49,    50,    50,    50,    50,    51,    51,    52,    52,
      52,    52,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    62,    62,    63,    63,    64
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,     2,    18,     6,     5,     5,     4,
       1,     2,    12,    11,    11,    10,     1,     2,     1,     1,
       2,     2,     3,     1,     2,     2,     4,     3,     1,     1,
       1,     2,     3,     1,     5,     5,     4,     7,     1,     2,
       5,     7,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     6,     5,     1,     1,     1,     1,
       5,     4,     2,     1,     4,     1,     3,     1,     3,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PLUSOP", "MINUSOP",
  "MULTOP", "DIVOP", "INT", "LP", "RP", "LHB", "RHB", "LCB", "RCB",
  "ASSIGN", "EQ", "AND", "OR", "GT", "LT", "CLASS", "STATIC", "VOID",
  "MAIN", "PUBLIC", "RETURN", "PERIOD", "COMMA", "EXCLAMATION",
  "SEMICOLON", "INTTYPE", "BOOLTYPE", "STRING", "IF", "ELSE", "WHILE",
  "NEW", "LENGTH", "PRINT", "IDENTIFIER", "TRUE", "FALSE", "THIS",
  "NO_ELSE", "$accept", "root", "goal", "mainclass", "classdeclaration",
  "classdeclarations", "methoddeclaration", "methoddeclarations",
  "methodbody", "vardeclaration", "vardeclarations", "parameters", "type",
  "statement", "statements", "stmt_if", "expression", "experiment",
  "exprlist", "factor", "identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    50,    50,    53,    58,    63,    70,    76,    81,    86,
      92,    93,    99,   107,   114,   121,   129,   130,   137,   138,
     139,   144,   150,   157,   158,   165,   170,   177,   180,   183,
     186,   191,   194,   197,   198,   203,   207,   212,   220,   223,
     229,   234,   242,   247,   252,   257,   262,   267,   272,   277,
     282,   287,   293,   295,   299,   305,   310,   313,   316,   319,
     322,   326,   331,   335,   338,   344,   348,   354,   356,   360
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2105 "parser.tab.c"

