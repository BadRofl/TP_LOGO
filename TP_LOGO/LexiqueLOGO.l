%{
#include <stdio.h>
#include "LOGO.h"
#include "ParseurLOGO.tab.h"
%}

%%
FORWARD  return TOK_FWD; 
REPEAT   return TOK_RPT;
LEFT     return TOK_LFT;
RIGHT    return TOK_RGT;
RAINBOWDASH return TOK_RBD;

"[" 							{return '[';}      
"]"	   							{return ']';} 
[0-9]+ {yylval.value=atoi(yytext); return TOK_NBR;}

[ \t\n]+ //Ignore les espaces tabulations et retours à la ligne
%%
