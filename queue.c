//queue.c, full implementation of a priority queue to use in order to implement dijkstra's algorithm for enemy pathfinding
//James Bonadonna (jbonadon), Ana Lamberto (alamber2), Sean Michalec (smichale), Justin Doney (jdoney)

#include "queue.h"
#include <stdlib.h>

queue_t *queue_create(){
    queue_t *q = (queue_t*)malloc(sizeof(*q));
    q->head = NULL;
    q->length = 0;
    return q;
}

queue_t *queue_push(queue_t *q, int c, int x0, int y0, int xP, int yP){
    if (!q) {
        return NULL;
    }
	tile_t *t = (tile_t*)malloc(sizeof(*t));
	t->cost = c;
	t->next = NULL;
	t->x = x0;
	t->y = y0;
	t->xPrev = xP;
	t->yPrev = yP;

	if(queue_empty(q)){
		q->head = t;
		q->length++;
	}
	else{
		tile_t *temp = q->head;
		if(t->cost < temp->cost){
			t->next = q->head;
			q->head = t;
			q->length++;
			return q;
		}
		while(temp->next != NULL){
			temp = temp->next;
			if(t->cost < temp->cost){
				t->next = temp;
				return q;
			}
		}
		temp->next = t;
		q->length++;
	}
	return q;
}

void queue_pop(queue_t *q){
	tile_t *temp = q->head;
	q->head = q->head->next;
	free(temp);
	q->length--;
}

tile_t *queue_top(queue_t *q){
	return q->head;
}

int queue_empty(queue_t *q){
	if(q->length != 0)
		return 0;
	else
		return 1;
}

void queue_clear(queue_t *q){
	tile_t *curr = q->head;
	while(curr->next != NULL){
		tile_t *temp = curr;
		curr = curr->next;
		free(temp);
	}
	free(curr);
	free(q);
}