//queue.h, contains all function declarations and structs for queue.c and implementation for other programs
//James Bonadonna (jbonadon), Ana Lamberto (alamber2), Sean Michalec (smichale), Justin Doney (jdoney)

#ifndef QUEUE_H
#define QUEUE_H
    #include <ncurses.h>
    #include <stdlib.h>

	typedef struct tile {
		int cost;
		struct tile *next;
		int x;
		int y;
		int xPrev;
		int yPrev;
	} tile_t;

    typedef struct queue {
		struct tile *head;
		int length;
    } queue_t;

	struct queue *queue_create();
	struct queue *queue_push(struct queue *q, int c, int x, int y, int xP, int yP);
	void queue_pop(struct queue *q);
	struct tile *queue_top(struct queue *q);
	int queue_empty(struct queue *q);
	void queue_clear(struct queue *q);

#endif
