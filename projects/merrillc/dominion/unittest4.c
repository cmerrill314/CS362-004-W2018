/********************************************************************
* Unit test for scoreFor() in dominion.c
*********************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

void testScoreFor() {
	int i, p, handCount, deckCount, discardCount, expectedScore, actualScore
	, passed, cursePassed, estatePassed, duchyPassed, provincePassed
	, greatHallPassed, gardensPassed;
	
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
			   
	int seed = 1500;
    int numPlayer = 2;
	int maxHand = 10;      
	int maxDeck = 10;
	int maxDiscard = 10;
	struct gameState G;
	
	//Initialize arrays of each score-effecting card
	int curses[MAX_HAND];
	int estates[MAX_HAND];
	int duchies[MAX_HAND];
	int provinces[MAX_HAND];
	int greatHalls[MAX_HAND];
	int gardensTwo[MAX_HAND];
	
	for (i = 0; i < MAX_HAND; i++) {
		curses[i] = curse;
		estates[i] = estate;
		duchies[i] = duchy;
		provinces[i] = province;
		greatHalls[i] = great_hall;
		gardensTwo[i] = gardens;
	}
	
	/********************************************************************
	* TEST 1: SCORE FROM HAND
	*********************************************************************/
	//Initialize all passed values to true
	passed = 1;
	cursePassed = 1;
	estatePassed = 1;
	duchyPassed = 1;
	provincePassed = 1;
	greatHallPassed = 1;
	gardensPassed = 1;
	
	for (p = 0; p < numPlayer; p++) {	
		for (handCount = 1; handCount <= maxHand; handCount++) {
			//Clear game state and initialize a new game
			memset(&G, 23, sizeof(struct gameState));  
			initializeGame(numPlayer, k, seed, &G); 
			
			//Initialize counts
			G.handCount[p] = handCount;
			G.deckCount[p] = 0;
			G.discardCount[p] = 0;
			
			/* --- CURSE TEST --- */
			
			//Set all cards to curses
			memcpy(G.hand[p], curses, sizeof(int) * handCount); 
			
			//Calculate expected and actual scores
			expectedScore = -1 * handCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				passed = 0;
				cursePassed = 0;
			}
			
			/* --- ESTATE TEST --- */
				
			//Set all cards to estates
			memcpy(G.hand[p], estates, sizeof(int) * handCount); 
			
			//Calculate expected and actual scores
			expectedScore = handCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				passed = 0;
				estatePassed = 0;
			}
			
			/* --- DUCHY TEST --- */
			
			//Set all cards to duchies
			memcpy(G.hand[p], duchies, sizeof(int) * handCount); 
			
			//Calculate expected and actual scores
			expectedScore = 3 * handCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore)  {
				duchyPassed = 0;
				passed = 0;
			}
			
			/* --- PROVINCE TEST --- */
			
			//Set all cards to provinces
			memcpy(G.hand[p], provinces, sizeof(int) * handCount); 
			
			//Calculate expected and actual scores
			expectedScore = 6 * handCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				provincePassed = 0;
				passed = 0;
			}
			
			/* --- GREAT HALL TEST --- */
			
			//Set all cards to great halls
			memcpy(G.hand[p], greatHalls, sizeof(int) * handCount); 
			
			//Calculate expected and actual scores
			expectedScore = handCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				greatHallPassed = 0;
				passed = 0;
			}
			
			/* --- GARDENS TEST --- */
			
			//Set all cards to gardens
			memcpy(G.hand[p], gardensTwo, sizeof(int) * handCount); 
			
			//Calculate expected and actual scores		
			expectedScore = handCount * (fullDeckCount(p, gardens, &G) / 10);
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				passed = 0;
				gardensPassed = 0;
			}
		}
	}
	
	//Print Test Results
	if (passed == 1) 
		printf("PASS: Score from hand correct for both players for all victory card types\n");
	else {
		printf("FAIL: Score from hand incorrect for the following cards:\n");
		
		if (cursePassed == 0)
			printf("- Curse\n");
		if (estatePassed == 0)
			printf("- Estate\n");
		if (duchyPassed == 0)
			printf("- Duchy\n");
		if (provincePassed == 0)
			printf("- Province\n");
		if (greatHallPassed == 0)
			printf("- Great Hall\n");
		if (gardensPassed == 0)
			printf("- Gardens\n");
	}
		
	/********************************************************************
	* TEST 2: SCORE FROM DISCARD
	*********************************************************************/
	//Initialize all passed values to true
	passed = 1;
	cursePassed = 1;
	estatePassed = 1;
	duchyPassed = 1;
	provincePassed = 1;
	greatHallPassed = 1;
	gardensPassed = 1;
	
	for (p = 0; p < numPlayer; p++) {	
		for (discardCount = 0; discardCount <= maxDiscard; discardCount++) {
			//Clear game state and initialize a new game
			memset(&G, 23, sizeof(struct gameState));  
			initializeGame(numPlayer, k, seed, &G); 
			
			//Initialize counts
			G.handCount[p] = 0;
			G.deckCount[p] = 0;
			G.discardCount[p] = discardCount;
			
			/* --- CURSE TEST --- */
			
			//Set all cards to curses
			memcpy(G.discard[p], curses, sizeof(int) * discardCount); 
			
			//Calculate expected and actual scores
			expectedScore = -1 * discardCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				passed = 0;
				cursePassed = 0;
			}
			
			/* --- ESTATE TEST --- */
			
			//Set all cards to estates
			memcpy(G.discard[p], estates, sizeof(int) * discardCount); 
			
			//Calculate expected and actual scores
			expectedScore = discardCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				passed = 0;
				estatePassed = 0;
			}
			
			/* --- DUCHY TEST --- */
			
			//Set all cards to duchies
			memcpy(G.discard[p], duchies, sizeof(int) * discardCount); 
			
			//Calculate expected and actual scores
			expectedScore = 3 * discardCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore)  {
				duchyPassed = 0;
				passed = 0;
			}
			
			/* --- PROVINCE TEST --- */
			
			//Set all cards to provinces
			memcpy(G.discard[p], provinces, sizeof(int) * discardCount); 
			
			//Calculate expected and actual scores
			expectedScore = 6 * discardCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				provincePassed = 0;
				passed = 0;
			}
			
			/* --- GREAT HALL TEST --- */
			
			//Set all cards to great halls
			memcpy(G.discard[p], greatHalls, sizeof(int) * discardCount); 
			
			//Calculate expected and actual scores
			expectedScore = discardCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				greatHallPassed = 0;
				passed = 0;
			}
			
			/* --- GARDENS TEST --- */
			
			//Set all cards to gardens
			memcpy(G.discard[p], gardensTwo, sizeof(int) * discardCount); 
			
			//Calculate expected and actual scores
			expectedScore = discardCount * (fullDeckCount(p, gardens, &G) / 10);
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				passed = 0;
				gardensPassed = 0;
			}			
		}
	}
	
	//Print Test Results
	if (passed == 1) 
		printf("PASS: Score from discard correct for both players for all victory card types\n");
	else {
		printf("FAIL: Score from discard incorrect for the following cards:\n");
		
		if (cursePassed == 0)
			printf("- Curse\n");
		if (estatePassed == 0)
			printf("- Estate\n");
		if (duchyPassed == 0)
			printf("- Duchy\n");
		if (provincePassed == 0)
			printf("- Province\n");
		if (greatHallPassed == 0)
			printf("- Great Hall\n");
		if (gardensPassed == 0)
			printf("- Gardens\n");
	}
	
	/********************************************************************
	* TEST 3: SCORE FROM DECK
	*********************************************************************/
	//Initialize all passed values to true
	passed = 1;
	cursePassed = 1;
	estatePassed = 1;
	duchyPassed = 1;
	provincePassed = 1;
	greatHallPassed = 1;
	gardensPassed = 1;
	
	for (p = 0; p < numPlayer; p++) {	
		for (deckCount = 0; deckCount <= maxDeck; deckCount++) {
			//Clear game state and initialize a new game
			memset(&G, 23, sizeof(struct gameState));  
			initializeGame(numPlayer, k, seed, &G); 
			
			//Initialize counts
			G.deckCount[p] = deckCount;
			G.handCount[p] = 0;
			G.discardCount[p] = 0;
			
			/* --- CURSE TEST --- */
			
			//Set all cards to curses
			memcpy(G.deck[p], curses, sizeof(int) * deckCount);  
			
			//Calculate expected and actual scores
			expectedScore = -1 * deckCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				passed = 0;
				cursePassed = 0;
			}
			/* --- ESTATE TEST --- */
			
			//Set all cards to estates
			memcpy(G.deck[p], estates, sizeof(int) * deckCount); 
			
			//Calculate expected and actual scores
			expectedScore = deckCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				passed = 0;
				estatePassed = 0;
			}
			
			/* --- DUCHY TEST --- */
			
			//Set all cards to duchies
			memcpy(G.deck[p], duchies, sizeof(int) * deckCount);  
			
			//Calculate expected and actual scores
			expectedScore = 3 * deckCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore)  {
				duchyPassed = 0;
				passed = 0;
			}
			
			/* --- PROVINCE TEST --- */
			
			//Set all cards to provinces
			memcpy(G.deck[p], provinces, sizeof(int) * deckCount); 
			
			//Calculate expected and actual scores
			expectedScore = 6 * deckCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				provincePassed = 0;
				passed = 0;
			}
			
			/* --- GREAT HALL TEST --- */
			
			//Set all cards to great halls
			memcpy(G.deck[p], greatHalls, sizeof(int) * deckCount); 
			
			//Calculate expected and actual scores
			expectedScore = deckCount;
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				greatHallPassed = 0;
				passed = 0;
			}
			
			/* --- GARDENS TEST --- */
			
			//Set all cards to gardens
			memcpy(G.deck[p], gardensTwo, sizeof(int) * deckCount); 
			
			//Calculate expected and actual scores
			expectedScore = deckCount * (fullDeckCount(p, gardens, &G) / 10);
			actualScore = scoreFor(p, &G);
			
			//If expected/actual scores don't match, the test failed
			if (actualScore != expectedScore) {
				passed = 0;
				gardensPassed = 0;
			}
		}
	}
	
	//Print Test Results
	if (passed == 1) 
		printf("PASS: Score from deck correct for both players for all victory card types\n");
	else {
		printf("FAIL: Score from deck incorrect for the following cards:\n");
		
		if (cursePassed == 0)
			printf("- Curse\n");
		if (estatePassed == 0)
			printf("- Estate\n");
		if (duchyPassed == 0)
			printf("- Duchy\n");
		if (provincePassed == 0)
			printf("- Province\n");
		if (greatHallPassed == 0)
			printf("- Great Hall\n");
		if (gardensPassed == 0)
			printf("- Gardens\n");
	}
	
	/********************************************************************
	* TEST 4: COMBINED SCORE (FROM HAND, DISCARD and DECK)
	*********************************************************************/
	//Initialize all passed values to true
	passed = 1;
	cursePassed = 1;
	estatePassed = 1;
	duchyPassed = 1;
	provincePassed = 1;
	greatHallPassed = 1;
	gardensPassed = 1;
	
	for (p = 0; p < numPlayer; p++) {	
		for (handCount = 1; handCount <= maxHand; handCount++) {
			for (deckCount = 0; deckCount <= maxDeck; deckCount++) {
				for (discardCount = 0; discardCount <= maxDiscard; discardCount++) {
					//Clear game state and initialize a new game
					memset(&G, 23, sizeof(struct gameState));  
					initializeGame(numPlayer, k, seed, &G); 
					
					//Initialize counts
					G.handCount[p] = handCount;
					G.deckCount[p] = deckCount;
					G.discardCount[p] = discardCount;
					
					/* --- CURSE TEST --- */
					
					//Set all cards to curses
					memcpy(G.hand[p], curses, sizeof(int) * handCount); 
					memcpy(G.deck[p], curses, sizeof(int) * deckCount); 
					memcpy(G.discard[p], curses, sizeof(int) * discardCount); 
					
					//Calculate expected and actual scores
					expectedScore = -1 * (handCount + deckCount + discardCount);
					actualScore = scoreFor(p, &G);
					
					//If expected/actual scores don't match, the test failed
					if (actualScore != expectedScore) {
						passed = 0;
						cursePassed = 0;
					}
					
					/* --- ESTATE TEST --- */
					
					//Set all cards to estates
					memcpy(G.hand[p], estates, sizeof(int) * handCount); 
					memcpy(G.deck[p], estates, sizeof(int) * deckCount); 
					memcpy(G.discard[p], estates, sizeof(int) * discardCount); 
					
					//Calculate expected and actual scores
					expectedScore = handCount + deckCount + discardCount;
					actualScore = scoreFor(p, &G);
					
					//If expected/actual scores don't match, the test failed
					if (actualScore != expectedScore) {
						passed = 0;
						estatePassed = 0;
					}
					
					/* --- DUCHY TEST --- */
					
					//Set all cards to duchies
					memcpy(G.hand[p], duchies, sizeof(int) * handCount); 
					memcpy(G.deck[p], duchies, sizeof(int) * deckCount); 
					memcpy(G.discard[p], duchies, sizeof(int) * discardCount); 
					
					//Calculate expected and actual scores
					expectedScore = 3 * (handCount + deckCount + discardCount);
					actualScore = scoreFor(p, &G);
					
					//If expected/actual scores don't match, the test failed
					if (actualScore != expectedScore)  {
						duchyPassed = 0;
						passed = 0;
					}
					
					/* --- PROVINCE TEST --- */
					
					//Set all cards to provinces
					memcpy(G.hand[p], provinces, sizeof(int) * handCount); 
					memcpy(G.deck[p], provinces, sizeof(int) * deckCount); 
					memcpy(G.discard[p], provinces, sizeof(int) * discardCount); 
					
					//Calculate expected and actual scores
					expectedScore = 6 * (handCount + deckCount + discardCount);
					actualScore = scoreFor(p, &G);
					
					//If expected/actual scores don't match, the test failed
					if (actualScore != expectedScore) {
						provincePassed = 0;
						passed = 0;
					}
					
					/* --- GREAT HALL TEST --- */
					
					//Set all cards to great halls
					memcpy(G.hand[p], greatHalls, sizeof(int) * handCount); 
					memcpy(G.deck[p], greatHalls, sizeof(int) * deckCount); 
					memcpy(G.discard[p], greatHalls, sizeof(int) * discardCount); 
					
					//Calculate expected and actual scores
					expectedScore = handCount + deckCount + discardCount;
					actualScore = scoreFor(p, &G);
					
					//If expected/actual scores don't match, the test failed
					if (actualScore != expectedScore) {
						greatHallPassed = 0;
						passed = 0;
					}
					
					/* --- GARDENS TEST --- */
					
					//Set all cards to gardens
					memcpy(G.hand[p], gardensTwo, sizeof(int) * handCount); 
					memcpy(G.deck[p], gardensTwo, sizeof(int) * deckCount); 
					memcpy(G.discard[p], gardensTwo, sizeof(int) * discardCount); 
					
					//Calculate expected and actual scores
					expectedScore = (handCount + discardCount + deckCount) * (fullDeckCount(p, gardens, &G) / 10);
					actualScore = scoreFor(p, &G);
					
					//If expected/actual scores don't match, the test failed
					if (actualScore != expectedScore) {
						passed = 0;
						gardensPassed = 0;
					}
				}
			}
		}
	}
	
	//Print Test Results
	if (passed == 1) 
		printf("PASS: Score from hand, discard and deck combined correct for both players for all victory card types\n");
	else {
		printf("FAIL: Score from hand, discard and deck combined incorrect for the following cards:\n");
		
		if (cursePassed == 0)
			printf("- Curse\n");
		if (estatePassed == 0)
			printf("- Estate\n");
		if (duchyPassed == 0)
			printf("- Duchy\n");
		if (provincePassed == 0)
			printf("- Province\n");
		if (greatHallPassed == 0)
			printf("- Great Hall\n");
		if (gardensPassed == 0)
			printf("- Gardens\n");
	}
}

int main() {
	testScoreFor();
	return 0;
}