%{
#include <stdio.h>
#include "LOGO.h"
#include "ParseurLOGO.tab.h"
%}

%%
(F|f)(O|o)(R|r)(W|w)(A|a)(R|r)(D|d)  return TOK_FWD; 
(R|r)(E|e)(P|p)(E|e)(A|a)(T|t)       return TOK_RPT;
(L|l)(E|e)(F|f)(T|t) 				 return TOK_LFT;
(R|r)(I|i)(G|g)(H|h)(T|t)   		 return TOK_RGT;
(S|s)(P|p)(I|i)(R|r)(A|a)(L|l)		 return TOK_SPIRAL;

"[" 							{return '[';}      
"]"	   							{return ']';} 
[0-9]+ {yylval.value=atoi(yytext); return TOK_NBR;}

"//".*    //Permet d'ajouter des commentaires
[ \t\n]+ //Ignore les espaces tabulations et retours à la ligne
%%
