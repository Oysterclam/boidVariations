#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>
#include "updateBoids.c"
#include <time.h>

boid **boidArray;

void updateBoids(int n, boid **boidArray){
	for(int i=0;i<n;i++){
		boid *b = boidArray[i];
		b->vec[0] += centerX(i,n, boidArray);
		b->vec[1] += centerY(i,n, boidArray);
		b->vec[0] += avoidX(i,n, boidArray);
		b->vec[1] += avoidY(i,n, boidArray);
		b->vec[0] += matchX(i, n, boidArray);
		b->vec[1] += matchY(i, n, boidArray);
		// b->vec[0] += avoidWalls(i, boidArray);
		// b->vec[1] += avoidFloors(i, boidArray);

	}
	for(int i=0;i<n;i++){
		boid *b = boidArray[i];
		b->x += b->vec[0];
		b->y += b->vec[1];
		b->x = positive_modulo(b->x, 2000);
		b->y = positive_modulo(b->y, 2000);
		drawBoid(b);
		b->vec[0] += rand()%3-1;
		b->vec[1] += rand()%3-1;
		// printf("%d,%d\n",b->x,b->y);
 	}
}

void keyPressed (unsigned char key, int x, int y) {  
	if(key == 'q'){
		printf("dawnaballz\n");
		exit(0);
	}
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	// glColor3ub(rand()%255, rand()%255, rand()%255 );
	// glBegin(GL_POLYGON);
	// glVertex3f(500,500,0);
	// glVertex3f(500,200,0);
	// glVertex3f(200,200,0);
	// glVertex3f(200,500,0);
	// glEnd();
	updateBoids(100, boidArray);
	glFlush();
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	boidArray = malloc(100*sizeof(boid));
	for(int i=0;i<200;i++){
		boidArray[i] = newBoid(rand()%2000,rand()%2000,rand()%40-20,rand()%40-20, rand()%255, rand()%255, rand()%255);
	}


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
    glutCreateWindow("Dawna Linsdell");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glPointSize(3);
    glOrtho(0.f, 2000.f, 0, 2000.f, 0.f, 1.f );
    glutKeyboardFunc(keyPressed);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();

	int duh =2;
	printf("%d\n",~duh);
	return 0;
}
