/********************************************************************
* Random test for Adventurer card in dominion.c
*********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void testAdventurer() {
	struct gameState pre, post;
	int i, j, numPlayer, player, handSize, deckSize, adventurerPos, failed, kingdomOrVictory, randCard;
	int seed = 1500,
		numTests = 10000,
        choice1 = 0, 
		choice2 = 0, 
		choice3 = 0, 
		bonus = 0, 
		gainedCards = 2, 
		discarded = 1, 
		discardSize = 2,
		minPlayers = 2,
		testOneFailed = 0,
		testTwoFailed = 0,
		testThreeFailed = 0,
		testFourFailed = 0,
		testFiveFailed = 0;
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
		
		//Generate random number of cards in that player's deck
		deckSize = rand() % MAX_DECK;
		
		//Generate a random handPos for Adventurer card
		adventurerPos = rand() % handSize;
		
		//Create and populate the player's hand
		int *testHand = (int*)malloc(sizeof(int)*handSize);
		for(j = 0; j < handSize; j++) {
			//Adventurer goes into eandomly generated position, all other cards are curses
			if (j == adventurerPos) 
				testHand[j] = adventurer;
			else 
				testHand[j] = curse;
		}
		
		//Create and populate the players deck
		int *testDeck = (int*)malloc(sizeof(int)*deckSize);
		for(j = 0; j < deckSize; j++) {
			//Populate the deck with random cards
			kingdomOrVictory = rand() % 2;
			
			if (kingdomOrVictory == 0) {
				//Add a random victory card
				randCard = rand() % 7;
				
				testDeck[j] = randCard;
			}
			else {
				//Add a random kingdom card
				randCard = rand() % 10;
				
				testDeck[j] = k[randCard];
			}		
		}
		
		//In case there are no treasure cards in deck, add two to starting discard pile
		int *testDiscard = (int*)malloc(sizeof(int)*discardSize);
		testDiscard[0] = copper;
		testDiscard[1] = copper;

		//Update Game State to include the randomly generated values
		pre.whoseTurn = player;
		pre.handCount[player] = handSize;
		pre.deckCount[player] = deckSize;
		pre.discardCount[player] = discardSize;
		memcpy(pre.hand[player], testHand, sizeof(int)*handSize);
		memcpy(pre.deck[player], testDeck, sizeof(int)*deckSize);
		memcpy(pre.discard[player], testDiscard, sizeof(int)*discardSize);
		
		//Copy game state to test case
		memcpy(&post, &pre, sizeof(struct gameState));
		
		//Play the Adventurer card
		cardEffect(adventurer, choice1, choice2, choice3, &post, adventurerPos, &bonus);
		
		//TEST 1: +2 cards to players hand
		if (post.handCount[player] != pre.handCount[player] + gainedCards - discarded) {
			printf("TEST %d: FAIL: +2 Cards To Player's Hand - Expected Hand Size: %d, Recieved Hand Size: %d\n", i, pre.handCount[player] + gainedCards - discarded, post.handCount[player]);
			testOneFailed = 1;
		}
		
		//TEST 2: +2 cards are treasure cards
		if (post.hand[player][post.handCount[player] - 2] != 4 && post.hand[player][post.handCount[player] - 2] != 5 && post.hand[player][post.handCount[player] - 2] != 6) {
			printf("TEST %d: FAIL: First Acquired Card Is Not Treasure\n", i);
			testTwoFailed = 1;
		}	
		if (post.hand[player][post.handCount[player] - 1] != 4 && post.hand[player][post.handCount[player] - 1] != 5 && post.hand[player][post.handCount[player] - 1] != 6) {
			printf("TEST %d: FAIL: Second Acquired Card Is Not Treasure\n", i);
			testTwoFailed = 1;
		}
			
		
		//TEST 3: Net sum of player's cards remains the same
		if ((pre.handCount[player] + pre.deckCount[player] + pre.discardCount[player]) != (post.handCount[player] + post.deckCount[player] + post.discardCount[player])) {
			printf("TEST %d: FAIL: Net sum of player's cards differs\n", i);
			testThreeFailed = 1;
		}
		
		//TEST 4: Other player's states should be unchanged
		for(j = 0; j < numPlayer; j++) {
			if (j != player) {
				if (pre.handCount[j] != post.handCount[j] || pre.deckCount[j] != post.deckCount[j] || pre.discardCount[j] != post.discardCount[j]) {
					printf("TEST %d: FAIL: State changed for player %d\n", i, j);
					testFourFailed = 1;
				}
			}
		}
		
		//TEST 5: All other card piles should be unchanged
		failed = 0;
		
		//Check victory cards, curse and coin cards piles first
		for (j = 0; j < 27; j++) {
			if (supplyCount(j, &pre) != supplyCount(j, &post))
				failed = 1;
		}		
		
		//Print test results
		if (failed == 1) {
			printf("TEST %d: FAIL: Supply Piles - One or more supply counts changed\n", i);
			testFiveFailed = 1;
		}
		
		//Free allocated memory
		free(testHand);
		free(testDeck);
	}
	
	//Print all tests passed if applicable
	if (testOneFailed == 0 && testTwoFailed == 0 && testThreeFailed == 0 && testFourFailed == 0 && testFiveFailed == 0) {
		printf("ALL TESTS PASSED!\n");
	}
}

int main() {
	testAdventurer();
	return 0;
}