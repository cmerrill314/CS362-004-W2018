 /********************************************************************
* Unit test for Village card in dominion.c
*********************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void testVillage() {
	int i;
	int seed = 1500;
    int numPlayer = 2;
    int player = 0;
	int newCards = 0;
    int discarded = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int handSize, prevHandSize, deckSize, prevDeckSize, prevDiscardSize, 
		discardSize, prevSupplyCount, postSupplyCount, supplyPassed, prevActions, actions;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
					sea_hag, tribute, smithy, council_room};
			
	//Clear game state and initialize a new game
	memset(&G, 23, sizeof(struct gameState));  
	initializeGame(numPlayer, k, seed, &G); 
	
	//Copy game state to test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	//Call cardEffect for village
	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	/********************************************************************
	* TEST 1: +1 Card
	*********************************************************************/
	
	//Calculate handCount before and after running cardEffect
	prevHandSize = G.handCount[player];
	handSize = testG.handCount[player];
	newCards = 1;
	
	//Print test results
	if (handSize == (prevHandSize + newCards - discarded))
		printf("PASS: +1 Card To Player's Hand - Expected Hand Size: %d, Recieved Hand Size: %d\n", prevHandSize + newCards - discarded, handSize);
	else
		printf("FAIL: +1 Cards To Player's Hand - Expected Hand Size: %d, Recieved Hand Size: %d\n", prevHandSize + newCards - discarded, handSize);
	
	/********************************************************************
	* TEST 2: +1 Card Comes From Player's Pile
	*********************************************************************/
	
	//Calculate deckCount before and after running cardEffect
	prevDeckSize = G.deckCount[player];
	deckSize = testG.deckCount[player];
	
	//Print test results
	if (deckSize == (prevDeckSize - newCards))
		printf("PASS: -1 Cards From Player's Deck - Expected Deck Size: %d, Recieved Deck Size: %d\n", prevDeckSize - newCards, deckSize);
	else
		printf("FAIL: -1 Cards From Player's Deck - Expected Deck Size: %d, Recieved Deck Size: %d\n", prevDeckSize - newCards, deckSize);
	
	/********************************************************************
	* TEST 3: +2 Actions
	*********************************************************************/
	
	//Calculate the number of actions before/after playing village
	prevActions = G.numActions;
	actions = testG.numActions;
	
	//Print test results
	if (actions == (prevActions + 2))
		printf("PASS: +2 Actions - Expected Actions: %d, Recieved Actions: %d\n", prevActions + 2, actions);
	else
		printf("FAIL: +2 Actions - Expected Actions: %d, Recieved Actions: %d\n", prevActions, actions);
	
	/********************************************************************
	* TEST 4: No State Change For Other Player
	*********************************************************************/
	
	//Change to other player
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
	for (i = 0; i <= gold; i++) {
		prevSupplyCount = supplyCount(i, &G);
		postSupplyCount = supplyCount(i, &testG);
		
		if (prevSupplyCount != postSupplyCount)
			supplyPassed = 0;
	}
	
	//Next check all playable kingdom cards
	for (i = 0; i < 10; i++) {
		prevSupplyCount = supplyCount(i, &G);
		postSupplyCount = supplyCount(i, &testG);
		
		if (prevSupplyCount != postSupplyCount)
			supplyPassed = 0;
	}
	
	//Print test results
	if (supplyPassed == 1)
		printf("PASS: Supply Piles - All card supplies remained the same\n");
	else
		printf("FAIL: Supply Piles - One or more supply counts changed\n");
}

int main() {
	testVillage();
	return 0;
}