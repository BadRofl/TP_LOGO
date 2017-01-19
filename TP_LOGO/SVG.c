#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "LOGO.h"
#include "SVG.h"



void initSVG(FILE *svg, int taille){
	fprintf(svg,"<?xml version=\"1.0\" encoding=\"utf-8\"?><svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\"><title>Dessin généré par un parseur LOGO</title>" , taille, taille);
	fprintf(svg,"<rect x=\"0px\" y=\"0px\" width=\"400\" height=\"400\"/>");
}

void ecrireSVG(NODE root, FILE *svg, CRAYON cray, int ite){

	if(root!= NULL){
			if(type(root) == 0){
				double posH;
				double posV;
				double finH;
				double finV;
				int R;
				int G;
				int B;
				
				R = getR(cray);
				G = getG(cray);
				B = getB(cray);
				
				posH = getposH(cray);
				posV = getposV(cray);
				
				finH = crayonPosH(cray,value(root)-ite);
				finV = crayonPosV(cray,value(root)-ite);
				
				fprintf(svg, "<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style =\"stroke:rgb(%d,%d,%d); stroke-width: 1px\" />", posH, posV, finH, finV, R, G, B);
			
			}
			else if(type(root) == 2){
				//printf("LEFT\n");
				crayonAngleL(cray, value(root));
			}
			else if(type(root) == 5){
				//printf("CENTER\n");
				crayonCenter(cray,value2(root), value3(root));
			}
			else if(type(root) == 6){
				//printf("COLOR\n");
				crayonColor(cray, value(root),value2(root),value3(root));
			}
			else if(type(root) == 3){
				//printf("RIGHT\n");
				crayonAngleR(cray, value(root));
				
			}
			else if(type(root) == 1){
				//printf("REPEAT\n");
				int i;
				for(i = 0; i<value(root); i++){
		
					ecrireSVG(ssProg(root), svg, cray, ite);					
				}		
			}
			else if(type(root) == 4){
				//printf("SPIRAL\n");
				int i;
				for(i = 0; i<value(root); i++){
		
					ecrireSVG(ssProg(root), svg, cray, i);					
				}		
			}
			ecrireSVG(suivant(root), svg, cray, ite);
		
	}
}


void fermerSVG(FILE *svg){
	
	fputs("</svg>\n", svg);
	fclose(svg);
	printf("Logo crée!\n");
	
}

