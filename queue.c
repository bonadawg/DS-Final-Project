/*queue.c, full implementation of a priority queue to use in order to implement dijkstra's algorithm for enemy pathfinding*/
/*James Bonadonna (jbonadon), Ana Lamberto (alamber2), Sean Michalec (smichale)*/

#include "queue.h"
#include <stdlib.h>
#include "map.h"
#include "main.h"
#include "gui.h"

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
	struct tile *t = (tile_t*)malloc(sizeof(*t));
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
		tile_t *curr = q->head;
		if(t->cost <= curr->cost){
			t->next = q->head;
			q->head = t;
			q->length++;
			return q;
		}
		while(curr->next){
			if(t->cost < curr->next->cost){
				t->next = curr->next;
				curr->next = t;
				q->length++;
				return q;
			}
			curr = curr->next;
		}
		curr->next = t;
		q->length++;
	}
	return q;
}

void queue_pop(struct queue *q){
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
	while(!queue_empty(q)){
		queue_pop(q);
	}
	free(q);
}
