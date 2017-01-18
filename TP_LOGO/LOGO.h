typedef enum{
	FORWARD, REPEAT, LEFT, RIGHT, SPIRAL
} TYPE;

static char *enumStrings[5] = {"FORWARD", "REPEAT", "LEFT", "RIGHT", "SPIRAL"};

struct node{
TYPE type;
int value;
struct node *suivant;
struct node *subProg;
};

typedef struct node* NODE;

static NODE root;

void creerSVG(NODE);

TYPE type(NODE);

NODE newNode(NODE, NODE, int, TYPE);

NODE addNode(NODE,NODE);

void fermerNode(NODE);

int value(NODE);

NODE suivant(NODE);

NODE ssProg(NODE);

void affichage(NODE, int);
