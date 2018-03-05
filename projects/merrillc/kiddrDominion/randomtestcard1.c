/********************************************************************
* Random test for Smithy card in dominion.c
*********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void testSmithy() {
	struct gameState pre, post;
	int i, j, numPlayer, player, handSize, smithyPos, actualGainedCards, failed;
	int seed = 1500,
		numTests = 10000,
        choice1 = 0, 
		choice2 = 0, 
		choice3 = 0, 
		bonus = 0, 
		gainedCards = 3, 
		discarded = 1, 
		minPlayers = 2,
		testOneFailed = 0,
		testTwoFailed = 0,
		testThreeFailed = 0,
		testFourFailed = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
					sea_hag, tribute, smithy, council_room};
	
	//Test loop
	for (i = 0; i < numTests; i++) {
		//Generate random number of players between 2 and MAX_PLAYERS
		numPlayer = rand() % (MAX_PLAYERS - 1) + minPlayers;
		
		//Clear game state and initialize a new game
		memset(&pre, 23, sizeof(struct gameState));  
		initializeGame(numPlayer, k, seed, &pre); 
		
		//Generate a random player's turn
		player = rand() % numPlayer;
		
		//Generate random number of cards in that player's hand
		handSize = rand() % (MAX_HAND - 1) + 1; 
		
		//Generate a random handPos for Smithy card
		smithyPos = rand() % handSize;
		
		//Create and populate the player's hand
		int *testHand = (int*)malloc(sizeof(int)*handSize);
		for(j = 0; j < handSize; j++) {
			//Smithy goes into eandomly generated position, all other cards are curses
			if (j == smithyPos) 
				testHand[j] = smithy;
			else 
				testHand[j] = curse;
		}
		
		//Update Game State to include the randomly generated values
		pre.whoseTurn = player;
		pre.handCount[player] = handSize;
		memcpy(pre.hand[player], testHand, sizeof(int)*handSize);
		
		//Copy game state to test case
		memcpy(&post, &pre, sizeof(struct gameState));
		
		//Play the Smithy card
		cardEffect(smithy, choice1, choice2, choice3, &post, smithyPos, &bonus);
		
		//TEST 1: +3 cards to players hand
		if(post.handCount[player] != pre.handCount[player] + gainedCards - discarded) {
			printf("TEST %d: FAIL: +3 Cards To Player's Hand - Expected Hand Size: %d, Recieved Hand Size: %d\n", i, pre.handCount[player] + gainedCards - discarded, post.handCount[player]);
			testOneFailed = 1;
		}
		//TEST 2: Gained cards should come from player's deck
		actualGainedCards = post.handCount[player] - pre.handCount[player] + discarded;
		
		if (post.deckCount[player] != pre.deckCount[player] - actualGainedCards) {
			printf("TEST %d: FAIL: Cards Came From Player's Deck - Expected Deck Size: %d, Recieved Deck Size: %d\n", i, pre.deckCount[player] - actualGainedCards, post.deckCount[player]);
			testTwoFailed = 1;
		}
		//TEST 3: Other player's states should be unchanged
		for(j = 0; j < numPlayer; j++) {
			if (j != player) {
				if (pre.handCount[j] != post.handCount[j] || pre.deckCount[j] != post.deckCount[j] || pre.discardCount[j] != post.discardCount[j]) {
					printf("TEST %d: FAIL: State changed for player %d\n", i, j);
					testThreeFailed = 1;
				}
			}
		}
		
		//TEST 4: All other card piles should be unchanged
		failed = 0;
		
		//Check victory cards, curse and coin cards piles first
		for (j = 0; j < 27; j++) {
			if (supplyCount(j, &pre) != supplyCount(j, &post))
				failed = 1;
		}		
		
		//Print test results
		if (failed == 1) {
			printf("TEST %d: FAIL: Supply Piles - One or more supply counts changed\n", i);
			testThreeFailed = 1;
		}
		
		//Free allocated memory
		free(testHand);
	}
	
	//Print all tests passed if applicable
	if (testOneFailed == 0 && testTwoFailed == 0 && testThreeFailed == 0 && testFourFailed == 0) {
		printf("ALL TESTS PASSED!\n");
	}
}

int main() {
	testSmithy();
	return 0;
}