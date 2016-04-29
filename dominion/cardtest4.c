//Test outpost
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

    int choice = 0;
    G.numBuys = 0;
    G.handCount[0] = 5;
    G.hand[0][0] = outpost;
    G.hand[0][1] = silver;
    G.hand[0][1] = copper;
    G.hand[0][2] = copper;
    G.hand[0][3] = gold;

    status = cardEffect(outpost, choice, choice, choice, &G, 0, NULL);
    printf("Testing outpost...\n");
    assert(status == 0);
    assert(G.outpostPlayed == 1);
    printf("CARDTEST 4 PASSED!\n");
    return 0;
}
