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
      case 46: // root
      case 47: // mainclass
      case 48: // statement
      case 49: // statements
      case 50: // expression
      case 51: // factor
      case 52: // identifier
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
      case 25: // COMMENT
      case 26: // RETURN
      case 27: // PERIOD
      case 28: // COMMA
      case 29: // EXCLAMATION
      case 30: // SEMICOLON
      case 31: // INTTYPE
      case 32: // BOOLTYPE
      case 33: // STRING
      case 34: // IF
      case 35: // ELSE
      case 36: // WHILE
      case 37: // NEW
      case 38: // LENGTH
      case 39: // PRINT
      case 40: // IDENTIFIER
      case 41: // TRUE
      case 42: // FALSE
      case 43: // THIS
      case 44: // STATEMENT
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
      case 46: // root
      case 47: // mainclass
      case 48: // statement
      case 49: // statements
      case 50: // expression
      case 51: // factor
      case 52: // identifier
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
      case 25: // COMMENT
      case 26: // RETURN
      case 27: // PERIOD
      case 28: // COMMA
      case 29: // EXCLAMATION
      case 30: // SEMICOLON
      case 31: // INTTYPE
      case 32: // BOOLTYPE
      case 33: // STRING
      case 34: // IF
      case 35: // ELSE
      case 36: // WHILE
      case 37: // NEW
      case 38: // LENGTH
      case 39: // PRINT
      case 40: // IDENTIFIER
      case 41: // TRUE
      case 42: // FALSE
      case 43: // THIS
      case 44: // STATEMENT
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
      case 46: // root
      case 47: // mainclass
      case 48: // statement
      case 49: // statements
      case 50: // expression
      case 51: // factor
      case 52: // identifier
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
      case 25: // COMMENT
      case 26: // RETURN
      case 27: // PERIOD
      case 28: // COMMA
      case 29: // EXCLAMATION
      case 30: // SEMICOLON
      case 31: // INTTYPE
      case 32: // BOOLTYPE
      case 33: // STRING
      case 34: // IF
      case 35: // ELSE
      case 36: // WHILE
      case 37: // NEW
      case 38: // LENGTH
      case 39: // PRINT
      case 40: // IDENTIFIER
      case 41: // TRUE
      case 42: // FALSE
      case 43: // THIS
      case 44: // STATEMENT
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
      case 46: // root
      case 47: // mainclass
      case 48: // statement
      case 49: // statements
      case 50: // expression
      case 51: // factor
      case 52: // identifier
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
      case 25: // COMMENT
      case 26: // RETURN
      case 27: // PERIOD
      case 28: // COMMA
      case 29: // EXCLAMATION
      case 30: // SEMICOLON
      case 31: // INTTYPE
      case 32: // BOOLTYPE
      case 33: // STRING
      case 34: // IF
      case 35: // ELSE
      case 36: // WHILE
      case 37: // NEW
      case 38: // LENGTH
      case 39: // PRINT
      case 40: // IDENTIFIER
      case 41: // TRUE
      case 42: // FALSE
      case 43: // THIS
      case 44: // STATEMENT
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
      case 46: // root
      case 47: // mainclass
      case 48: // statement
      case 49: // statements
      case 50: // expression
      case 51: // factor
      case 52: // identifier
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
      case 25: // COMMENT
      case 26: // RETURN
      case 27: // PERIOD
      case 28: // COMMA
      case 29: // EXCLAMATION
      case 30: // SEMICOLON
      case 31: // INTTYPE
      case 32: // BOOLTYPE
      case 33: // STRING
      case 34: // IF
      case 35: // ELSE
      case 36: // WHILE
      case 37: // NEW
      case 38: // LENGTH
      case 39: // PRINT
      case 40: // IDENTIFIER
      case 41: // TRUE
      case 42: // FALSE
      case 43: // THIS
      case 44: // STATEMENT
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
#line 42 "parser.y"
                      {root = yystack_[0].value.as < Node * > ();}
#line 816 "parser.tab.c"
    break;

  case 3:
#line 44 "parser.y"
                                                                                                                     {
                      yylhs.value.as < Node * > () = new Node("MainClass", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              }
#line 827 "parser.tab.c"
    break;

  case 5:
#line 146 "parser.y"
                                 { 
              yylhs.value.as < Node * > () = new Node("Statements", "", yylineno);
            }
#line 835 "parser.tab.c"
    break;

  case 6:
#line 149 "parser.y"
                                            {
              yylhs.value.as < Node * > () = new Node("IF", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 845 "parser.tab.c"
    break;

  case 7:
#line 154 "parser.y"
                                                           {
              yylhs.value.as < Node * > () = new Node("IfElse", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 856 "parser.tab.c"
    break;

  case 8:
#line 160 "parser.y"
                                               {
              yylhs.value.as < Node * > () = new Node("While", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 866 "parser.tab.c"
    break;

  case 9:
#line 165 "parser.y"
                                               {
              yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 875 "parser.tab.c"
    break;

  case 10:
#line 169 "parser.y"
                                                     {
              yylhs.value.as < Node * > () = new Node("Assign", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 885 "parser.tab.c"
    break;

  case 11:
#line 174 "parser.y"
                                                                        {
              yylhs.value.as < Node * > () = new Node("indexAssign", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 896 "parser.tab.c"
    break;

  case 13:
#line 184 "parser.y"
                                   { 
              yylhs.value.as < Node * > () = new Node("Statements", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

            }
#line 907 "parser.tab.c"
    break;

  case 14:
#line 193 "parser.y"
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
#line 922 "parser.tab.c"
    break;

  case 15:
#line 203 "parser.y"
                                            {
                            yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r2 "); */
                          }
#line 933 "parser.tab.c"
    break;

  case 16:
#line 209 "parser.y"
                                           {
                            yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r3 "); */
                          }
#line 944 "parser.tab.c"
    break;

  case 17:
#line 215 "parser.y"
                                          {
                            yylhs.value.as < Node * > () = new Node("DivExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r3 "); */
                          }
#line 955 "parser.tab.c"
    break;

  case 18:
#line 221 "parser.y"
                                           {
                            yylhs.value.as < Node * > () = new Node("Assigning", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 965 "parser.tab.c"
    break;

  case 19:
#line 226 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("GreaterThan", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 975 "parser.tab.c"
    break;

  case 20:
#line 231 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("LessThan", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 985 "parser.tab.c"
    break;

  case 21:
#line 236 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("Equals", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 995 "parser.tab.c"
    break;

  case 22:
#line 241 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("OR", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1005 "parser.tab.c"
    break;

  case 23:
#line 246 "parser.y"
                                        {
                            yylhs.value.as < Node * > () = new Node("AND", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());                            
                          }
#line 1015 "parser.tab.c"
    break;

  case 24:
#line 252 "parser.y"
                                            {
                            yylhs.value.as < Node * > () = new Node("Index", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());  // what to take index of
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // index value
                          }
#line 1025 "parser.tab.c"
    break;

  case 25:
#line 257 "parser.y"
                                       {
                            yylhs.value.as < Node * > () = new Node("LenghtOfExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          }
#line 1034 "parser.tab.c"
    break;

  case 26:
#line 261 "parser.y"
                                                                             {
                              // TODO
                          }
#line 1042 "parser.tab.c"
    break;

  case 27:
#line 265 "parser.y"
                   {
                  yylhs.value.as < Node * > () = new Node("True", "", yylineno);
                }
#line 1050 "parser.tab.c"
    break;

  case 28:
#line 268 "parser.y"
                    {
                  yylhs.value.as < Node * > () = new Node("False", "", yylineno);
                }
#line 1058 "parser.tab.c"
    break;

  case 29:
#line 271 "parser.y"
                         {
                  yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                }
#line 1066 "parser.tab.c"
    break;

  case 30:
#line 274 "parser.y"
                    {
                  yylhs.value.as < Node * > () = new Node("This", "", yylineno);
                }
#line 1074 "parser.tab.c"
    break;

  case 31:
#line 277 "parser.y"
                                             {
                      yylhs.value.as < Node * > () = new Node("AllocateIntArray", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // Size of int array
                  }
#line 1083 "parser.tab.c"
    break;

  case 32:
#line 281 "parser.y"
                                   {
                      yylhs.value.as < Node * > () = new Node("AllocateIdentifier", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());  
                  }
#line 1092 "parser.tab.c"
    break;

  case 33:
#line 285 "parser.y"
                                     {
                      yylhs.value.as < Node * > () = new Node("Negation", "", yylineno);
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
                  }
#line 1101 "parser.tab.c"
    break;

  case 34:
#line 289 "parser.y"
                          {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); /* printf("r4 ");*/}
#line 1107 "parser.tab.c"
    break;

  case 35:
#line 293 "parser.y"
                          {  yylhs.value.as < Node * > () = new Node("Int", yystack_[0].value.as < std::string > (), yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
#line 1113 "parser.tab.c"
    break;

  case 36:
#line 294 "parser.y"
                               { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); /* printf("r6 ");  simply return the expression */}
#line 1119 "parser.tab.c"
    break;

  case 37:
#line 297 "parser.y"
                       {
                    yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno); // Here we create a leaf node Int. The value of the leaf node is $1 
                          }
#line 1127 "parser.tab.c"
    break;


#line 1131 "parser.tab.c"

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


  const signed char parser::yypact_ninf_ = -33;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -17,    -3,    20,   -33,   -24,   -33,   -33,     9,     2,     7,
      11,     6,    24,     3,    27,    29,   -24,    36,    37,    56,
     -33,    40,    42,    43,    47,    -5,    -9,    16,    16,    16,
      48,    16,    16,   -33,   -33,   -33,    16,    16,   -30,   -33,
     -33,   -33,   154,   -33,   -33,   173,   192,   -33,   210,    98,
     229,   302,    45,    68,    16,    16,    16,    16,    56,    16,
      16,    16,    16,    16,    16,    16,   -32,    56,    49,    63,
     -33,   -33,    16,    71,     8,     8,    -8,    -8,    46,   247,
     320,   356,   338,   338,   366,   366,   -33,    75,   -33,   -33,
      16,   265,   -33,    56,   -33,    16,   116,   -33,   -33,   134,
     -33,    16,   284,   -33
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     1,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,    13,    35,     0,     0,     0,    27,
      28,    30,     0,    34,    29,     0,     0,     3,     0,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     0,
      10,    36,     0,     0,    14,    15,    16,    17,     6,     0,
      18,    21,    23,    22,    19,    20,    25,     0,     8,     9,
       0,     0,    32,     4,    24,     0,     0,    31,     7,     0,
      11,     0,     0,    26
  };

  const signed char
  parser::yypgoto_[] =
  {
     -33,   -33,   -33,   -15,   -33,    10,   -33,    -4
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,    24,    26,    42,    43,    44
  };

  const signed char
  parser::yytable_[] =
  {
       7,    52,    59,    20,    33,    31,    86,     1,     6,    32,
       6,    34,    17,    56,    57,    25,     6,     4,    59,    66,
       5,     8,    25,    35,    36,    21,     9,    22,    10,    12,
      23,     6,    13,    11,    53,    66,    14,    15,    45,    46,
      16,    48,    49,    78,    18,    37,    50,    51,    27,    19,
      28,    29,    88,    38,    25,    72,     6,    39,    40,    41,
      30,    47,    87,    25,    74,    75,    76,    77,    20,    79,
      80,    81,    82,    83,    84,    85,    73,    90,    98,    89,
      92,    93,    91,    95,     0,     0,     0,     0,     0,    25,
      21,     0,    22,     0,     0,    23,     6,     0,     0,     0,
      96,    54,    55,    56,    57,    99,     0,     0,    59,     0,
       0,   102,    60,    61,    62,    63,    64,    65,     0,    54,
      55,    56,    57,     0,     0,    66,    59,     0,    70,     0,
      60,    61,    62,    63,    64,    65,     0,    54,    55,    56,
      57,     0,     0,    66,    59,     0,   100,     0,    60,    61,
      62,    63,    64,    65,     0,     0,     0,    54,    55,    56,
      57,    66,   101,    58,    59,     0,     0,     0,    60,    61,
      62,    63,    64,    65,     0,     0,    54,    55,    56,    57,
       0,    66,    67,    59,     0,     0,     0,    60,    61,    62,
      63,    64,    65,     0,     0,    54,    55,    56,    57,     0,
      66,    68,    59,     0,     0,     0,    60,    61,    62,    63,
      64,    65,     0,    54,    55,    56,    57,     0,     0,    66,
      59,    69,     0,     0,    60,    61,    62,    63,    64,    65,
       0,     0,    54,    55,    56,    57,     0,    66,    71,    59,
       0,     0,     0,    60,    61,    62,    63,    64,    65,     0,
      54,    55,    56,    57,     0,     0,    66,    59,    94,     0,
       0,    60,    61,    62,    63,    64,    65,     0,    54,    55,
      56,    57,     0,     0,    66,    59,    97,     0,     0,    60,
      61,    62,    63,    64,    65,     0,     0,    54,    55,    56,
      57,     0,    66,   103,    59,     0,     0,     0,    60,    61,
      62,    63,    64,    65,     0,    54,    55,    56,    57,     0,
       0,    66,    59,     0,     0,     0,    60,    61,    62,    63,
      64,    65,     0,    54,    55,    56,    57,     0,     0,    66,
      59,     0,     0,     0,     0,    61,    62,    63,    64,    65,
       0,    54,    55,    56,    57,     0,     0,    66,    59,     0,
       0,     0,     0,    61,     0,     0,    64,    65,     0,    54,
      55,    56,    57,     0,     0,    66,    59,     0,     0,    54,
      55,    56,    57,     0,    64,    65,    59,     0,     0,     0,
       0,     0,     0,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66
  };

  const signed char
  parser::yycheck_[] =
  {
       4,    31,    10,    12,    13,    10,    38,    24,    40,    14,
      40,    26,    16,     5,     6,    19,    40,    20,    10,    27,
       0,    12,    26,     7,     8,    34,    24,    36,    21,    23,
      39,    40,     8,    22,    38,    27,    33,    10,    28,    29,
      11,    31,    32,    58,     8,    29,    36,    37,     8,    12,
       8,     8,    67,    37,    58,    10,    40,    41,    42,    43,
      13,    13,    66,    67,    54,    55,    56,    57,    12,    59,
      60,    61,    62,    63,    64,    65,     8,    14,    93,    30,
       9,    35,    72,     8,    -1,    -1,    -1,    -1,    -1,    93,
      34,    -1,    36,    -1,    -1,    39,    40,    -1,    -1,    -1,
      90,     3,     4,     5,     6,    95,    -1,    -1,    10,    -1,
      -1,   101,    14,    15,    16,    17,    18,    19,    -1,     3,
       4,     5,     6,    -1,    -1,    27,    10,    -1,    30,    -1,
      14,    15,    16,    17,    18,    19,    -1,     3,     4,     5,
       6,    -1,    -1,    27,    10,    -1,    30,    -1,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,     3,     4,     5,
       6,    27,    28,     9,    10,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    -1,    -1,     3,     4,     5,     6,
      -1,    27,     9,    10,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    19,    -1,    -1,     3,     4,     5,     6,    -1,
      27,     9,    10,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    -1,     3,     4,     5,     6,    -1,    -1,    27,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      -1,    -1,     3,     4,     5,     6,    -1,    27,     9,    10,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,    -1,
       3,     4,     5,     6,    -1,    -1,    27,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    -1,     3,     4,
       5,     6,    -1,    -1,    27,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    -1,    -1,     3,     4,     5,
       6,    -1,    27,     9,    10,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    -1,     3,     4,     5,     6,    -1,
      -1,    27,    10,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    -1,     3,     4,     5,     6,    -1,    -1,    27,
      10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      -1,     3,     4,     5,     6,    -1,    -1,    27,    10,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    18,    19,    -1,     3,
       4,     5,     6,    -1,    -1,    27,    10,    -1,    -1,     3,
       4,     5,     6,    -1,    18,    19,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27
  };

  const signed char
  parser::yystos_[] =
  {
       0,    24,    46,    47,    20,     0,    40,    52,    12,    24,
      21,    22,    23,     8,    33,    10,    11,    52,     8,    12,
      12,    34,    36,    39,    48,    52,    49,     8,     8,     8,
      13,    10,    14,    13,    48,     7,     8,    29,    37,    41,
      42,    43,    50,    51,    52,    50,    50,    13,    50,    50,
      50,    50,    31,    52,     3,     4,     5,     6,     9,    10,
      14,    15,    16,    17,    18,    19,    27,     9,     9,    11,
      30,     9,    10,     8,    50,    50,    50,    50,    48,    50,
      50,    50,    50,    50,    50,    50,    38,    52,    48,    30,
      14,    50,     9,    35,    11,     8,    50,    11,    48,    50,
      30,    28,    50,     9
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    45,    46,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    51,    51,    52
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,    18,     0,     3,     5,     7,     5,     5,
       4,     7,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     8,     1,     1,     1,
       1,     5,     4,     2,     1,     1,     3,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "PLUSOP", "MINUSOP", "MULTOP",
  "DIVOP", "INT", "LP", "RP", "LHB", "RHB", "LCB", "RCB", "ASSIGN", "EQ",
  "AND", "OR", "GT", "LT", "CLASS", "STATIC", "VOID", "MAIN", "PUBLIC",
  "COMMENT", "RETURN", "PERIOD", "COMMA", "EXCLAMATION", "SEMICOLON",
  "INTTYPE", "BOOLTYPE", "STRING", "IF", "ELSE", "WHILE", "NEW", "LENGTH",
  "PRINT", "IDENTIFIER", "TRUE", "FALSE", "THIS", "STATEMENT", "$accept",
  "root", "mainclass", "statement", "statements", "expression", "factor",
  "identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    42,    42,    44,   144,   146,   149,   154,   160,   165,
     169,   174,   182,   184,   193,   203,   209,   215,   221,   226,
     231,   236,   241,   246,   252,   257,   261,   265,   268,   271,
     274,   277,   281,   285,   289,   293,   294,   297
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
#line 1628 "parser.tab.c"

