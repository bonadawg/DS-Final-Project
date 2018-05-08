CC = gcc
CFLAGS = -Wall -g -gdwarf-2 -std=gnu89 -Werror -lrt

test: queue.o test.o
	$(CC) $(CFLAGS) -o $@ $^

queue.o: queue.c
	$(CC) $(CFLAGS) -o $@ -c $<

test.o: test_script.c
	$(CC) $(CFLAGS) -o $@ -c $<	

clean:
	rm *.o test
