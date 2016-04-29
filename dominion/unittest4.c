//Test getCost
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
        sea_hag, tribute, smithy};
    printf ("Starting game.\n");
    int r = initializeGame(2, k, 2, &G);
    assert (r == 0);

    //Test all possible card costs
    assert(getCost(curse) == 0);
    printf(" Curse PASSED!\n");

    assert(getCost(estate) == 2);
    printf(" Estate PASSED!\n");

    assert(getCost(duchy) == 5);
    printf(" Duchy PASSED!\n");

    assert(getCost(province) == 8);
    printf(" Province PASSED!\n");

    assert(getCost(copper) == 0);
    printf(" Copper PASSED!\n");

    assert(getCost(silver) == 3);
    printf(" Silver PASSED!\n");

    assert(getCost(gold) == 6);
    printf(" Gold PASSED!\n");

    assert(getCost(adventurer) == 6);
    printf(" Adventure PASSED\n");

    assert(getCost(council_room) == 5);
    printf(" Council_room PASSD!\n");

    assert(getCost(feast) == 4);
    printf(" Feast PASSED!\n");

    assert(getCost(gardens) == 4);
    printf(" Gardens PASSED\n");

    assert(getCost(mine) == 5);
    printf(" Mine PASSED!\n");

    assert(getCost(remodel) == 4);
    printf(" Remodel PASSED!\n");

    assert(getCost(smithy) == 4);
    printf(" Smithy PASSED!\n");

    assert(getCost(village) == 3);
    printf(" Village PASSED!\n");

    assert(getCost(baron) == 4);
    printf(" Baron PASSED!\n");

    assert(getCost(great_hall) == 3);
    printf(" Great_hall PASSED!\n");

    assert(getCost(minion) == 5);
    printf(" Minion PASSED!\n");

    assert(getCost(steward) == 3);
    printf(" Steward PASSED!\n");

    assert(getCost(tribute) == 5);
    printf(" Tribute PASSED!\n");

    assert(getCost(ambassador) == 3);
    printf(" Ambassador PASSED!\n");

    assert(getCost(cutpurse) == 4);
    printf(" Cutpurse PASSED!\n");

    assert(getCost(embargo) == 2);
    printf(" Embargo PASSED!\n");

    assert(getCost(outpost) == 5);
    printf(" Outpost PASSED!\n");

    assert(getCost(salvager) == 4);
    printf(" Salvager PASSED!\n");

    assert(getCost(sea_hag) == 4);
    printf(" Sea_hag PASSED!\n");

    assert(getCost(treasure_map) == 4);
    printf(" Treasure_map PASSED!\n");
        
    printf("UNITTEST 4 PASSED!!\n");
    return 0;
}
