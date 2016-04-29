//Test great_hall
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
    G.numActions = 1;
    status = cardEffect(great_hall, choice, choice, choice, &G, 0, NULL);
    printf("Testing great hall...\n");
    assert(status == 0);
    assert(G.numActions == 2);
    printf("CARDTEST 3 PASSED!\n");
    return 0;
}
