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




%type <num> command exp digit math_exp invalid_num text_exp t_exp 
%type <str> word openB closeB t_OP openP closeP t_openP t_closeP html_statement html_contents html_list html_statements
%type <str> annotator token tokens word_annon open_tag close_tag inner_words inner_word
%%

command :  newline	
	| command newline	
	| math_exp newline   
	| command math_exp newline	
	
	| text_exp newline
	| command text_exp newline
	
	
	| tokens newline {printf("\n");}
	| command tokens newline {printf("\n");}
	

	
	| html_list {printf("\n");}
	| command html_list newline{printf("\n");}
	
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
	
html_statements: html_statement {printf("\n");}
	| html_statements newline html_statement {printf("\n");}

	;
	
html_statement: open_tag close_tag html_contents end_tag IDENT close_tag {printf(", ");} 
	| open_tag close_tag html_statement end_tag IDENT close_tag {printf("");}	
	| html_statement open_tag close_tag html_contents end_tag IDENT close_tag {printf(", ");} 
	;
	
html_contents: tokens	{printf(" ");}
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
	
	
tokens: token {;}
	| tokens token {;}
	;
	
token: word {;}
	| word_annon {;}
	| annotator	{;}
	| EQUALS {;}
	| digit{ 
			if($1.type == 1){
				printf("%d", $1.ival);
			}
			else{
				printf("%f", $1.fval);
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
	;
	
	
word: IDENT {$$ = $1; printf("%s", $1);}
	;
	
word_annon: IDENT_PUNC {
							$$ = $1; 
							char* currText = $$;
							RemoveChars(currText, ' ');
							printf("%s ", currText);
						}
	| INT_PUNC {
					$$ = $1;
					char* currText = $$;
					RemoveChars(currText, ' ');
					printf("%s ", currText);					
			   }
	| FLOAT_PUNC {
					$$ = $1;
					char* currText = $$;
					RemoveChars(currText, ' ');
					printf("%s ", currText);					
			   }
	;
	

	
openB: LBRACE {
					;
			  }
	;
	
closeB: RBRACE {
				printf("\n");
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
								//sprintf(curr, "%f", $3.fval);
								//globalC = strcat(globalC, curr);
								//printf("%f", $3.fval);
								;
							}
							
							if($1.type == 2 && $3.type == 1){
								//sprintf(curr, "%d", $3.ival);
								//globalC = strcat(globalC, curr);
								//printf("%d", $3.ival);
								;
							}
							
							if($1.type == 2 && $3.type == 2){
								//sprintf(curr, "%f", $3.fval);
								//globalC = strcat(globalC, curr);								
								//printf("%f", $3.fval);
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
				else{
					//sprintf(curr, "%f", $1.fval);
					//globalC = strcat(globalC, curr);	
					printf("%f", $1.fval);
				}
				
	} 
	;
	
t_OP: PLUS	{printf("+");}
	|MINUS	{printf("-");}
	|MULT	{printf("*");}
	|DIVIDE	{printf("/");}
	
	
	
math_exp	: EQUALS exp { //printf("Expression type = %d\n",$2.type);
							if($2.type == 1){
								printf("Expression of int type single and value: %d\n", $2.ival);
							}
							else{
								printf("Expression of float type single and value: %f\n", $2.fval);
							} 
							
						}

;

exp :	exp PLUS exp 		{	
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
	| exp MINUS exp   	{	
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
	| exp MULT exp   	{	
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
	| exp DIVIDE exp   	{	
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
	| exp MODULO exp   	{	
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
	| openP exp closeP		{$$ = $2;}
	|	digit {$$ = $1;}
    ;
	
digit: INTEGER {$$ = $1; $$.type = $1.type; }
	| FLOAT {$$ = $1; $$.type = $1.type;}
	| invalid_num {printf("Badly formed number\n"); return 1;}
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
