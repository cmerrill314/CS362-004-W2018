/********************************************************************
* Unit test for getCost function in dominion.c
*********************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

void testGetCost() {
	//Store the result of passing an invalid card
	int invalidTest = getCost(30);
	
	//Test the case for an invalid card value
	if (invalidTest == -1)
		printf("PASS: Invalid Card Cost - Recieved: %d, Expected: %d\n", invalidTest, -1);
	else 
		printf("FAIL: Invalid Card Cost - Recieved: %d, Expected: %d\n", invalidTest, -1);
	
	//Store the value of running getCost on each valid card type
	int curseCost = getCost(curse);
	int estateCost = getCost(estate);
	int duchyCost = getCost(duchy);
	int provinceCost = getCost(province);
	int copperCost = getCost(copper);
	int silverCost = getCost(silver);
	int goldCost = getCost(gold);
	int adventurerCost = getCost(adventurer);
	int councilRoomCost = getCost(council_room);
	int feastCost = getCost(feast);
	int gardensCost = getCost(gardens);
	int mineCost = getCost(mine);
	int remodelCost = getCost(remodel);
	int smithyCost = getCost(smithy);
	int villageCost = getCost(village);
	int baronCost = getCost(baron);
	int greatHallCost = getCost(great_hall);
	int minionCost = getCost(minion);
	int stewardCost = getCost(steward);
	int tributeCost = getCost(tribute);
	int ambassadorCost = getCost(ambassador);
	int cutpurseCost = getCost(cutpurse);
	int embargoCost = getCost(embargo);
	int outpostCost = getCost(outpost);
	int salvagerCost = getCost(salvager);
	int seaHagCost = getCost(sea_hag);
	int treasureMapCost = getCost(treasure_map);
	
	//Test to make sure that each of recieved card values match the expected values
	if (curseCost == 0)
		printf("PASS: Curse Cost - Recieved: %d, Expected: %d\n", curseCost, 0);
	else 
		printf("FAIL: Curse Cost - Recieved: %d, Expected: %d\n", curseCost, 0);
	if (estateCost == 2)
		printf("PASS: Estate Cost - Recieved: %d, Expected: %d\n", estateCost, 2);
	else 
		printf("FAIL: Estate Cost - Recieved: %d, Expected: %d\n", estateCost, 2);
	if (duchyCost == 5)
		printf("PASS: Duchy Cost - Recieved: %d, Expected: %d\n", duchyCost, 5);
	else 
		printf("FAIL: Duchy Cost - Recieved: %d, Expected: %d\n", duchyCost, 5);
	if (provinceCost == 8)
		printf("PASS: Province Cost - Recieved: %d, Expected: %d\n", provinceCost, 8);
	else 
		printf("FAIL: Province Cost - Recieved: %d, Expected: %d\n", provinceCost, 8);
	if (copperCost == 0)
		printf("PASS: Copper Cost - Recieved: %d, Expected: %d\n", copperCost, 0);
	else 
		printf("FAIL: Copper Cost - Recieved: %d, Expected: %d\n", copperCost, 0);
	if (silverCost == 3)
		printf("PASS: Silver Cost - Recieved: %d, Expected: %d\n", silverCost, 3);
	else 
		printf("FAIL: Silver Cost - Recieved: %d, Expected: %d\n", silverCost, 3);
	if (goldCost == 6)
		printf("PASS: Gold Cost - Recieved: %d, Expected: %d\n", goldCost, 6);
	else 
		printf("FAIL: Gold Cost - Recieved: %d, Expected: %d\n", goldCost, 6);
	if (adventurerCost == 6)
		printf("PASS: Adventurer Cost - Recieved: %d, Expected: %d\n", adventurerCost, 6);
	else 
		printf("FAIL: Adventurer Cost - Recieved: %d, Expected: %d\n", adventurerCost, 6);
	if (councilRoomCost == 5)
		printf("PASS: Council Room Cost - Recieved: %d, Expected: %d\n", councilRoomCost, 5);
	else 
		printf("FAIL: Council Room Cost - Recieved: %d, Expected: %d\n", councilRoomCost, 5);
	if (feastCost == 4)
		printf("PASS: Feast Cost - Recieved: %d, Expected: %d\n", feastCost, 4);
	else 
		printf("FAIL: Feast Cost - Recieved: %d, Expected: %d\n", feastCost, 4);
	if (gardensCost == 4)
		printf("PASS: Gardens Cost - Recieved: %d, Expected: %d\n", gardensCost, 4);
	else 
		printf("FAIL: Gardens Cost - Recieved: %d, Expected: %d\n", gardensCost, 4);
	if (mineCost == 5)
		printf("PASS: Mine Cost - Recieved: %d, Expected: %d\n", mineCost, 5);
	else 
		printf("FAIL: Mine Cost - Recieved: %d, Expected: %d\n", mineCost, 5);
	if (remodelCost == 4)
		printf("PASS: Remodel Cost - Recieved: %d, Expected: %d\n", remodelCost, 4);
	else 
		printf("FAIL: Remodel Cost - Recieved: %d, Expected: %d\n", remodelCost, 4);
	if (smithyCost == 4)
		printf("PASS: Smithy Cost - Recieved: %d, Expected: %d\n", smithyCost, 4);
	else 
		printf("FAIL: Smithy Cost - Recieved: %d, Expected: %d\n", smithyCost, 4);
	if (villageCost == 3)
		printf("PASS: Village Cost - Recieved: %d, Expected: %d\n", villageCost, 3);
	else 
		printf("FAIL: Village Cost - Recieved: %d, Expected: %d\n", villageCost, 3);
	if (baronCost == 4)
		printf("PASS: Baron Cost - Recieved: %d, Expected: %d\n", baronCost, 4);
	else 
		printf("FAIL: Baron Cost - Recieved: %d, Expected: %d\n", baronCost, 4);
	if (greatHallCost == 3)
		printf("PASS: Great Hall Cost - Recieved: %d, Expected: %d\n", greatHallCost, 3);
	else 
		printf("FAIL: Great Hall Cost - Recieved: %d, Expected: %d\n", greatHallCost, 3);
	if (minionCost == 5)
		printf("PASS: Minion Cost - Recieved: %d, Expected: %d\n", minionCost, 5);
	else 
		printf("FAIL: Minion Cost - Recieved: %d, Expected: %d\n", minionCost, 5);
	if (stewardCost == 3)
		printf("PASS: Steward Cost - Recieved: %d, Expected: %d\n", stewardCost, 3);
	else 
		printf("FAIL: Steward Cost - Recieved: %d, Expected: %d\n", stewardCost, 3);
	if (tributeCost == 5)
		printf("PASS: Tribute Cost - Recieved: %d, Expected: %d\n", tributeCost, 5);
	else 
		printf("FAIL: Tribute Cost - Recieved: %d, Expected: %d\n", tributeCost, 5);
	if (ambassadorCost == 3)
		printf("PASS: Ambassador Cost - Recieved: %d, Expected: %d\n", ambassadorCost , 3);
	else 
		printf("FAIL: Ambassador Cost - Recieved: %d, Expected: %d\n", ambassadorCost , 3);
	if (cutpurseCost == 4)
		printf("PASS: Cutpurse Cost - Recieved: %d, Expected: %d\n", cutpurseCost, 4);
	else 
		printf("FAIL: Cutpurse Cost - Recieved: %d, Expected: %d\n", cutpurseCost, 4);
	if (embargoCost == 2)
		printf("PASS: Embargo Cost - Recieved: %d, Expected: %d\n", embargoCost, 2);
	else 
		printf("FAIL: Embargo Cost - Recieved: %d, Expected: %d\n", embargoCost, 2);
	if (outpostCost == 5)
		printf("PASS: Outpost Cost - Recieved: %d, Expected: %d\n", outpostCost, 5);
	else 
		printf("FAIL: Outpost Cost - Recieved: %d, Expected: %d\n", outpostCost, 5);
	if (salvagerCost == 4)
		printf("PASS: Salvager Cost - Recieved: %d, Expected: %d\n", salvagerCost, 4);
	else 
		printf("FAIL: Salvager Cost - Recieved: %d, Expected: %d\n", salvagerCost, 4);
	if (seaHagCost == 4)
		printf("PASS: Sea Hag Cost - Recieved: %d, Expected: %d\n", seaHagCost, 4);
	else 
		printf("FAIL: Sea Hag Cost - Recieved: %d, Expected: %d\n", seaHagCost, 4);
	if (treasureMapCost == 4)
		printf("PASS: Treasure Map Cost - Recieved: %d, Expected: %d\n", treasureMapCost, 4);
	else 
		printf("FAIL: Treasure Map Cost - Recieved: %d, Expected: %d\n", treasureMapCost, 4);
}

int main() {
	testGetCost();
	return 0;
}