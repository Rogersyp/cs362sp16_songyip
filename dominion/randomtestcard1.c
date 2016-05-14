#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 2000

int main() {

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
    int preHandCount, postHandCount, preDeckCount, postDeckCount, handDiff, deckDiff; 
    int wrongCount = 0;
    int correctCount = 0;
    int i, players, player, seed, handPos;
    struct gameState state;

    printf("Running Random Smithy Test...\n");

    for (i = 0; i < MAX_TESTS; i++) {

        players = rand() % 4;
        seed = rand();
        handPos = rand() % 4;
        player = rand() % (players + 1);
        
        initializeGame(players, k, seed, &state);

        //Initiate valid state variables
        state.deckCount[player] = rand() % MAX_DECK;
        state.discardCount[player] = rand() % MAX_DECK;
        state.handCount[player] = rand() % MAX_HAND;

        // set up all the pre-call variables
        preHandCount = state.handCount[player];
        preDeckCount = state.deckCount[player];

        cardEffect(smithy, 1, 1, 1, &state, handPos, 0);

        // record post-call variables
        postHandCount = state.handCount[player];
        postDeckCount = state.deckCount[player];

        // calculations to test accuracy of this test
        handDiff = postHandCount - preHandCount;
        deckDiff = preDeckCount - postDeckCount;
 
        if (handDiff != 2 && postDeckCount >= 0) {
            wrongCount = wrongCount+1;
        }
        else if (postDeckCount == 0) {
            if (handDiff == preDeckCount) correctCount = correctCount+1;
            else wrongCount = wrongCount+1;
        }
        else {
            correctCount = correctCount+1;
        }
    }

    printf("%i Tests Complete\n", MAX_TESTS);
    printf("Correct Results: %i\n", correctCount);
    printf("Wrong Results: %i\n", wrongCount);
    
    return 0;
}
