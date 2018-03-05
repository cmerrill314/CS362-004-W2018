/********************************************************************
* Unit test for isGameOver() in dominion.c
*********************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

void testIsGameOver() {
	int p, q, r;
    int seed = 1500;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
	int testsPassed = 1; 
    struct gameState G;
	
	/*------------------------------------ CASE 0: All Card Piles Remain ------------------------------------*/
	
	//Game should not end in this case
	
	//Clear game state and initialize a new game
	memset(&G, 23, sizeof(struct gameState));  
	initializeGame(numPlayer, k, seed, &G); 
	
	//Print results
	if (isGameOver(&G) == 0)
		printf("PASS: Game is not over when all piles remain\n");
	else 
		printf("FAIL: Game is over when all piles remain\n");
	
	
	/*--- CASE 1: Game Ends By Depleting Province Cards (and all other supply cards are not yet depleted) ---*/
	
	//Loop through every possible amount of province cards. If there are 0, the game should end. 
	for (p = 0; p <= 8; p++) {
		//Clear game state and initialize a new game
		memset(&G, 23, sizeof(struct gameState));  
		initializeGame(numPlayer, k, seed, &G); 
		
		//Set province count to 0
		G.supplyCount[3] = p; 
		
		//Game should end when there are 0 province cards
		if (p == 0) {
			if (isGameOver(&G) == 1)
				printf("PASS: Game is over when %d province card(s) remain\n", G.supplyCount[3]);
			else 
				printf("FAIL: Game is not over when %d province card(s) remain\n", G.supplyCount[3]);
		}
		//Game should continue if there are more than 0 province cards
		else {
			if (isGameOver(&G) == 0)
				printf("PASS: Game is not over when %d province card(s) remain\n", G.supplyCount[3]);
			else 
				printf("FAIL: Game is over when %d province card(s) remain\n", G.supplyCount[3]);
		}
	}
	
	/*--------------------------- CASE 2: Game Ends By Depleting Any 3 Supply Piles -------------------------*/
	
	//Loop through every possible combination of 3 depleted piles to assure that isGameOver returns 1 
	for (p = 0; p < 17; p++) {
		for (q = 0; q < 17; q++) {
			for (r = 0; r < 17; r++) {
				//Ignore combinations with province cards and combinations with duplicates
				if (p != 3 && q != 3 && r != 3 && p != q && p != r && q != r) {
					//Clear game state and initialize a new game
					memset(&G, 23, sizeof(struct gameState));  
					initializeGame(numPlayer, k, seed, &G); 
					
					//Set cards p, q, r to 0 supply
					G.supplyCount[p] = 0; 
					G.supplyCount[q] = 0;
					G.supplyCount[r] = 0;
					
					//If test failed, print the failing card combination and set allTestsPassed to false
					if (isGameOver(&G) == 0) {
						printf("FAIL: Game is not over when 3 card piles (%d, %d and %d) are depleted and all other piles remain\n", p, q, r);
						testsPassed = 0;
					}	
				}
			}
		}
	}
	
	//Print results
	if (testsPassed == 1) {
		printf("PASS: Game successfully ends when any combination of 3 supply cards are depleted (this test excludes province cards)\n");
	}
}

int main() {
	testIsGameOver();
	return 0;
}