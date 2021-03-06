
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 36 "parser.y"

   struct number
	{

	  int ival;
	  float fval;
	  int type;
	} n;



/* Line 1676 of yacc.c  */
#line 52 "parser.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     newline = 258,
     FLOAT = 259,
     INTEGER = 260,
     PLUS = 261,
     MINUS = 262,
     MULT = 263,
     DIVIDE = 264,
     MODULO = 265,
     EQUALS = 266,
     invalid_num = 267,
     EXP = 268,
     IDENT_PUNC = 269,
     INT_PUNC = 270,
     FLOAT_PUNC = 271,
     COLON = 272,
     COMMA = 273,
     SCOLON = 274,
     PERIOD = 275,
     QUOTE = 276,
     DQUOTE = 277,
     LPAREN = 278,
     RPAREN = 279,
     IDENT = 280,
     TAGIDENT = 281,
     ENDTAGHEAD = 282,
     LTHAN = 283,
     GTHAN = 284,
     LBRACE = 285,
     RBRACE = 286,
     INVALID_COMMENT = 287,
     INVALID_TOKEN = 288
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 48 "parser.y"

   struct number num;
   char* str;



/* Line 1676 of yacc.c  */
#line 109 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


