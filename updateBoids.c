#include "boids.c"

int positive_modulo(int i, int n) {
    return (n + (i % n)) % n;
}

double centerX(int j, int n, boid **boidArray){
	double accumX = 0;
	int count = 1;
	for(int i=0;i<n;i++){
		if(i!=j){
			if((pow(boidArray[i]->x - boidArray[j]->x,2) 
				+ pow(boidArray[i]->y - boidArray[j]->y,2)) < 150000){
				accumX += boidArray[i]->x - boidArray[j]->x;
				count++;
			}
		}
	}
	return accumX/count/150;
}

double centerY(int j, int n, boid **boidArray){
	double accumY = 0;
	int count = 1;
	for(int i=0;i<n;i++){
		if(i!=j){
			if((pow(boidArray[i]->x - boidArray[j]->x,2) 
				+ pow(boidArray[i]->y - boidArray[j]->y,2)) < 150000){
				accumY += boidArray[i]->y - boidArray[j]->y;
				count++;
			}
		}
	}
	return accumY/count/150;
}

double avoidX(int j, int n, boid **boidArray){
	double accumX = 0;
	for(int i=0;i<n;i++){
		if(i!=j){
			if((pow(boidArray[i]->x - boidArray[j]->x,2) 
				+ pow(boidArray[i]->y - boidArray[j]->y,2)) < 1000){
				accumX -= (boidArray[i]->x - boidArray[j]->x);
			}
		}
	}
	return accumX/22;
}

double avoidY(int j, int n, boid **boidArray){
	double accumY = 0;
	for(int i=0;i<n;i++){
		if(i!=j){
			if((pow(boidArray[i]->x - boidArray[j]->x,2) 
				+ pow(boidArray[i]->y - boidArray[j]->y,2)) < 1000){
				accumY -= (boidArray[i]->y - boidArray[j]->y);
			}
		}
	}
	return accumY/22;
}

double avoidWalls(int j, boid **boidArray){
	boid *b = boidArray[j];
	double scale = 0.5*(pow(b->vec[0],2) + pow(b->vec[1],2));
	return (scale/(double)b->x) - (scale/(double)(1000-b->x)) ;
}

double avoidWalls2(int j, boid **boidArray){
	boid *b = boidArray[j];
	if(b->x < 0){
		return 10;
	}
	if(b->x >1000){
		return -10;
	}
}
double avoidFloors(int j, boid **boidArray){
	boid *b = boidArray[j];
	double scale = 0.5* (pow(b->vec[0],2) + pow(b->vec[1],2));
	return (scale/(double)b->y) - (scale/(double)(1000-b->y)) ;
}

double avoidFloors2(int j, boid **boidArray){
	boid *b = boidArray[j];
	if(b->y < 0){
		return 10;
	}
	if(b->y >1000){
		return -10;
	}
}
double matchX(int j, int n, boid **boidArray){
	double accumX = 0;
	int count = 1;
	for(int i=0;i<n;i++){
		if(i!=j){
			if((pow(boidArray[i]->x - boidArray[j]->x,2) 
				+ pow(boidArray[i]->y - boidArray[j]->y,2)) < 1800){
				accumX += boidArray[i]->vec[0];
				count++;
			}
		}
	}
	return (accumX-boidArray[j]->vec[0])/count/10;
}

double matchY(int j, int n, boid **boidArray){
	double accumY = 0;
	int count = 1;
	for(int i=0;i<n;i++){
		if(i!=j){
			if((pow(boidArray[i]->x - boidArray[j]->x,2) 
				+ pow(boidArray[i]->y - boidArray[j]->y,2)) < 1800){
				accumY += boidArray[i]->vec[1];
				count++;
			}
		}
	}
	return (accumY-boidArray[j]->vec[1])/count/10;
}






