struct crayon{
	double posH;
	double posV;
	double angle;
	int R;
	int G;
	int B;
};

typedef struct crayon* CRAYON;


CRAYON initCrayon(double, double, double, int, int, int);

void fermerCrayon(CRAYON);


double crayonPosH(CRAYON, int);

double crayonPosV(CRAYON, int);

double crayonAngleL(CRAYON, int);

double crayonAngleR(CRAYON, int);

void crayonColor(CRAYON, int,int,int);

void crayonCenter(CRAYON, int, int);
	

double getposH(CRAYON);

double getposV(CRAYON);

double getangle(CRAYON);


int getR(CRAYON);

int getG(CRAYON);

int getB(CRAYON);
