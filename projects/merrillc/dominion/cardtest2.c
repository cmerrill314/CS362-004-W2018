/********************************************************************
* Unit test for Adventurer card in dominion.c
*********************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void testAdventurer() {
	int i, j;
	int seed = 1500;
    int numPlayer = 2;
    int player = 0;
	int newCards = 0;
    int discarded = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int handSize, prevHandSize, deckSize, prevDeckSize, prevDiscardSize, 
		discardSize, prevSupplyCount, postSupplyCount, supplyPassed, testOnePassed;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
					sea_hag, tribute, smithy, council_room};
					
	//Test arrays for each type of treasure card
	int coppers[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];
	
	//Populate test arrays
	for (i = 0; i < 6; i++) {
		//Add treasure cards at positions 0 and 3
		if (i == 0 || i == 3) {
			coppers[i] = copper;
			silvers[i] = silver;
			golds[i] = gold;
		}
		//Add non-treasure cards between
		else {
			coppers[i] = estate;
			silvers[i] = estate;
			golds[i] = estate;
		}
	}
	
	//Go through main test loop 3 times (for copper, silver, and gold scenarios)
	for (i = 0; i < 3; i++) {
		//Clear game state and initialize a new game
		memset(&G, 23, sizeof(struct gameState));
		memset(&testG, 23, sizeof(struct gameState));  		
		initializeGame(numPlayer, k, seed, &G); 
		player = 0;
		
		//Copy game state to test case
		memcpy(&testG, &G, sizeof(struct gameState));
		
		//Copper scenario
		if (i == 0) {
			printf("***COPPER TESTS***\n\n");
			
			//Populate player's hand with copper deck
			memcpy(testG.deck[player], coppers, sizeof(int) * 6); 
		}
		//Silver scenario
		else if (i == 1) {
			printf("\n***SILVER TESTS***\n\n");
			
			//Populate player's hand with silver deck
			memcpy(testG.deck[player], silvers, sizeof(int) * 6); 
		}
		//Gold scenario
		else {
			printf("\n***GOLD TESTS***\n\n");
			
			//Populate player's hand with silver deck
			memcpy(testG.deck[player], golds, sizeof(int) * 6); 
		}
		
		//Call cardEffect for adventurer
		cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
		
		/********************************************************************
		* TEST 1: +2 Treasure Cards To Player's Hand
		*********************************************************************/
		
		//Calculate handCount before and after running cardEffect
		prevHandSize = G.handCount[player];
		handSize = testG.handCount[player];
		newCards = 2;
		
		//Print test results
		if (handSize == (prevHandSize + newCards - discarded)) {
			printf("PASS: +2 Cards To Players Hand - Expected Hand Size: %d, Recieved Hand Size: %d\n", prevHandSize + newCards - discarded, handSize);
			testOnePassed = 1;
		}
		else {
			printf("FAIL: +2 Cards To Players Hand - Expected Hand Size: %d, Recieved Hand Size: %d\n", prevHandSize + newCards - discarded, handSize);
			testOnePassed = 0;
		}
			
		
		/********************************************************************
		* TEST 2: +2 Cards Are Treasure Cards
		*********************************************************************/
		
		//Only run this test if Test 1 passed
		if (testOnePassed == 1) {
			//Determine if the cards added to the player's hand are treasure cards
			for (j = testG.handCount[player] - 1; j > testG.handCount[player] - 3; j--) {
				//Examine each drawn card
				if (testG.hand[player][j] == 4 || testG.hand[player][j] == 5 || testG.hand[player][j] == 6)
					printf("PASS: Added Card Is Treasure\n");
				else
					printf("FAIL: Added Card Is Not Treasure\n");
			}
		}
		
		/********************************************************************
		* TEST 3: ALL DRAWN NON-TREASURE CARDS SHOULD BE DISCARDED
		*********************************************************************/
		
		//Calculate Discard pile before/after size
		prevDiscardSize = G.discardCount[player];
		discardSize = testG.discardCount[player];
		
		//Print test results - Discard pile should increase by 4
		if (discardSize == prevDiscardSize + 4) 
			printf("PASS: +4 Cards To Discard Pile - Expected Discard Size: %d, Recieved Discard Size: %d\n", prevDiscardSize, discardSize);
		else 
			printf("FAIL: +4 Cards To Discard Pile - Expected Discard Size: %d, Recieved Discard Size: %d\n", prevDiscardSize, discardSize);
		
		/********************************************************************
		* TEST 4: No State Change For Other Player
		*********************************************************************/
		
		//Switch to other player
		player = 1;
		
		//Calculate other players deck/hand/discard counts before and after playing Smithy
		prevHandSize = G.handCount[player];
		handSize = testG.handCount[player];
		prevDeckSize = G.deckCount[player];
		deckSize = testG.deckCount[player];
		prevDiscardSize = G.handCount[player];
		discardSize = testG.discardCount[player];
		
		//Print Results
		if (handSize == prevHandSize)
			printf("PASS: Other Player's State - Expected Hand Size: %d, Recieved Hand Size: %d\n", prevHandSize, handSize);
		else
			printf("FAIL: Other Player's State - Expected Hand Size: %d, Recieved Hand Size: %d\n", prevHandSize, handSize);
		if (deckSize == prevDeckSize)
			printf("PASS: Other Player's State - Expected Deck Size: %d, Recieved Deck Size: %d\n", prevDeckSize, deckSize);
		else
			printf("FAIL: Other Player's State - Expected Deck Size: %d, Recieved Deck Size: %d\n", prevDeckSize, deckSize);
		if (discardSize == prevDiscardSize)
			printf("PASS: Other Player's State - Expected Discard Size: %d, Recieved Discard Size: %d\n", prevDiscardSize, discardSize);
		else
			printf("FAIL: Other Player's State - Expected Discard Size: %d, Recieved Discard Size: %d\n", prevDiscardSize, discardSize);
		
		/********************************************************************
		* TEST 5: No Change To Remaining Victory/Kingdom Card Piles
		*********************************************************************/
		
		//Initialize supplyPassed to 1
		supplyPassed = 1;
		
		//Check victory cards, curse and coin cards piles first
		for (j = 0; j <= gold; j++) {
			prevSupplyCount = supplyCount(j, &G);
			postSupplyCount = supplyCount(j, &testG);
			
			if (prevSupplyCount != postSupplyCount)
				supplyPassed = 0;
		}
		
		//Next check all playable kingdom cards
		for (j = 0; j < 10; j++) {
			prevSupplyCount = supplyCount(j, &G);
			postSupplyCount = supplyCount(j, &testG);
			
			if (prevSupplyCount != postSupplyCount)
				supplyPassed = 0;
		}
		
		//Print test results
		if (supplyPassed == 1)
			printf("PASS: Supply Piles - All card supplies remained the same\n");
		else
			printf("FAIL: Supply Piles - One or more supply counts changed\n");
	}	
}

int main() {
	testAdventurer();
	return 0;
}