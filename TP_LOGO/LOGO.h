typedef enum{
	FORWARD, REPEAT, LEFT, RIGHT, SPIRAL, CENTER, COLOR
} TYPE;

static char *enumStrings[7] = {"FORWARD", "REPEAT", "LEFT", "RIGHT", "SPIRAL", "CENTER", "COLOR"};

struct node{
TYPE type;
int value;
int value2;
int value3;
struct node *suivant;
struct node *subProg;
};

typedef struct node* NODE;

static NODE root;

void creerSVG(NODE);

TYPE type(NODE);

NODE newNode(NODE, NODE, int, int, int, TYPE);

NODE addNode(NODE,NODE);

void fermerNode(NODE);

int value(NODE);

int value2(NODE);

int value3(NODE);

NODE suivant(NODE);

NODE ssProg(NODE);

void affichage(NODE, int);
