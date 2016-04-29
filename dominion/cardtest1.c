//Test treasure_map
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


int main(){
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
        sea_hag, tribute, smithy};
    printf ("Starting game.\n");

    int status = initializeGame(2, k, 2, &G);
    assert (status == 0);

    printf("Testing treasure_map...\n");
    int choice = 0;
    G.numBuys = 0;
    G.handCount[0] = 5;
    G.hand[0][0] = treasure_map;
    G.hand[0][1] = silver;
    G.hand[0][1] = treasure_map;
    G.hand[0][2] = copper;
    G.hand[0][3] = gold;
    status = cardEffect(treasure_map, choice, choice, choice, &G, 0, NULL);
    printf("2 treasure_maps. Status must be 1, count must be 3\n");
    printf("%d\n", G.handCount[0]);
    assert(status == 1);
    assert(G.handCount[0] == 3);

    G.handCount[0] = 5;
    G.hand[0][0] = treasure_map;
    G.hand[0][1] = silver;
    G.hand[0][1] = copper;
    G.hand[0][2] = copper;
    G.hand[0][3] = gold;
    status = cardEffect(treasure_map, choice, choice, choice, &G, 0, NULL);
    printf("1 treasure_map. Status must be -1, count must be 5\n");
    printf("%d\n", G.handCount[0]);
    assert(status == -1);
    assert(G.handCount[0] == 5);

    printf("CARDTEST 1 PASSED!\n");
    return 0;
}
