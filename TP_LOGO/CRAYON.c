#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "CRAYON.h"

#define PI 3.14159

CRAYON initCrayon(double posH, double posV, double angle, int R, int G, int B){
	 CRAYON cray = (CRAYON)malloc(sizeof(*cray));
	 
	 cray -> posH = posH;
	 cray -> posV = posV;
	 cray -> angle = angle;
	 cray -> R = R;
	 cray -> G = G;
	 cray -> B = B;
	 
	 return cray;
	 
}

void fermerCrayon(CRAYON cray){
	if(cray != NULL){
		//printf("Crayon libéré\n");
		free(cray);
	}
}

double crayonPosH(CRAYON cray, int valeur){
	if(cray != NULL){
		double posH = getposH(cray) + valeur * cos(getangle(cray));
		cray->posH = posH;
	
		return posH;
	}
}

double crayonPosV(CRAYON cray, int valeur){
	if(cray != NULL){
		double posV = getposV(cray) + valeur * sin(getangle(cray));
		cray->posV = posV;
	
		return posV;
	}
}

double crayonAngleL(CRAYON cray, int valeur){
	if(cray != NULL){
		double angle = getangle(cray) - ((PI*valeur)/180.0);
		cray->angle = angle;
	
		return angle;
	}
}

double crayonAngleR(CRAYON cray, int valeur){
	if(cray != NULL){
		double angle = getangle(cray) + ((PI*valeur)/180.0);
		cray->angle = angle;
	
		return angle;
	}
}

void crayonColor(CRAYON cray, int R, int G, int B){
	if(cray != NULL){
		cray->R = R;
		cray->G = G;
		cray->B = B;
	}	
}

void crayonCenter(CRAYON cray, int H, int V){
	if(cray != NULL){
		cray->posH = H;
		cray->posV = V;
	}
}
	

double getposH(CRAYON cray){
	if(cray != NULL){
		return cray->posH;
	}
}

double getposV(CRAYON cray){
	if(cray != NULL){
		return cray->posV;
	}
}

double getangle(CRAYON cray){
	if(cray != NULL){
		return cray->angle;
	}
}

int getR(CRAYON cray){
	if(cray != NULL){
		return cray->R;
	}
}

int getG(CRAYON cray){
	if(cray != NULL){
		return cray->G;
	}
}

int getB(CRAYON cray){
	if(cray != NULL){
		return cray->B;
	}
}


	 
	
