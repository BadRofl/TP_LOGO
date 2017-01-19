%{
#include <stdio.h>
#include "LOGO.h"


void yyerror(const char *str){
	fprintf(stderr, "Erreur %s\n", str);
}

int yywrap(){
	return 1;
}
	
%}

%token TOK_FWD
%token TOK_RPT
%token TOK_LFT
%token TOK_RGT
%token TOK_NBR
%token TOK_SPIRAL
%token TOK_CENTER
%token TOK_COLOR

%union{
	NODE node;
	TYPE type;
	int value;
	int value2;
	int value3;
}

%type <type> TOK_FWD TOK_RPT TOK_LFT TOK_RGT TOK_SPIRAL 
%type <node> FILE PROG INST
%type <value> TOK_NBR
%start FILE
%%

FILE : PROG{
	 root=$1; YYACCEPT; //Force la sortie
}
PROG : INST
	{$$=$1;	}
	|INST PROG
	{$$=addNode($2,$1);}

INST : TOK_FWD TOK_NBR
	{$$=newNode(NULL,NULL,$2,0,0,FORWARD);}
	|TOK_CENTER TOK_NBR TOK_NBR
	{$$=newNode(NULL,NULL,0,$2,$3,CENTER);}
	|TOK_COLOR TOK_NBR TOK_NBR TOK_NBR
	{$$=newNode(NULL,NULL,$2,$3,$4,COLOR);}
	|TOK_LFT TOK_NBR
	{$$=newNode(NULL,NULL,$2,0,0,LEFT);}
	|TOK_RGT TOK_NBR
	{$$=newNode(NULL,NULL,$2,0,0,RIGHT);}
	|TOK_RPT TOK_NBR '[' PROG ']'
	{$$=newNode(NULL,$4,$2,0,0,REPEAT);}
	|TOK_SPIRAL TOK_NBR '[' PROG ']'
	{$$=newNode(NULL,$4,$2,0,0,SPIRAL);}
%%

int main(){
yyparse();
creerSVG(root);
return 0;
}
