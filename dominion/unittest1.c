//test buy card
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

    //Test buyCard function
    //Can buy, return value should be 0
    G.numBuys = 1;
    G.coins = 1;
    status = buyCard(copper, &G);
    assert(status == 0);

    //Cannot buy, return value should be 1
    G.numBuys = 0;
    G.coins = 1;    
    status = buyCard(copper, &G);
    assert(status == -1);
    printf("UNITTEST 1 PASSED!\n");

    return 0;
}
