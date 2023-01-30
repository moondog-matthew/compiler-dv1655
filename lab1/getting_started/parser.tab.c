// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.tab.h"


// Unqualified %code blocks.
#line 11 "parser.y"

  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;
  extern int yylineno;
  

#line 55 "parser.tab.c"


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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
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
#line 127 "parser.tab.c"


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

  /*---------------.
  | Symbol types.  |
  `---------------*/



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

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 45: // root
      case 46: // goal
      case 47: // mainclass
      case 48: // classdeclaration
      case 49: // classdeclarations
      case 50: // methoddeclaration
      case 51: // methoddeclarations
      case 52: // methodbody
      case 53: // vardeclaration
      case 54: // vardeclarations
      case 55: // parameters
      case 56: // type
      case 57: // statement
      case 58: // statements
      case 59: // stmt_if
      case 60: // expression
      case 61: // experiment
      case 62: // exprlist
      case 63: // factor
      case 64: // identifier
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // DIVOP
      case 7: // INT
      case 8: // LP
      case 9: // RP
      case 10: // LHB
      case 11: // RHB
      case 12: // LCB
      case 13: // RCB
      case 14: // ASSIGN
      case 15: // EQ
      case 16: // AND
      case 17: // OR
      case 18: // GT
      case 19: // LT
      case 20: // CLASS
      case 21: // STATIC
      case 22: // VOID
      case 23: // MAIN
      case 24: // PUBLIC
      case 25: // RETURN
      case 26: // PERIOD
      case 27: // COMMA
      case 28: // EXCLAMATION
      case 29: // SEMICOLON
      case 30: // INTTYPE
      case 31: // BOOLTYPE
      case 32: // STRING
      case 33: // IF
      case 34: // ELSE
      case 35: // WHILE
      case 36: // NEW
      case 37: // LENGTH
      case 38: // PRINT
      case 39: // IDENTIFIER
      case 40: // TRUE
      case 41: // FALSE
      case 42: // THIS
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
    switch (that.type_get ())
    {
      case 45: // root
      case 46: // goal
      case 47: // mainclass
      case 48: // classdeclaration
      case 49: // classdeclarations
      case 50: // methoddeclaration
      case 51: // methoddeclarations
      case 52: // methodbody
      case 53: // vardeclaration
      case 54: // vardeclarations
      case 55: // parameters
      case 56: // type
      case 57: // statement
      case 58: // statements
      case 59: // stmt_if
      case 60: // expression
      case 61: // experiment
      case 62: // exprlist
      case 63: // factor
      case 64: // identifier
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // DIVOP
      case 7: // INT
      case 8: // LP
      case 9: // RP
      case 10: // LHB
      case 11: // RHB
      case 12: // LCB
      case 13: // RCB
      case 14: // ASSIGN
      case 15: // EQ
      case 16: // AND
      case 17: // OR
      case 18: // GT
      case 19: // LT
      case 20: // CLASS
      case 21: // STATIC
      case 22: // VOID
      case 23: // MAIN
      case 24: // PUBLIC
      case 25: // RETURN
      case 26: // PERIOD
      case 27: // COMMA
      case 28: // EXCLAMATION
      case 29: // SEMICOLON
      case 30: // INTTYPE
      case 31: // BOOLTYPE
      case 32: // STRING
      case 33: // IF
      case 34: // ELSE
      case 35: // WHILE
      case 36: // NEW
      case 37: // LENGTH
      case 38: // PRINT
      case 39: // IDENTIFIER
      case 40: // TRUE
      case 41: // FALSE
      case 42: // THIS
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 45: // root
      case 46: // goal
      case 47: // mainclass
      case 48: // classdeclaration
      case 49: // classdeclarations
      case 50: // methoddeclaration
      case 51: // methoddeclarations
      case 52: // methodbody
      case 53: // vardeclaration
      case 54: // vardeclarations
      case 55: // parameters
      case 56: // type
      case 57: // statement
      case 58: // statements
      case 59: // stmt_if
      case 60: // expression
      case 61: // experiment
      case 62: // exprlist
      case 63: // factor
      case 64: // identifier
        value.copy< Node * > (that.value);
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // DIVOP
      case 7: // INT
      case 8: // LP
      case 9: // RP
      case 10: // LHB
      case 11: // RHB
      case 12: // LCB
      case 13: // RCB
      case 14: // ASSIGN
      case 15: // EQ
      case 16: // AND
      case 17: // OR
      case 18: // GT
      case 19: // LT
      case 20: // CLASS
      case 21: // STATIC
      case 22: // VOID
      case 23: // MAIN
      case 24: // PUBLIC
      case 25: // RETURN
      case 26: // PERIOD
      case 27: // COMMA
      case 28: // EXCLAMATION
      case 29: // SEMICOLON
      case 30: // INTTYPE
      case 31: // BOOLTYPE
      case 32: // STRING
      case 33: // IF
      case 34: // ELSE
      case 35: // WHILE
      case 36: // NEW
      case 37: // LENGTH
      case 38: // PRINT
      case 39: // IDENTIFIER
      case 40: // TRUE
      case 41: // FALSE
      case 42: // THIS
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
    switch (that.type_get ())
    {
      case 45: // root
      case 46: // goal
      case 47: // mainclass
      case 48: // classdeclaration
      case 49: // classdeclarations
      case 50: // methoddeclaration
      case 51: // methoddeclarations
      case 52: // methodbody
      case 53: // vardeclaration
      case 54: // vardeclarations
      case 55: // parameters
      case 56: // type
      case 57: // statement
      case 58: // statements
      case 59: // stmt_if
      case 60: // expression
      case 61: // experiment
      case 62: // exprlist
      case 63: // factor
      case 64: // identifier
        value.move< Node * > (that.value);
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // DIVOP
      case 7: // INT
      case 8: // LP
      case 9: // RP
      case 10: // LHB
      case 11: // RHB
      case 12: // LCB
      case 13: // RCB
      case 14: // ASSIGN
      case 15: // EQ
      case 16: // AND
      case 17: // OR
      case 18: // GT
      case 19: // LT
      case 20: // CLASS
      case 21: // STATIC
      case 22: // VOID
      case 23: // MAIN
      case 24: // PUBLIC
      case 25: // RETURN
      case 26: // PERIOD
      case 27: // COMMA
      case 28: // EXCLAMATION
      case 29: // SEMICOLON
      case 30: // INTTYPE
      case 31: // BOOLTYPE
      case 32: // STRING
      case 33: // IF
      case 34: // ELSE
      case 35: // WHILE
      case 36: // NEW
      case 37: // LENGTH
      case 38: // PRINT
      case 39: // IDENTIFIER
      case 40: // TRUE
      case 41: // FALSE
      case 42: // THIS
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
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
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
  parser::yypop_ (int n)
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
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
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
        YYCDEBUG << "Reading a token: ";
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

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
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
      case 45: // root
      case 46: // goal
      case 47: // mainclass
      case 48: // classdeclaration
      case 49: // classdeclarations
      case 50: // methoddeclaration
      case 51: // methoddeclarations
      case 52: // methodbody
      case 53: // vardeclaration
      case 54: // vardeclarations
      case 55: // parameters
      case 56: // type
      case 57: // statement
      case 58: // statements
      case 59: // stmt_if
      case 60: // expression
      case 61: // experiment
      case 62: // exprlist
      case 63: // factor
      case 64: // identifier
        yylhs.value.emplace< Node * > ();
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // DIVOP
      case 7: // INT
      case 8: // LP
      case 9: // RP
      case 10: // LHB
      case 11: // RHB
      case 12: // LCB
      case 13: // RCB
      case 14: // ASSIGN
      case 15: // EQ
      case 16: // AND
      case 17: // OR
      case 18: // GT
      case 19: // LT
      case 20: // CLASS
      case 21: // STATIC
      case 22: // VOID
      case 23: // MAIN
      case 24: // PUBLIC
      case 25: // RETURN
      case 26: // PERIOD
      case 27: // COMMA
      case 28: // EXCLAMATION
      case 29: // SEMICOLON
      case 30: // INTTYPE
      case 31: // BOOLTYPE
      case 32: // STRING
      case 33: // IF
      case 34: // ELSE
      case 35: // WHILE
      case 36: // NEW
      case 37: // LENGTH
      case 38: // PRINT
      case 39: // IDENTIFIER
      case 40: // TRUE
      case 41: // FALSE
      case 42: // THIS
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
  case 2:
#line 50 "parser.y"
                   {
                      root = yystack_[0].value.as < Node * > ();
              }
#line 873 "parser.tab.c"
    break;

  case 3:
#line 56 "parser.y"
                                                    {
                      yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      printf("goaln: %d\n", yylineno);
              }
#line 884 "parser.tab.c"
    break;

  case 4:
#line 64 "parser.y"
                                                                                                                 {
                      yylhs.value.as < Node * > () = new Node("MainClass", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[14].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                      printf("main, %d\n", yylineno);
              }
#line 896 "parser.tab.c"
    break;

  case 5:
#line 73 "parser.y"
                                                                              {
                      yylhs.value.as < Node * > () = new Node("classDeclaration", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              }
#line 907 "parser.tab.c"
    break;

  case 6:
#line 81 "parser.y"
                               {
                      yylhs.value.as < Node * > () = nullptr;
            }
#line 915 "parser.tab.c"
    break;

  case 7:
#line 84 "parser.y"
                                                 {
                      yylhs.value.as < Node * > () = new Node("ClassDeclarations", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 925 "parser.tab.c"
    break;

  case 8:
#line 91 "parser.y"
                                                                                                          {
                      yylhs.value.as < Node * > () = new Node("Method", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ()); // type
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ()); // identifier
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ()); // param
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); // method body
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // return expression
              }
#line 938 "parser.tab.c"
    break;

  case 9:
#line 102 "parser.y"
                        { 
                      yylhs.value.as < Node * > () = nullptr; 
            }
#line 946 "parser.tab.c"
    break;

  case 10:
#line 105 "parser.y"
                                                   {
                      yylhs.value.as < Node * > () = new Node("MethodDeclarations", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 956 "parser.tab.c"
    break;

  case 11:
#line 112 "parser.y"
                        {
                      yylhs.value.as < Node * > () = nullptr;
            }
#line 964 "parser.tab.c"
    break;

  case 12:
#line 115 "parser.y"
                                        {
                      yylhs.value.as < Node * > () = new Node("MethodVariable", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 974 "parser.tab.c"
    break;

  case 13:
#line 120 "parser.y"
                                   {
                      yylhs.value.as < Node * > () = new Node("MethodStatement", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 984 "parser.tab.c"
    break;

  case 14:
#line 127 "parser.y"
                                          {
                      yylhs.value.as < Node * > () = new Node("Variable", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // type
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // identifier
              }
#line 994 "parser.tab.c"
    break;

  case 15:
#line 133 "parser.y"
                             {
                      yylhs.value.as < Node * > () = nullptr;
            }
#line 1002 "parser.tab.c"
    break;

  case 16:
#line 136 "parser.y"
                                             {
                      yylhs.value.as < Node * > () = new Node("Variables", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1012 "parser.tab.c"
    break;

  case 17:
#line 143 "parser.y"
                        {
                      yylhs.value.as < Node * > () = nullptr;
            }
#line 1020 "parser.tab.c"
    break;

  case 18:
#line 146 "parser.y"
                              {
                      yylhs.value.as < Node * > () = new Node("Parameter", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // type
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // identifier
            }
#line 1030 "parser.tab.c"
    break;

  case 19:
#line 151 "parser.y"
                                               {
                      yylhs.value.as < Node * > () = new Node("Parameters", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); // type
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // identifier
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // undef nr of prams
            }
#line 1041 "parser.tab.c"
    break;

  case 20:
#line 159 "parser.y"
                      {
            yylhs.value.as < Node * > () = new Node("ArrayType", "", yylineno);
              }
#line 1049 "parser.tab.c"
    break;

  case 21:
#line 162 "parser.y"
                 {
            yylhs.value.as < Node * > () =  new Node("BoolType", "", yylineno);
              }
#line 1057 "parser.tab.c"
    break;

  case 22:
#line 165 "parser.y"
                {
            yylhs.value.as < Node * > () = new Node("IntType", "", yylineno);
              }
#line 1065 "parser.tab.c"
    break;

  case 23:
#line 168 "parser.y"
                   {
            yylhs.value.as < Node * > () = new Node("IdentifierType", "", yylineno);
              }
#line 1073 "parser.tab.c"
    break;

  case 24:
#line 174 "parser.y"
                                { 
              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
            }
#line 1081 "parser.tab.c"
    break;

  case 25:
#line 177 "parser.y"
              { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1087 "parser.tab.c"
    break;

  case 26:
#line 178 "parser.y"
                                               {
              yylhs.value.as < Node * > () = new Node("While", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1097 "parser.tab.c"
    break;

  case 27:
#line 183 "parser.y"
                                               {
              yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1106 "parser.tab.c"
    break;

  case 28:
#line 187 "parser.y"
                                                     {
              yylhs.value.as < Node * > () = new Node("Assign", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1116 "parser.tab.c"
    break;

  case 29:
#line 192 "parser.y"
                                                                        {
              yylhs.value.as < Node * > () = new Node("indexAssign", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1127 "parser.tab.c"
    break;

  case 30:
#line 200 "parser.y"
                        {
              yylhs.value.as < Node * > () = nullptr;
            }
#line 1135 "parser.tab.c"
    break;

  case 31:
#line 203 "parser.y"
                                   { 
              yylhs.value.as < Node * > () = new Node("Statements", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 1145 "parser.tab.c"
    break;

  case 32:
#line 210 "parser.y"
                                                     { // To solve dangling else ambiguity
              yylhs.value.as < Node * > () = new Node("IF", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1155 "parser.tab.c"
    break;

  case 33:
#line 215 "parser.y"
                                                           {
              yylhs.value.as < Node * > () = new Node("IfElse", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1166 "parser.tab.c"
    break;

  case 34:
#line 223 "parser.y"
                                         {      
                            yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r1 "); */
                          }
#line 1177 "parser.tab.c"
    break;

  case 35:
#line 229 "parser.y"
                                            {
                            yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r2 "); */
                          }
#line 1188 "parser.tab.c"
    break;

  case 36:
#line 235 "parser.y"
                                           {
                            yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r3 "); */
                          }
#line 1199 "parser.tab.c"
    break;

  case 37:
#line 241 "parser.y"
                                          {
                            yylhs.value.as < Node * > () = new Node("DivExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r3 "); */
                          }
#line 1210 "parser.tab.c"
    break;

  case 38:
#line 247 "parser.y"
                                           {
                            yylhs.value.as < Node * > () = new Node("Assigning", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1220 "parser.tab.c"
    break;

  case 39:
#line 252 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("GreaterThan", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1230 "parser.tab.c"
    break;

  case 40:
#line 257 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("LessThan", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1240 "parser.tab.c"
    break;

  case 41:
#line 262 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("Equals", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1250 "parser.tab.c"
    break;

  case 42:
#line 267 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("OR", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1260 "parser.tab.c"
    break;

  case 43:
#line 272 "parser.y"
                                        {
                            yylhs.value.as < Node * > () = new Node("AND", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1270 "parser.tab.c"
    break;

  case 44:
#line 278 "parser.y"
              { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1276 "parser.tab.c"
    break;

  case 45:
#line 280 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("LenghtOfExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            printf("LEN: %d\n", yylineno);
                          }
#line 1286 "parser.tab.c"
    break;

  case 46:
#line 285 "parser.y"
                                                          {  // recursive grammar, follows recursive rules
                              yylhs.value.as < Node * > () = new Node("Method call", "", yylineno);
                              printf("expression.ID(exprls): %d\n", yylineno);
                          }
#line 1295 "parser.tab.c"
    break;

  case 47:
#line 289 "parser.y"
                                                 {  // for the empty case
                              yylhs.value.as < Node * > () = new Node("Method call", "", yylineno);
                              printf("expression.ID(): %d\n", yylineno);
                          }
#line 1304 "parser.tab.c"
    break;

  case 48:
#line 293 "parser.y"
                   {
                  yylhs.value.as < Node * > () = new Node("True", "", yylineno);
                }
#line 1312 "parser.tab.c"
    break;

  case 49:
#line 296 "parser.y"
                    {
                  yylhs.value.as < Node * > () = new Node("False", "", yylineno);
                }
#line 1320 "parser.tab.c"
    break;

  case 50:
#line 299 "parser.y"
                         {
                  yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                }
#line 1328 "parser.tab.c"
    break;

  case 51:
#line 302 "parser.y"
                    {
                  yylhs.value.as < Node * > () = new Node("This", "", yylineno);
                }
#line 1336 "parser.tab.c"
    break;

  case 52:
#line 305 "parser.y"
                                             {
                      yylhs.value.as < Node * > () = new Node("AllocateIntArray", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // Size of int array
                  }
#line 1345 "parser.tab.c"
    break;

  case 53:
#line 309 "parser.y"
                                   {
                      yylhs.value.as < Node * > () = new Node("AllocateIdentifier", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());  
                      printf("NEW ident: %d\n", yylineno);
                  }
#line 1355 "parser.tab.c"
    break;

  case 54:
#line 314 "parser.y"
                                     {
                      yylhs.value.as < Node * > () = new Node("Negation", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
                  }
#line 1364 "parser.tab.c"
    break;

  case 55:
#line 318 "parser.y"
                          {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); /* printf("r4 ");*/}
#line 1370 "parser.tab.c"
    break;

  case 56:
#line 321 "parser.y"
                                          { //??
                      yylhs.value.as < Node * > () = new Node("Index", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());  // what to take index of
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // index value
                  }
#line 1380 "parser.tab.c"
    break;

  case 57:
#line 328 "parser.y"
                     {
                      yylhs.value.as < Node * > () = new Node("Expression", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                  }
#line 1389 "parser.tab.c"
    break;

  case 58:
#line 332 "parser.y"
                                        {
                      yylhs.value.as < Node * > () = new Node("ExpressionList", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                  }
#line 1399 "parser.tab.c"
    break;

  case 59:
#line 340 "parser.y"
            {
                      yylhs.value.as < Node * > () = new Node("Int", yystack_[0].value.as < std::string > (), yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
#line 1406 "parser.tab.c"
    break;

  case 60:
#line 342 "parser.y"
                               { 
                      yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); /* printf("r6 ");  simply return the expression */
                  }
#line 1414 "parser.tab.c"
    break;

  case 61:
#line 347 "parser.y"
                       {
                    yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno); 
            }
#line 1422 "parser.tab.c"
    break;


#line 1426 "parser.tab.c"

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
      YY_STACK_PRINT ();

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
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
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

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

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
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

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
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -53;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -16,    16,    19,   -53,    22,    11,   -53,    31,   -53,    50,
      11,    31,    59,    39,    57,   -53,    72,    52,   -53,   -53,
      53,    35,    64,    66,   -53,    -9,   -53,    11,   -53,    82,
      81,   -53,    35,   -53,    65,    67,   -53,    11,   -53,    88,
      92,    91,    35,    11,   108,    11,   110,   111,    93,   117,
     -53,    35,    83,    58,   -53,   -53,   123,   126,   127,   129,
     -53,    -1,    13,   -53,   -53,    -1,   -10,    13,    13,    13,
     -53,    13,    13,   -53,    13,    13,    28,   -53,   -53,   -53,
     122,   -53,   -53,   -53,   -53,   -53,   184,   202,   220,   237,
     149,   255,   104,   134,   137,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    -4,   133,    83,    83,
     120,   136,   -53,   -53,    13,   147,    54,    54,     8,     8,
     272,   306,   340,   323,   323,   350,   350,   -53,   150,   -53,
     128,   -53,   -53,    13,   289,   -53,   -53,     3,    83,   166,
     -53,   -53,   306,    -3,   -53,   -53,   -53,    13,   306
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     0,     1,     6,    61,     0,
       0,     6,     0,     0,     0,     7,     0,     0,    15,     3,
       0,     9,     0,    22,    21,     0,    16,     0,    23,     0,
       0,     5,     0,    10,     0,     0,    20,     0,    14,     0,
       0,     0,    17,     0,     0,     0,     0,     0,    18,     0,
      11,    17,     0,     0,    19,    30,     0,     0,     0,     0,
      25,     0,     0,    12,    13,    23,     0,     0,     0,     0,
       4,     0,     0,    59,     0,     0,     0,    48,    49,    51,
       0,    44,    55,    50,    24,    31,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    60,     0,     0,    34,    35,    36,    37,
       0,    38,    41,    43,    42,    39,    40,    45,     0,     8,
      32,    26,    27,     0,     0,    53,    56,     0,     0,     0,
      52,    47,    57,     0,    33,    29,    46,     0,    58
  };

  const short
  parser::yypgoto_[] =
  {
     -53,   -53,   -53,   -53,   -53,   162,   -53,   -53,   -53,   107,
     -53,   135,   -25,   -52,   -53,   -53,    10,   -53,   -53,   -53,
      -5
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    11,    12,    33,    25,    53,    26,
      21,    44,    27,    59,    66,    60,    80,    81,   143,    82,
      83
  };

  const unsigned char
  parser::yytable_[] =
  {
       9,    64,    55,    84,    31,    14,   146,    37,     1,    71,
      73,    74,   141,    72,    85,    32,    28,    45,    99,     6,
      73,    74,    34,    56,   147,    57,    45,    28,    58,     8,
       7,    75,    40,   127,   106,     8,     5,    28,    46,    76,
      48,    75,     8,    77,    78,    79,    28,    61,    65,    76,
       8,    10,     8,    77,    78,    79,   130,   131,    93,    97,
      98,    61,    13,    17,    99,    23,    24,     8,    16,    18,
      55,    94,    19,    20,     8,    22,    30,    86,    87,    88,
     106,    89,    90,    62,    91,    92,   144,    29,    23,    24,
      35,    56,    36,    57,    38,    55,    58,     8,    41,    39,
      42,   128,    43,    61,    61,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    56,    47,    57,    49,
      51,    58,     8,    50,   134,    95,    96,    97,    98,    52,
     106,    67,    99,    61,    68,    69,   100,   101,   102,   103,
     104,   105,    70,   139,   114,   115,   129,   142,   106,   132,
     133,   107,    95,    96,    97,    98,   135,   148,   137,    99,
      63,     0,   138,   100,   101,   102,   103,   104,   105,    95,
      96,    97,    98,    15,     0,   106,    99,     0,   112,     0,
     100,   101,   102,   103,   104,   105,    54,    95,    96,    97,
      98,     0,   106,   108,    99,   145,     0,     0,   100,   101,
     102,   103,   104,   105,     0,    95,    96,    97,    98,     0,
     106,   109,    99,     0,     0,     0,   100,   101,   102,   103,
     104,   105,     0,    95,    96,    97,    98,     0,   106,   110,
      99,     0,     0,     0,   100,   101,   102,   103,   104,   105,
      95,    96,    97,    98,     0,     0,   106,    99,   111,     0,
       0,   100,   101,   102,   103,   104,   105,     0,    95,    96,
      97,    98,     0,   106,   113,    99,     0,     0,     0,   100,
     101,   102,   103,   104,   105,    95,    96,    97,    98,     0,
       0,   106,    99,   136,     0,     0,   100,   101,   102,   103,
     104,   105,    95,    96,    97,    98,     0,     0,   106,    99,
     140,     0,     0,   100,   101,   102,   103,   104,   105,    95,
      96,    97,    98,     0,     0,   106,    99,     0,     0,     0,
     100,   101,   102,   103,   104,   105,    95,    96,    97,    98,
       0,     0,   106,    99,     0,     0,     0,     0,   101,     0,
       0,   104,   105,    95,    96,    97,    98,     0,     0,   106,
      99,     0,     0,    95,    96,    97,    98,     0,   104,   105,
      99,     0,     0,     0,     0,     0,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106
  };

  const short
  parser::yycheck_[] =
  {
       5,    53,    12,    13,    13,    10,     9,    32,    24,    10,
       7,     8,     9,    14,    66,    24,    21,    42,    10,     0,
       7,     8,    27,    33,    27,    35,    51,    32,    38,    39,
       8,    28,    37,    37,    26,    39,    20,    42,    43,    36,
      45,    28,    39,    40,    41,    42,    51,    52,    53,    36,
      39,    20,    39,    40,    41,    42,   108,   109,    30,     5,
       6,    66,    12,    24,    10,    30,    31,    39,     9,    12,
      12,    76,     0,    21,    39,    22,    10,    67,    68,    69,
      26,    71,    72,    25,    74,    75,   138,    23,    30,    31,
       8,    33,    11,    35,    29,    12,    38,    39,    10,    32,
       8,   106,    11,   108,   109,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    33,     9,    35,     9,
      27,    38,    39,    12,   114,     3,     4,     5,     6,    12,
      26,     8,    10,   138,     8,     8,    14,    15,    16,    17,
      18,    19,    13,   133,    10,     8,    13,   137,    26,    29,
      14,    29,     3,     4,     5,     6,     9,   147,     8,    10,
      53,    -1,    34,    14,    15,    16,    17,    18,    19,     3,
       4,     5,     6,    11,    -1,    26,    10,    -1,    29,    -1,
      14,    15,    16,    17,    18,    19,    51,     3,     4,     5,
       6,    -1,    26,     9,    10,    29,    -1,    -1,    14,    15,
      16,    17,    18,    19,    -1,     3,     4,     5,     6,    -1,
      26,     9,    10,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    -1,     3,     4,     5,     6,    -1,    26,     9,
      10,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
       3,     4,     5,     6,    -1,    -1,    26,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    -1,     3,     4,
       5,     6,    -1,    26,     9,    10,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,     3,     4,     5,     6,    -1,
      -1,    26,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,     3,     4,     5,     6,    -1,    -1,    26,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,     3,
       4,     5,     6,    -1,    -1,    26,    10,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,     3,     4,     5,     6,
      -1,    -1,    26,    10,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    18,    19,     3,     4,     5,     6,    -1,    -1,    26,
      10,    -1,    -1,     3,     4,     5,     6,    -1,    18,    19,
      10,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26
  };

  const signed char
  parser::yystos_[] =
  {
       0,    24,    45,    46,    47,    20,     0,     8,    39,    64,
      20,    48,    49,    12,    64,    49,     9,    24,    12,     0,
      21,    54,    22,    30,    31,    51,    53,    56,    64,    23,
      10,    13,    24,    50,    64,     8,    11,    56,    29,    32,
      64,    10,     8,    11,    55,    56,    64,     9,    64,     9,
      12,    27,    12,    52,    55,    12,    33,    35,    38,    57,
      59,    64,    25,    53,    57,    64,    58,     8,     8,     8,
      13,    10,    14,     7,     8,    28,    36,    40,    41,    42,
      60,    61,    63,    64,    13,    57,    60,    60,    60,    60,
      60,    60,    60,    30,    64,     3,     4,     5,     6,    10,
      14,    15,    16,    17,    18,    19,    26,    29,     9,     9,
       9,    11,    29,     9,    10,     8,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    37,    64,    13,
      57,    57,    29,    14,    60,     9,    11,     8,    34,    60,
      11,     9,    60,    62,    57,    29,     9,    27,    60
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    45,    46,    47,    48,    49,    49,    50,    51,
      51,    52,    52,    52,    53,    54,    54,    55,    55,    55,
      56,    56,    56,    56,    57,    57,    57,    57,    57,    57,
      58,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    62,    62,    63,
      63,    64
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     5,    17,     6,     0,     2,    12,     0,
       2,     0,     2,     2,     3,     0,     2,     0,     2,     4,
       3,     1,     1,     1,     3,     1,     5,     5,     4,     7,
       0,     2,     5,     7,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     6,     5,     1,     1,
       1,     1,     5,     4,     2,     1,     4,     1,     3,     1,
       3,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "PLUSOP", "MINUSOP", "MULTOP",
  "DIVOP", "INT", "LP", "RP", "LHB", "RHB", "LCB", "RCB", "ASSIGN", "EQ",
  "AND", "OR", "GT", "LT", "CLASS", "STATIC", "VOID", "MAIN", "PUBLIC",
  "RETURN", "PERIOD", "COMMA", "EXCLAMATION", "SEMICOLON", "INTTYPE",
  "BOOLTYPE", "STRING", "IF", "ELSE", "WHILE", "NEW", "LENGTH", "PRINT",
  "IDENTIFIER", "TRUE", "FALSE", "THIS", "NO_ELSE", "$accept", "root",
  "goal", "mainclass", "classdeclaration", "classdeclarations",
  "methoddeclaration", "methoddeclarations", "methodbody",
  "vardeclaration", "vardeclarations", "parameters", "type", "statement",
  "statements", "stmt_if", "expression", "experiment", "exprlist",
  "factor", "identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    50,    50,    56,    64,    73,    81,    84,    91,   102,
     105,   112,   115,   120,   127,   133,   136,   143,   146,   151,
     159,   162,   165,   168,   174,   177,   178,   183,   187,   192,
     200,   203,   210,   215,   223,   229,   235,   241,   247,   252,
     257,   262,   267,   272,   278,   280,   285,   289,   293,   296,
     299,   302,   305,   309,   314,   318,   321,   328,   332,   340,
     342,   347
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
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
#line 1947 "parser.tab.c"

