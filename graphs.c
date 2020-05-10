#include <stdio.h>
#include <stdlib.h>
#include "boids.c"

typedef struct node{
	boid *b;
	struct node *next;
} node;

typedef struct list{
	int elements;
	int size;
	node **nodes;
} list;

list *initList(int elements){
	list *l = malloc(sizeof(list));
	node **nodes = calloc(elements,sizeof(*nodes));
	l-> nodes = nodes;
	l-> size = 0;
	l-> elements = elements;
	return l;
}
void add(boid *b, list *l, int addr){
	node **nodes = l->nodes;
	if(addr > l->elements){
		return;
	}
	else if(nodes[addr] == NULL){
		node *n = malloc(sizeof(node));
		n->b = b;
		n->next = NULL;
		nodes[addr] = n;
	}
	else
	{
		node *n = malloc(sizeof(node));
		n->b = b;
		n->next = NULL;
		node *cur = nodes[addr];
		while(cur->next != NULL){
			if(cur->next->b == b){
				break;
			}
			else if(cur->next == NULL){
				cur->next = n;
			}
			else
			{
				cur = cur->next;
			}
		}
	}
}

void delete(boid *b, list *l, int addr){
	node **nodes = l->nodes;
	if(addr > l->elements){
		return;
	}
	else if(nodes[addr] == NULL){
		return;
	}
	else
	{
		node *cur = nodes[addr];
		while(cur->next != NULL){
			if(cur->next->b == b){
				break;
			}
			else
			{
				cur = cur->next;
			}
		}
		if(cur->next != NULL){
			node *temp = cur->next;
			cur->next = temp->next;
			free(temp);
		}
	}
}

void printDir(list *l, int dir){
	node **nodes = l->nodes;
	if(nodes[dir] == NULL){
		return;
	}
	else{
		node *cur = nodes[dir];
		while(cur->next != NULL){
			printf("%d,",cur->b->x);
			cur = cur->next;
		}
	}
	// printf("\n");
}
// int main(){
// 	boid *b = newBoid(1,2,3,4,5,6,7);
// 	list *dawna = initList(5);
// 	add(b, dawna, 0);
// 	add(b, dawna, 0);
// 	printf("%d\n",dawna->nodes[0]->b->y);
// 	delete(b, dawna, 0);
// 	delete(b, dawna, 0);
// 	printf("%d\n",dawna->nodes[0]->b->y);
// 	return 0;
// }




