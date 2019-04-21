%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int INT_TYPE = 1;
int FLOAT_TYPE = 2;


char* prevWord = "";

void RemoveChars(char *s, char c)
{
    int writer = 0, reader = 0;

    while (s[reader])
    {
        if (s[reader]!=c) 
        {   
            s[writer++] = s[reader];
        }

        reader++;       
    }

    s[writer]=0;
}


%}

%code requires {
   struct number
	{

	  int ival;
	  float fval;
	  int type;
	} n;
}


%union
{
   struct number num;
   char* str;
}

%start command
%token newline

%token <num>FLOAT 
%token <num>INTEGER
%token PLUS
%token MINUS
%token MULT
%token DIVIDE
%token MODULO
%token EQUALS
%token invalid_num
%token EXP

%token <str>IDENT_PUNC
%token <str>INT_PUNC
%token <str>FLOAT_PUNC

%token <str>COLON;
%token <str>COMMA;
%token <str>SCOLON;
%token <str>PERIOD;
%token <str>QUOTE;
%token <str>DQUOTE;


%token <str>LPAREN
%token <str>RPAREN
%token <str>IDENT
%token <str> TAGIDENT
%token <str> ENDTAGHEAD
%token <str>LTHAN
%token <str>GTHAN
%token <str>LBRACE
%token <str>RBRACE
%token <str> INVALID_COMMENT;
%token <str> INVALID_TOKEN;

%left '+' '-'
%left '*' '/'
%left '%'

%type <num> command exp digit math_exp invalid_num text_exp t_exp 
%type <str> word openB closeB t_OP openP closeP t_openP t_closeP html_statement html_contents html_list html_statement_end html_statement_other
%type <str> annotator tokens word_annon open_tag close_tag inner_words inner_word token_end token_other 
%%

command :  newline	{;}
	| command newline	{;}
	| math_exp newline   {;}
	| command math_exp newline	{;}
	
	| text_exp newline {;}
	| command text_exp newline {;}
	
	| tokens newline {printf("\n");}
	| command tokens newline {printf("\n");}
	
	/* this */
	| end_tag newline{printf("</\n");}
	| command end_tag newline{printf("</\n");}
	| command tokens end_tag {printf("</");}
	| command tokens end_tag newline{printf("</\n");}
	
	| TAGIDENT newline{printf("%s\n", $1);}
	| command TAGIDENT newline{printf("%s\n", $2);}
	| command tokens TAGIDENT {printf("%s", $3);}
	| command tokens TAGIDENT newline{printf("%s\n", $3);}
	
	| INVALID_TOKEN newline{printf("(invalid:%s)", $1);}
	| command INVALID_TOKEN newline{printf("(invalid:%s)", $2);}
	| command tokens INVALID_TOKEN {printf("(invalid:%s)", $3);}
	
	| INVALID_COMMENT newline {printf("Un-expected end of file\n"); return 1;}
	| command INVALID_COMMENT {printf("Un-expected end of file"); return 1;}
	| command INVALID_COMMENT newline {printf("Un-expected end of file\n"); return 1;}
	/* until this */
	
	| html_list {;}
	| command html_list {;}
	| command html_list newline {;}
    ;
	
	

mulline: newline {;}
	|	mulline newline {;}
	;
	
open_tag: TAGIDENT	{;}
	| TAGIDENT inner_words {;}
	| TAGIDENT mulline	{;}
	;

close_tag: GTHAN {;}
	;
	
end_tag: ENDTAGHEAD {;}
	;

html_list: open_tag close_tag mulline tokens end_tag IDENT close_tag {;} 
	| open_tag close_tag mulline html_list end_tag IDENT close_tag {;} 
	| open_tag close_tag mulline tokens mulline end_tag IDENT close_tag {;}
	| open_tag close_tag mulline html_list mulline end_tag IDENT close_tag {;}

	
	| html_statement {printf("\n");}
	| html_list newline html_statement {printf("\n");}
	
	
	| html_list newline open_tag close_tag mulline tokens end_tag IDENT close_tag {printf("");}
	| html_list newline	open_tag close_tag mulline tokens mulline end_tag IDENT close_tag {printf("");}
	| html_list newline open_tag close_tag mulline html_list end_tag IDENT close_tag {printf("");}
	| html_list newline	open_tag close_tag mulline html_list mulline end_tag IDENT close_tag {printf("");}
	;
	


html_statement: html_statement_end {;}

	| html_statement html_statement_end {;}
	| html_statement html_statement_other html_statement_end {;}
	
	
	| html_statement_other html_statement_end {printf("");;}
	| open_tag close_tag html_statement end_tag IDENT close_tag {printf("");;}
	| html_statement open_tag close_tag html_statement end_tag IDENT close_tag {printf("");}
	;
	
html_statement_other: open_tag close_tag html_contents end_tag IDENT close_tag {printf(",");} 	
	| html_statement_other open_tag close_tag html_contents end_tag IDENT close_tag {printf(",");} 
	;
	
html_statement_end: open_tag close_tag html_contents end_tag IDENT close_tag {printf(",");}
	;
	
html_contents: tokens	{printf("");}
	| math_exp	{printf(" ");}
	| text_exp	{printf(" ");}
	;
	
inner_words: inner_word {;}
	| inner_words inner_word {;}
	;
	
inner_word: IDENT {;}
	| digit {;}
	| EQUALS {;}
	;
	
	
tokens: token_end {printf("");}
	| token_other token_end {printf("");}
	;
	
token_end: word {;}
	| word_annon {;}
	| annotator	{;}
	|'+'	{printf("+");}
	|'-'	{printf("-");}
	|'*'	{printf("*");}
	|'/'	{printf("/");}
	|'%'	{printf("%c", '%');}
	|EXP 	{printf("**");}
	|EQUALS {printf("=");}

	| digit{ 
			if($1.type == 1){
				printf("%d ", $1.ival);
			}
			else if($1.type == 2){
				printf("%.2f ", $1.fval);
			}
		}
	;
	
token_other: word {printf(" ");}
	| word_annon {printf(" ");}
	| annotator	{printf(" ");}
	|'+'	{printf("+ ");}
	|'-'	{printf("- ");}
	|'*'	{printf("*");}
	|'/'	{printf("/");}
	|'%'	{printf("%c", '%');}
	|EXP 	{printf("**");}
	
	|EQUALS {printf("=");}	
	| digit{ 
			if($1.type == 1){
				printf("%d ", $1.ival);
			}
			else if($1.type == 2){
				printf("%.2f ", $1.fval);
			}
		}
	| token_other word {printf(" ");}
	| token_other word_annon {printf(" ");}
	| token_other annotator	{printf(" ");}
	| token_other '+'	{printf("+ ");}
	| token_other '-'	{printf("- ");}
	| token_other '*'	{printf("* ");}
	| token_other '/'	{printf("/ ");}
	| token_other '%'	{printf("%c ", '%');}
	| token_other EXP 	{printf("** ");}
	| token_other EQUALS {printf("= ");}
	
	| token_other digit{ 
			if($2.type == 1){
				printf("%d ", $2.ival);
			}
			else if($2.type == 2){
				printf("%.2f ", $2.fval);
			}
		}
	;
	

	
annotator: COLON { printf(":");}
	| COMMA { 
			 printf(",");
		}
	| SCOLON { printf(";");}
	| PERIOD {printf(".");}
	| QUOTE { printf("'");}
	| DQUOTE {printf("\"");}
	| openP {printf("(");}
	| closeP {printf(")");}
	| GTHAN {printf(">");}
	| LTHAN {printf("<");}
	;
	
	
word: IDENT {$$ = $1; printf("%s", $1);}
	;
	
word_annon: IDENT_PUNC {
							$$ = $1; 
							char* currText = $$;
							RemoveChars(currText, ' ');
							printf("%s", currText);
						}
	| INT_PUNC {
					$$ = $1;
					char* currText = $$;
					RemoveChars(currText, ' ');
					printf("%s", currText);					
			   }
	| FLOAT_PUNC {
					$$ = $1;
					char* currText = $$;
					RemoveChars(currText, ' ');
					printf("%s", currText);					
			   }
	;
	

	
openB: LBRACE {
					;
			  }
	;
	
closeB: RBRACE {
				printf("");
			   }
	;
	
openP: LPAREN {;}
	;
	
closeP: RPAREN {;}
	;

t_openP: LPAREN {printf("(");}
	;

t_closeP: RPAREN {printf(")");}
	;

	
text_exp: openB t_exp closeB {;}
	;
	
t_exp: t_exp t_OP t_exp {
							if($1.type == 1 && $3.type == 1){
								//sprintf(curr, "%d", $3.ival);
								//globalC = strcat(globalC, curr);
								//printf("%d", $3.ival);
								;
							}
							
							if($1.type == 1 && $3.type == 2){
								//sprintf(curr, "%.2f", $3.fval);
								//globalC = strcat(globalC, curr);
								//printf("%.2f", $3.fval);
								;
							}
							
							if($1.type == 2 && $3.type == 1){
								//sprintf(curr, "%d", $3.ival);
								//globalC = strcat(globalC, curr);
								//printf("%d", $3.ival);
								;
							}
							
							if($1.type == 2 && $3.type == 2){
								//sprintf(curr, "%.2f", $3.fval);
								//globalC = strcat(globalC, curr);								
								//printf("%.2f", $3.fval);
								;
							}
						}
	
	| t_openP t_exp t_closeP {;}
	| digit {
				$$ = $1;
				if($1.type == 1){
					//sprintf(curr, "%d", $1.ival);
					//globalC = strcat(globalC, curr);
					printf("%d", $1.ival);
				}
				else if($1.type == 2){
					//sprintf(curr, "%.2f", $1.fval);
					//globalC = strcat(globalC, curr);	
					printf("%.2f", $1.fval);
				}
				
	} 
	;
	
t_OP: '+'	{printf("+");}
	|'-'	{printf("-");}
	|'*'	{printf("*");}
	|'/'	{printf("/");}
	|'%'	{printf("%c", '%');}
	|EXP 	{printf("**");}
	
	
	
math_exp	: EQUALS exp { //printf("Expression type = %d\n",$2.type);
							if($2.type == 1){
								printf("%d", $2.ival);
							}
							else if($2.type == 2){
								printf("%.2f", $2.fval);
							} 
							
						}

;

exp :	exp '+' exp 		{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival + $3.ival);
								}
								
								else if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = ($1.ival + $3.fval);
								}
								
								else if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = ($1.fval + $3.ival);
								}
								
								else if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = ($1.fval + $3.fval);
								}
							}
	| exp '-' exp   	{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival - $3.ival);
								}
								
								else if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = ($1.ival - $3.fval);
								}
								
								else if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = ($1.fval - $3.ival);
								}
								
								else if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = ($1.fval - $3.fval);
								}
							}
	| exp '*' exp   	{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival * $3.ival);
								}
								
								else if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = ($1.ival * $3.fval);
								}
								
								else if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = ($1.fval * $3.ival);
								}
								
								else if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = ($1.fval * $3.fval);
								}
							}
	| exp '/' exp   	{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival / $3.ival);
								}
								
								else if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = ($1.ival / $3.fval);
								}
								
								else if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = ($1.fval / $3.ival);
								}
								
								else if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = ($1.fval / $3.fval);
								}
							}
	| exp '%' exp   	{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival % $3.ival);
								}
							
								/*if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = fmodf((float)$1.ival, $3.fval);
								}*/						
								
								/*if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = fmodf($1.fval, (float)$3.ival);
								} */		
								
								else if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = fmodf($1.fval, $3.fval);
								}
							}
	| exp EXP exp			{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = pow($1.ival, $3.ival);
								}
								
								else if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = pow($1.ival, $3.fval);
								}
								
								else if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = pow($1.fval, $3.ival);
								}
								
								else if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = pow($1.fval, $3.fval);
								}
							}
	| openP exp closeP		{$$ = $2;}
	|	digit {$$ = $1;}
    ;
	
digit: INTEGER {$$ = $1; $$.type = $1.type; }
	| FLOAT {$$ = $1; $$.type = $1.type;}
	| '-' INTEGER {$$.ival = -$2.ival; $$.type = $2.type;}
	| '-' FLOAT {$$.fval = -$2.fval; $$.type = $2.type;}
	| invalid_num {printf("Badly formed number"); }
	;





%%

int main()
{ 

  return yyparse();
}


int yyerror(char *s)
{
   fprintf(stderr,"%s\n",s);
   return 0;
}
