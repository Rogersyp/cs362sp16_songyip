#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_TESTS 100000

//This randomly tests Adventurer

int main() {

    srand(time(NULL));

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
        sea_hag, tribute, smithy};

    int i, j, playerCount, currentPlayer, seed, handSlot;
    int status, preCoinCount, postCoinCount, postHandSize, preHandSize;
    struct gameState state;

    printf("Running Random Adventurer Test...\n");

    for (i = 0; i < NUM_TESTS; i++) {

        //Setup Game 
        playerCount = rand() % 3 + 1;
        currentPlayer = rand() % playerCount;
        seed = rand();		//pick random seed
        
        initializeGame(playerCount, k, seed, &state);
        state.whoseTurn = currentPlayer;

        
        state.deckCount[currentPlayer] = rand() % MAX_DECK;
        state.discardCount[currentPlayer] = MAX_DECK - state.deckCount[currentPlayer];
        state.handCount[currentPlayer] = rand() % MAX_HAND + 1;
        if(rand() % 3 == 1) // 1 in 3 chance of using empty deck
            state.deckCount[currentPlayer] = 0;

        //Randomize card piles
        for (j = 0; j < state.handCount[currentPlayer]; j++)
            state.hand[currentPlayer][j] = rand() % treasure_map;
        for (j = 0; j < state.deckCount[currentPlayer]; j++)
            state.deck[currentPlayer][j] = rand() % treasure_map;
        for (j = 0; j < state.discardCount[currentPlayer]; j++)
            state.discard[currentPlayer][j] = rand() % treasure_map;

        //Enforce spot to be the target card
        handSlot = rand()% state.handCount[currentPlayer];
        state.hand[currentPlayer][handSlot] = adventurer;

        
        preHandSize = state.handCount[currentPlayer];
        updateCoins(state.whoseTurn, &state, 0);
        preCoinCount = state.coins;

        //Run cardEffect
        status = cardEffect(adventurer, 0, 0, 0, &state, handSlot, 0); 
        
        postHandSize = state.handCount[currentPlayer];
        updateCoins(state.whoseTurn, &state, 0);
        postCoinCount = state.coins;

        //proper coin check
        assert(status == 0);
//        if(preHandSize + 1 != postHandSize)
//            printf("Error, handsize update failure\n");
    }
    printf("Tests Complete\n");

    return 0;
}
