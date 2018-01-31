CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

#To run playdom you need to enter: ./playdom <any integer number> like ./playdom 10*/
playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
	
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

#Unit Tests	 for Assignment 3
unittestresults.out: unittest1.c unittest2.c unittest3.c rngs.c dominion.c
	echo "*** UNIT TEST RESULTS ***" > unittestresults.out

	echo "-----------------------------------------------------" >> unittestresults.out
	echo -e "\nunittest1.c: getCost()\n" >> unittestresults.out
	gcc -o unittest1 rngs.c dominion.c unittest1.c $(CFLAGS)
	unittest1 >> unittestresults.out
	echo -e "\nUnit Test 1 Coverage:\n" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "-----------------------------------------------------" >> unittestresults.out
	echo -e "\nunittest2.c: isGameOver()\n" >> unittestresults.out
	gcc -o unittest2 rngs.c dominion.c unittest2.c $(CFLAGS)
	unittest2 >> unittestresults.out
	echo -e "\nUnit Test 2 Coverage:\n" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "-----------------------------------------------------" >> unittestresults.out
	echo -e "\nunittest3.c: whoseTurn()\n" >> unittestresults.out
	gcc -o unittest3 rngs.c dominion.c unittest3.c $(CFLAGS)
	unittest3 >> unittestresults.out
	echo -e "\nUnit Test 3 Coverage:\n" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "-----------------------------------------------------" >> unittestresults.out
	echo -e "\nunittest4.c: scoreFor()\n" >> unittestresults.out
	gcc -o unittest4 rngs.c dominion.c unittest4.c $(CFLAGS)
	unittest4 >> unittestresults.out
	echo -e "\nUnit Test 4 Coverage:\n" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "-----------------------------------------------------" >> unittestresults.out
	echo -e "\ncardtest1.c: Smithy\n" >> unittestresults.out
	gcc -o cardtest1 rngs.c dominion.c cardtest1.c $(CFLAGS)
	cardtest1 >> unittestresults.out
	echo -e "\nCard Test 1 Coverage:\n" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "-----------------------------------------------------" >> unittestresults.out
	echo -e "\ncardtest2.c: Adventurer\n" >> unittestresults.out
	gcc -o cardtest2 rngs.c dominion.c cardtest2.c $(CFLAGS)
	cardtest2 >> unittestresults.out
	echo -e "\nCard Test 2 Coverage:\n" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "-----------------------------------------------------" >> unittestresults.out
	echo -e "\ncardtest3.c: Village\n" >> unittestresults.out
	gcc -o cardtest3 rngs.c dominion.c cardtest3.c $(CFLAGS)
	cardtest3 >> unittestresults.out
	echo -e "\nCard Test 3 Coverage:\n" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "-----------------------------------------------------" >> unittestresults.out
	echo -e "\ncardtest4.c: Council Room\n" >> unittestresults.out
	gcc -o cardtest4 rngs.c dominion.c cardtest4.c $(CFLAGS)
	cardtest4 >> unittestresults.out
	echo -e "\nCard Test 4 Coverage:\n" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
