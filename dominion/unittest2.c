//Test updateCoins
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
   
    G.hand[0][0] = copper; // 1
    G.hand[0][1] = silver; // 2
    G.hand[0][2] = gold;   // 3
    G.hand[0][3] = copper; // 1
    G.hand[0][4] = silver; // 2
    //Total coins should be 9

    updateCoins(0, &G, 5);
    //+5 bonus, 14 coins!
    printf("Total coins should be 14\n");
    assert(G.coins == 14);
    printf("UNITTEST 2 PASSED!\n");
    return 0;
}
