*James Bonadonna (jbonadon), Ana Lamberto (alamber2), Sean Michalec (smichale)*

*Testing README, has data to show the memory and timing information for the pathfinding implementation in the dungeon crawler*

        Linear       |     Dijkstra's
 --------------------|-------------------
        0.000001     |     0.001000
        0.000001     |     0.001015
        0.000001     |     0.000985
        0.000000     |     0.000983
        0.000001     |     0.000979
        0.000000     |     0.000988
        0.000001     |     0.000987
        0.000000     |     0.000992
        0.000001     |     0.001003
        0.000000     |     0.000994
        0.000001     |     0.000985
        0.000001     |     0.001068
        0.000001     |     0.001014
        0.000001     |     0.000549
        0.000002     |     0.000990
        0.000001     |     0.000981
        0.000001     |     0.001007
        0.000001     |     0.000992
        0.000001     |     0.000999
        0.000001     |     0.000594
        0.000001     |     0.000999
        0.000001     |     0.000662
        0.000001     |     0.000651
        0.000001     |     0.000663
        0.000001     |     0.000631
        0.000001     |     0.000631
        0.000001     |     0.000464
        0.000001     |     0.000650
        0.000002     |     0.000619
        0.000002     |     0.000612
        0.000001     |     0.000669
        0.000001     |     0.000656
        0.000002     |     0.000644
        0.000002     |     0.000733
        0.000001     |     0.000634
        0.000001     |     0.000360
        0.000002     |     0.000639
        0.000002     |     0.000662
        0.000001     |     0.000645
        0.000002     |     0.000349
        0.000001     |     0.000146
        0.000001     |     0.000152
        0.000001     |     0.000155
        0.000001     |     0.000149
        0.000001     |     0.000076
        0.000001     |     0.000137
        0.000001     |     0.000144
        0.000001     |     0.000147
        0.000001     |     0.000147
                     |
AVG:    0.000001     |     0.000683

Distance between the player and enemy for the Dijkstra measurement was varied between 15 and 1 in order to get a true average time to calculate the shortest distance.

Times for the linear measurement were determined by putting timing calls into the original code with linear pathfinding in order to determine the difference between the two.

Despite the fact that the Dijkstra pathfinding took much longer than the linear pathfinding, the fact that it still ran, on average, in less than 1/1000 of a second means that it is a viable implementation of pathfinding, and that it can perform in the program without a noticeable dropoff in the time between player turns.


10:46 PM|testing|$ valgrind --leak-check=full ./test 
==23031== Memcheck, a memory error detector
==23031== Copyright (C) 2002-2012, and GNU GPL'd, by Julian Seward et al.
==23031== Using Valgrind-3.8.1 and LibVEX; rerun with -h for copyright info
==23031== Command: ./test
==23031== 

Time Elapsed: 0.032014

==23031== 
==23031== HEAP SUMMARY:
==23031==     in use at exit: 0 bytes in 0 blocks
==23031==   total heap usage: 904 allocs, 904 frees, 28,912 bytes allocated
==23031== 
==23031== All heap blocks were freed -- no leaks are possible
==23031== 
==23031== For counts of detected and suppressed errors, rerun with: -v
==23031== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 8 from 6)

The memory allocated by the queue and pathfinding programs is all free'd and allocated correctly, meaning that the code added to the dungeoncrawler has no memory leaks.
