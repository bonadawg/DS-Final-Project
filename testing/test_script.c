#include "queue.h"
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <fcntl.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

queue_t *test_pathfind(int y, int x, int *xn, int *yn){
	int range = 29;
    int eY = 510;
    int eX = 540;
	queue_t *q = queue_create();
	int prevC[range][range];
	int prevR[range][range];
	int sX, sY, m, n;
	int ePos = range/2;

	for(m=0; m<range; m++){
		for(n=0; n<range; n++){
			prevC[m][n] = -1;
			prevR[m][n] = -1;
		}
	}

	sX = ePos + (x - eX);
	sY = ePos + (y - eY);
	queue_push(q, 0, sX, sY, -1, -1);
	
	while(!queue_empty(q)){
		tile_t *t = queue_top(q);
		int currC = t->x;
		int currR = t->y;
		int tCost = t->cost;
		if(prevR[currR][currC] != -1){
			queue_pop(q);
			continue;
		}
		prevC[currR][currC] = t->xPrev;
		prevR[currR][currC] = t->yPrev;
		queue_pop(q);

		if(currC == ePos && currR == ePos){
			*xn -= (currC - prevC[currR][currC]);
			*yn -= (currR - prevR[currR][currC]);
			return q;
		}
			
		if((currR-1 >= 0 && currC-1 >= 0) && (prevC[currR-1][currC-1] == -1)){
			if(tCost < range)
				queue_push(q, tCost+1, currC-1, currR-1, currC, currR);
		}
		if((currR-1 >= 0 && currC+1 < range) && (prevC[currR-1][currC+1] == -1)){
			if(tCost < range)
				queue_push(q, tCost+1, currC+1, currR-1, currC, currR);
		}
		if((currR+1 < range && currC-1 >= 0) && (prevC[currR+1][currC-1] == -1)){
			if(tCost < range)
				queue_push(q, tCost+1, currC-1, currR+1, currC, currR);
		}
		if((currR+1 < range && currC+1 < range) && (prevC[currR+1][currC+1] == -1)){
			if(tCost < range)
				queue_push(q, tCost+1, currC+1, currR+1, currC, currR);
		}
		if((currR-1 >= 0) && (prevC[currR-1][currC] == -1)){
			if(tCost < range)
				queue_push(q, tCost+1, currC, currR-1, currC, currR);
		}
		if((currC-1 >= 0) && (prevC[currR][currC-1] == -1)){
			if(tCost < range)
				queue_push(q, tCost+1, currC-1, currR, currC, currR);
		}
		if((currR+1 < range) && (prevC[currR+1][currC] == -1)){
			if(tCost < range)
				queue_push(q, tCost+1, currC, currR+1, currC, currR);
		}
		if((currC+1 < range) && (prevC[currR][currC+1] == -1)){
			if(tCost < range)
				queue_push(q, tCost+1, currC+1, currR, currC, currR);
		}
	}
	return q;
}

int main(int argc, char *argv[]){
    int a = 10;
    int b = 10;
    if(argc >= 3){
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }
    int x = 0;
    int y = 0;
    struct timespec start;
    struct timespec end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    struct queue *q = test_pathfind(510 - a, 540 - b, &x, &y); /*allows the difference between the character and enemy to be modified to test the time*/
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Time Elapsed: %f\n", ((end.tv_nsec - start.tv_nsec) / 1000000000.0)); /*displays the time in seconds*/
    queue_clear(q);
    return 0;
}
