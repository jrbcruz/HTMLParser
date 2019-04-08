%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>



int INT_TYPE = 1;
int FLOAT_TYPE = 2;

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
%type <num> command exp digit
%%

command :  newline
	| command newline
	| exp newline   {printf("Expression type = %d\n",$1.type);
							if($1.type == 1){
								printf("Expression of int type single and value: %d\n", $1.ival);
							}
							else{
								printf("Expression of float type single and value: %f\n", $1.fval);
							}
						}
	| command exp newline	{printf("Expression type = %d\n",$2.type);
							if($2.type == 1){
								printf("Expression of int type and value: %d\n", $2.ival);
							}
							else{
								printf("Expression of float type and value: %f\n", $2.fval);
							}
						}
    ;

exp :	exp PLUS digit 		{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival + $3.ival);
								}
								
								if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = ($1.ival + $3.fval);
								}
								
								if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = ($1.fval + $3.ival);
								}
								
								if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = ($1.fval + $3.fval);
								}
							}
	| exp MINUS digit   	{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival - $3.ival);
								}
								
								if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = ($1.ival - $3.fval);
								}
								
								if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = ($1.fval - $3.ival);
								}
								
								if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = ($1.fval - $3.fval);
								}
							}
	| exp MULT digit   	{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival * $3.ival);
								}
								
								if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = ($1.ival * $3.fval);
								}
								
								if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = ($1.fval * $3.ival);
								}
								
								if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = ($1.fval * $3.fval);
								}
							}
	| exp DIVIDE digit   	{	
								if($1.type == 1 && $3.type == 1){
									//printf("both are integers\n");
									$$.type = 1;
									$$.ival = ($1.ival / $3.ival);
								}
								
								if($1.type == 1 && $3.type == 2){
									//printf("first is int second is float\n");
									$$.type = 2;
									$$.fval = ($1.ival / $3.fval);
								}
								
								if($1.type == 2 && $3.type == 1){
									//printf("first is float second is int\n");
									$$.type = 2;
									$$.fval = ($1.fval / $3.ival);
								}
								
								if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = ($1.fval / $3.fval);
								}
							}
	| exp MODULO digit   	{	
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
								
								if($1.type == 2 && $3.type == 2){
									//printf("both are floats\n");
									$$.type = 2;
									$$.fval = fmodf($1.fval, $3.fval);
								}
							}							
	|	digit {$$ = $1;}
    ;
	
digit: INTEGER {$$ = $1; $$.type = $1.type;  printf("ival assigned\n");}
	| FLOAT {$$ = $1; $$.type = $1.type; printf("fval assigned\n");}
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
