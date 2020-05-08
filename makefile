CC=/usr/bin/gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g -framework OpenGL -framework GLUT -Wno-deprecated-declarations -fsanitize=address 

boids: flyers.c boids.c updateBoids.c
	$(CC) $(CFLAGS) -o boids flyers.c 

