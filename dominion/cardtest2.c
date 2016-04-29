//Test salvager
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
    status = cardEffect(salvager, choice, choice, choice, &G, 0, NULL);
    printf("Testing salvager...\n");
    assert(status == 0);
    assert(G.numBuys == 1);

    printf("CARDTEST 2 PASSED!\n");
    return 0;
}
