//Test numHandCards
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

    printf("Checking player 0's hand for number of cards...\n");
    //Should start with 5 cards 
    int numCards = numHandCards(&G);
    assert(numCards == 5);
    printf("UNITTEST 3 PASSED!\n");
    return 0;
}
