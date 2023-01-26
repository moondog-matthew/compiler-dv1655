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
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_COMMENT: // COMMENT
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
      case symbol_kind::S_STATEMENT: // STATEMENT
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
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_COMMENT: // COMMENT
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
      case symbol_kind::S_STATEMENT: // STATEMENT
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
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_COMMENT: // COMMENT
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
      case symbol_kind::S_STATEMENT: // STATEMENT
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
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_COMMENT: // COMMENT
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
      case symbol_kind::S_STATEMENT: // STATEMENT
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
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_COMMENT: // COMMENT
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
      case symbol_kind::S_STATEMENT: // STATEMENT
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
  case 2: // root: statement
#line 41 "parser.y"
                      {root = yystack_[0].value.as < Node * > ();}
#line 775 "parser.tab.c"
    break;

  case 4: // statement: LCB statements RCB
#line 70 "parser.y"
                                 { 
              yylhs.value.as < Node * > () = new Node("Statements", "", yylineno);
            }
#line 783 "parser.tab.c"
    break;

  case 5: // statement: IF LP expression RP statement
#line 73 "parser.y"
                                            {
              yylhs.value.as < Node * > () = new Node("IF", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 793 "parser.tab.c"
    break;

  case 6: // statement: IF LP expression RP statement ELSE statement
#line 78 "parser.y"
                                                           {
              yylhs.value.as < Node * > () = new Node("IfElse", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 804 "parser.tab.c"
    break;

  case 7: // statement: WHILE LP expression RP statement
#line 84 "parser.y"
                                               {
              yylhs.value.as < Node * > () = new Node("While", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 814 "parser.tab.c"
    break;

  case 8: // statement: PRINT LP expression RP SEMICOLON
#line 89 "parser.y"
                                               {
              yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 823 "parser.tab.c"
    break;

  case 9: // statement: identifier ASSIGN expression SEMICOLON
#line 93 "parser.y"
                                                     {
              yylhs.value.as < Node * > () = new Node("Assign", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 833 "parser.tab.c"
    break;

  case 10: // statement: identifier LHB expression RHB ASSIGN expression SEMICOLON
#line 98 "parser.y"
                                                                        {
              yylhs.value.as < Node * > () = new Node("indexAssign", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 844 "parser.tab.c"
    break;

  case 12: // statements: statements statement
#line 108 "parser.y"
                                   { 
              yylhs.value.as < Node * > () = new Node("Statements", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

            }
#line 855 "parser.tab.c"
    break;

  case 13: // expression: expression PLUSOP expression
#line 117 "parser.y"
                                         {      /*
                                                  Create a subtree that corresponds to the AddExpression
                                                  The root of the subtree is AddExpression
                                                  The childs of the AddExpression subtree are the left hand side (expression accessed through $1) and right hand side of the expression (expression accessed through $3)
                                                */
                            yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r1 "); */
                          }
#line 870 "parser.tab.c"
    break;

  case 14: // expression: expression MINUSOP expression
#line 127 "parser.y"
                                            {
                            yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r2 "); */
                          }
#line 881 "parser.tab.c"
    break;

  case 15: // expression: expression MULTOP expression
#line 133 "parser.y"
                                           {
                            yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r3 "); */
                          }
#line 892 "parser.tab.c"
    break;

  case 16: // expression: expression DIVOP expression
#line 139 "parser.y"
                                          {
                            yylhs.value.as < Node * > () = new Node("DivExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r3 "); */
                          }
#line 903 "parser.tab.c"
    break;

  case 17: // expression: expression ASSIGN expression
#line 145 "parser.y"
                                           {
                            yylhs.value.as < Node * > () = new Node("Assigning", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 913 "parser.tab.c"
    break;

  case 18: // expression: expression GT expression
#line 150 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("GreaterThan", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 923 "parser.tab.c"
    break;

  case 19: // expression: expression LT expression
#line 155 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("LessThan", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 933 "parser.tab.c"
    break;

  case 20: // expression: expression EQ expression
#line 160 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("Equals", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 943 "parser.tab.c"
    break;

  case 21: // expression: expression OR expression
#line 165 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("OR", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 953 "parser.tab.c"
    break;

  case 22: // expression: expression AND expression
#line 170 "parser.y"
                                        {
                            yylhs.value.as < Node * > () = new Node("AND", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 963 "parser.tab.c"
    break;

  case 23: // expression: expression LHB expression RHB
#line 176 "parser.y"
                                            {
                            yylhs.value.as < Node * > () = new Node("Index", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());  // what to take index of
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // index value
                          }
#line 973 "parser.tab.c"
    break;

  case 24: // expression: expression PERIOD LENGTH
#line 181 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("LenghtOfExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          }
#line 982 "parser.tab.c"
    break;

  case 25: // expression: expression PERIOD identifier LP expression COMMA expression RP
#line 185 "parser.y"
                                                                             {
                              // TODO
                          }
#line 990 "parser.tab.c"
    break;

  case 26: // expression: TRUE
#line 189 "parser.y"
                   {
                  yylhs.value.as < Node * > () = new Node("True", "", yylineno);
                }
#line 998 "parser.tab.c"
    break;

  case 27: // expression: FALSE
#line 192 "parser.y"
                    {
                  yylhs.value.as < Node * > () = new Node("False", "", yylineno);
                }
#line 1006 "parser.tab.c"
    break;

  case 28: // expression: identifier
#line 195 "parser.y"
                         {
                  yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                }
#line 1014 "parser.tab.c"
    break;

  case 29: // expression: THIS
#line 198 "parser.y"
                    {
                  yylhs.value.as < Node * > () = new Node("This", "", yylineno);
                }
#line 1022 "parser.tab.c"
    break;

  case 30: // expression: NEW INTTYPE LHB expression RHB
#line 201 "parser.y"
                                             {
                      yylhs.value.as < Node * > () = new Node("AllocateIntArray", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // Size of int array
                  }
#line 1031 "parser.tab.c"
    break;

  case 31: // expression: NEW identifier LP RP
#line 205 "parser.y"
                                   {
                      yylhs.value.as < Node * > () = new Node("AllocateIdentifier", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());  
                  }
#line 1040 "parser.tab.c"
    break;

  case 32: // expression: EXCLAMATION expression
#line 209 "parser.y"
                                     {
                      yylhs.value.as < Node * > () = new Node("Negation", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
                  }
#line 1049 "parser.tab.c"
    break;

  case 33: // expression: factor
#line 213 "parser.y"
                          {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); /* printf("r4 ");*/}
#line 1055 "parser.tab.c"
    break;

  case 34: // factor: INT
#line 217 "parser.y"
                          {  yylhs.value.as < Node * > () = new Node("Int", yystack_[0].value.as < std::string > (), yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
#line 1061 "parser.tab.c"
    break;

  case 35: // factor: LP expression RP
#line 218 "parser.y"
                               { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); /* printf("r6 ");  simply return the expression */}
#line 1067 "parser.tab.c"
    break;

  case 36: // identifier: IDENTIFIER
#line 221 "parser.y"
                       {
                    yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno); // Here we create a leaf node Int. The value of the leaf node is $1 
                          }
#line 1075 "parser.tab.c"
    break;


#line 1079 "parser.tab.c"

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


  const signed char parser::yypact_ninf_ = -18;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      49,   -18,    -7,    -1,     6,   -18,     8,   -18,    52,    38,
      18,    18,    18,   -18,    18,    18,   -18,   -18,   -18,    18,
      18,   -17,   -18,   -18,   -18,   139,   -18,   -18,   157,   175,
     192,    86,   210,   279,    14,     7,    18,    18,    18,    18,
      49,    18,    18,    18,    18,    18,    18,    18,     5,    49,
       2,    27,   -18,   -18,    18,    44,    59,    59,    -6,    -6,
      21,   227,   296,   330,   313,   313,    13,    13,   -18,    39,
     -18,   -18,    18,   244,   -18,    49,   -18,    18,   103,   -18,
     -18,   120,   -18,    18,   262,   -18
  };

  const signed char
  parser::yydefact_[] =
  {
       3,    11,     0,     0,     0,    36,     0,     2,     0,     0,
       0,     0,     0,     1,     0,     0,     4,    12,    34,     0,
       0,     0,    26,    27,    29,     0,    33,    28,     0,     0,
       0,     0,     0,    32,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     9,    35,     0,     0,    13,    14,    15,    16,
       5,     0,    17,    20,    22,    21,    18,    19,    24,     0,
       7,     8,     0,     0,    31,     3,    23,     0,     0,    30,
       6,     0,    10,     0,     0,    25
  };

  const signed char
  parser::yypgoto_[] =
  {
     -18,   -18,     3,   -18,    -9,   -18,     0
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     6,     7,     9,    25,    26,    27
  };

  const signed char
  parser::yytable_[] =
  {
       8,    10,    28,    29,    41,    30,    31,    11,    13,     8,
      32,    33,    17,    34,    12,    55,    36,    37,    38,    39,
      48,    35,     5,    41,    54,    18,    19,    56,    57,    58,
      59,    71,    61,    62,    63,    64,    65,    66,    67,    48,
       8,    72,    68,    60,     5,    73,    20,    77,    69,     8,
       1,    16,    70,    74,    21,    75,     0,     5,    22,    23,
      24,     1,    14,    78,    38,    39,    15,     0,    81,    41,
       0,     2,     0,     3,    84,     8,     4,     5,    80,     0,
       0,     0,     2,     0,     3,    48,     0,     4,     5,    36,
      37,    38,    39,     0,     0,     0,    41,     0,     0,     0,
      42,    43,    44,    45,    46,    47,    36,    37,    38,    39,
       0,     0,    48,    41,     0,    52,     0,    42,    43,    44,
      45,    46,    47,    36,    37,    38,    39,     0,     0,    48,
      41,     0,    82,     0,    42,    43,    44,    45,    46,    47,
       0,     0,    36,    37,    38,    39,    48,    83,    40,    41,
       0,     0,     0,    42,    43,    44,    45,    46,    47,     0,
      36,    37,    38,    39,     0,    48,    49,    41,     0,     0,
       0,    42,    43,    44,    45,    46,    47,     0,    36,    37,
      38,    39,     0,    48,    50,    41,     0,     0,     0,    42,
      43,    44,    45,    46,    47,    36,    37,    38,    39,     0,
       0,    48,    41,    51,     0,     0,    42,    43,    44,    45,
      46,    47,     0,    36,    37,    38,    39,     0,    48,    53,
      41,     0,     0,     0,    42,    43,    44,    45,    46,    47,
      36,    37,    38,    39,     0,     0,    48,    41,    76,     0,
       0,    42,    43,    44,    45,    46,    47,    36,    37,    38,
      39,     0,     0,    48,    41,    79,     0,     0,    42,    43,
      44,    45,    46,    47,     0,    36,    37,    38,    39,     0,
      48,    85,    41,     0,     0,     0,    42,    43,    44,    45,
      46,    47,    36,    37,    38,    39,     0,     0,    48,    41,
       0,     0,     0,    42,    43,    44,    45,    46,    47,    36,
      37,    38,    39,     0,     0,    48,    41,     0,     0,     0,
       0,    43,    44,    45,    46,    47,    36,    37,    38,    39,
       0,     0,    48,    41,     0,     0,     0,     0,    43,     0,
       0,    46,    47,    36,    37,    38,    39,     0,     0,    48,
      41,     0,     0,     0,     0,     0,     0,     0,    46,    47,
       0,     0,     0,     0,     0,     0,    48
  };

  const signed char
  parser::yycheck_[] =
  {
       0,     8,    11,    12,    10,    14,    15,     8,     0,     9,
      19,    20,     9,    30,     8,     8,     3,     4,     5,     6,
      26,    21,    39,    10,    10,     7,     8,    36,    37,    38,
      39,    29,    41,    42,    43,    44,    45,    46,    47,    26,
      40,    14,    37,    40,    39,    54,    28,     8,    48,    49,
      12,    13,    49,     9,    36,    34,    -1,    39,    40,    41,
      42,    12,    10,    72,     5,     6,    14,    -1,    77,    10,
      -1,    33,    -1,    35,    83,    75,    38,    39,    75,    -1,
      -1,    -1,    33,    -1,    35,    26,    -1,    38,    39,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,     3,     4,     5,     6,
      -1,    -1,    26,    10,    -1,    29,    -1,    14,    15,    16,
      17,    18,    19,     3,     4,     5,     6,    -1,    -1,    26,
      10,    -1,    29,    -1,    14,    15,    16,    17,    18,    19,
      -1,    -1,     3,     4,     5,     6,    26,    27,     9,    10,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,    -1,
       3,     4,     5,     6,    -1,    26,     9,    10,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    19,    -1,     3,     4,
       5,     6,    -1,    26,     9,    10,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,     3,     4,     5,     6,    -1,
      -1,    26,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    -1,     3,     4,     5,     6,    -1,    26,     9,
      10,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
       3,     4,     5,     6,    -1,    -1,    26,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,     3,     4,     5,
       6,    -1,    -1,    26,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    -1,     3,     4,     5,     6,    -1,
      26,     9,    10,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,     3,     4,     5,     6,    -1,    -1,    26,    10,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,     3,
       4,     5,     6,    -1,    -1,    26,    10,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,     3,     4,     5,     6,
      -1,    -1,    26,    10,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    18,    19,     3,     4,     5,     6,    -1,    -1,    26,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    26
  };

  const signed char
  parser::yystos_[] =
  {
       0,    12,    33,    35,    38,    39,    45,    46,    50,    47,
       8,     8,     8,     0,    10,    14,    13,    46,     7,     8,
      28,    36,    40,    41,    42,    48,    49,    50,    48,    48,
      48,    48,    48,    48,    30,    50,     3,     4,     5,     6,
       9,    10,    14,    15,    16,    17,    18,    19,    26,     9,
       9,    11,    29,     9,    10,     8,    48,    48,    48,    48,
      46,    48,    48,    48,    48,    48,    48,    48,    37,    50,
      46,    29,    14,    48,     9,    34,    11,     8,    48,    11,
      46,    48,    29,    27,    48,     9
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    45,    46,    46,    46,    46,    46,    46,    46,
      46,    47,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    49,    50
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     3,     5,     7,     5,     5,     4,
       7,     0,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     8,     1,     1,     1,     1,
       5,     4,     2,     1,     1,     3,     1
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
  "MAIN", "PUBLIC", "COMMENT", "PERIOD", "COMMA", "EXCLAMATION",
  "SEMICOLON", "INTTYPE", "BOOLTYPE", "STRING", "IF", "ELSE", "WHILE",
  "NEW", "LENGTH", "PRINT", "IDENTIFIER", "TRUE", "FALSE", "THIS",
  "STATEMENT", "$accept", "root", "statement", "statements", "expression",
  "factor", "identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    41,    41,    68,    70,    73,    78,    84,    89,    93,
      98,   106,   108,   117,   127,   133,   139,   145,   150,   155,
     160,   165,   170,   176,   181,   185,   189,   192,   195,   198,
     201,   205,   209,   213,   217,   218,   221
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
#line 1643 "parser.tab.c"

