/********************************************************************
* Unit test for whoseTurn() in dominion.c
*********************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

void testWhoseTurn() {
	int i, j;
	int seed = 1500;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	int player;
	
	//Check every combination of player turns for all possible numbers of players 
	for (i = 2; i <= MAX_PLAYERS; i++) {
		for (j = 0; j < numPlayer; j++) {
			//Clear game state and initialize a new game
			memset(&G, 23, sizeof(struct gameState));  
			initializeGame(i, k, seed, &G); 
			
			//Set whoseTurn to j
			G.whoseTurn = j;
			
			//Verify that it is player j's turn
			player = whoseTurn(&G);
			
			//Print results
			if (player == j) 
				printf("PASS: Number of Players: %d - Expected Player: %d, Recieved Player: %d\n", numPlayer, j, player);
			else 
				printf("FAIL: Number of Players: %d - Expected Player: %d, Recieved Player: %d\n", numPlayer, j, player);
		}
		//Increase number of players
		numPlayer++;
	}
}

int main() {
	testWhoseTurn();
	return 0;
}