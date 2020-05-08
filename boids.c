#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <GLUT/glut.h>

float boidShape[10] = {-20,-27,-20,0,0,50,20,0,20,-27};
double startOrientation[2] = {0,1};

typedef struct boid{
	int r;
	int g;
	int b;
	int x;
	int y;
	double *vec;
} boid;

boid *newBoid(int x, int y, double vecX, double vecY, int red, int grn, int blu){
	boid *b = malloc(sizeof(boid));
	b->x = x;
	b->y = y;
	b->vec = malloc(2*sizeof(double));
	b->vec[0] = vecX;
	b->vec[1] = vecY;
	b->r = red;
	b->g = grn;
	b->b = blu;
	return b;
}

void freeBoid(boid *b){
	free(b->vec);
	free(b);
}

void drawBoid(boid *b){
	glColor3ub(b->r,b->g,b->b);
	glEnableClientState(GL_VERTEX_ARRAY);
	double dot = (b->vec[1])/sqrt(pow(b->vec[0],2)+pow(b->vec[1],2));
	double cross = -(b->vec[0]);
	double omega = acos(dot)*180/3.1415;
	glPushMatrix();
	glTranslatef(b->x, b->y,0);
	glRotatef(omega,0,0,cross);
	glVertexPointer(2, GL_FLOAT, 0, boidShape);
	glDrawArrays(GL_POLYGON, 0, 5);
	glPopMatrix();
	glDisableClientState(GL_VERTEX_ARRAY);
}