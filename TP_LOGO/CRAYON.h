struct crayon{
	double posH;
	double posV;
	double angle;
};

typedef struct crayon* CRAYON;


CRAYON initCrayon(double, double, double);

void fermerCrayon(CRAYON);


double crayonPosH(CRAYON, int);

double crayonPosV(CRAYON, int);

double crayonAngleL(CRAYON, int);

double crayonAngleR(CRAYON, int);
	

double getposH(CRAYON);

double getposV(CRAYON);

double getangle(CRAYON);
