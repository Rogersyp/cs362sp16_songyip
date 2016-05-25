#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define NUM_TEST_ITERS 10000

int test_dominion();

int main(int argc, char** argv) {
  int i;
  for (i = 0; i < NUM_TEST_ITERS; i++) {
    test_dominion();
  }
  
  return 0;
}

int test_dominion () {
  struct gameState G;
  struct gameState *p = &G;

  int minCard, maxCard;
  minCard = adventurer;
  maxCard = treasure_map;
  int k[3][10] = {
            {adventurer, gardens, embargo, village, minion, mine, cutpurse,
         sea_hag, tribute, smithy},
            {village, council_room, feast, salvager, ambassador, mine, steward, 
               outpost, great_hall, baron},
            {sea_hag, steward, salvager, smithy, adventurer, ambassador, baron, 
               tribute, treasure_map, remodel}
      };

  printf ("Starting game.\n");
  
  int money = 0;
  int smithyPos = -1;
  int adventurerPos = -1;
  int villagePos = -1;
  int cutpursePos = -1;
  int i=0;
  int init;
  
  int players = rand() % (MAX_PLAYERS - 1) + 2;

  printf("num players: %d\n", players);
  i = rand() % 2;
  init = initializeGame(players, k[i], k[i][players], p); 
  if (init != 0) {
      printf("init failed: returned %d\n", init);
      exit(-1);
  }
  
  int numSmithies = 0;
  int numAdventurers = 0;
  int numVillage = 0;
  int numCutpurse = 0;

  while (!isGameOver(p)) {
    money = 0;
    smithyPos = -1;
    adventurerPos = -1;
    villagePos = -1;
    cutpursePos = -1;
    
    for (i = 0; i < numHandCards(p); i++) {
      if (handCard(i, p) == copper)
    money++;
      else if (handCard(i, p) == silver)
    money += 2;
      else if (handCard(i, p) == gold)
    money += 3;
      else if (handCard(i, p) == smithy)
    smithyPos = i;
      else if (handCard(i, p) == adventurer)
    adventurerPos = i;
      else if (handCard(i, p) == village)
    villagePos = i;
      else if (handCard(i, p) == cutpurse)
    cutpursePos = i;
    }

    if (whoseTurn(p) == 0) {
      if (smithyPos != -1) {
        printf("0: smithy played from position %d\n", smithyPos); 
        playCard(smithyPos, -1, -1, -1, p);
        printf("smithy played.\n");
        money = 0;
        i=0;
        while(i<numHandCards(p)){
          if (handCard(i, p) == copper){
            playCard(i, -1, -1, -1, p);
            money++;
          }
          else if (handCard(i, p) == silver){
            playCard(i, -1, -1, -1, p);
            money += 2;
          }
          else if (handCard(i, p) == gold){
            playCard(i, -1, -1, -1, p);
            money += 3;
          }
          i++;
        }
      }

      if (money >= 8) {
        printf("0: bought province\n"); 
        buyCard(province, p);
      }
      else if (money >= 6) {
        printf("0: bought gold\n"); 
        buyCard(gold, p);
      }
      else if ((money >= 4) && (numSmithies < 2)) {
        printf("0: bought smithy\n"); 
        buyCard(smithy, p);
        numSmithies++;
      }
      else if (money >= 3) {
        printf("0: bought silver\n"); 
        buyCard(silver, p);
      }

      printf("0: end turn\n");
      endTurn(p);
    }
    else if (whoseTurn(p) == 1) {
      if (adventurerPos != -1) {
        printf("1: adventurer played from position %d\n", adventurerPos);
        playCard(adventurerPos, -1, -1, -1, p);
        money = 0;
        i=0;
        while(i<numHandCards(p)){
          if (handCard(i, p) == copper){
            playCard(i, -1, -1, -1, p);
            money++;
          }
          else if (handCard(i, p) == silver){
            playCard(i, -1, -1, -1, p);
            money += 2;
          }
          else if (handCard(i, p) == gold){
            playCard(i, -1, -1, -1, p);
            money += 3;
          }
          i++;
        }
      }

      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
      else if ((money >= 6) && (numAdventurers < 2)) {
        printf("1: bought adventurer\n");
        buyCard(adventurer, p);
        numAdventurers++;
      }else if (money >= 6){
        printf("1: bought gold\n");
        buyCard(gold, p);
      }
      else if (money >= 3){
        printf("1: bought silver\n");
        buyCard(silver, p);
      }
      printf("1: endTurn\n");
      
      endTurn(p);      
    }
    else if (whoseTurn(p) == 2) {
      if (adventurerPos != -1) {
        printf("2: village played from position %d\n", villagePos);
        playCard(villagePos, -1, -1, -1, p);
        money = 0;
        i=0;
        while(i<numHandCards(p)){
          if (handCard(i, p) == copper){
            playCard(i, -1, -1, -1, p);
            money++;
          }
          else if (handCard(i, p) == silver){
            playCard(i, -1, -1, -1, p);
            money += 2;
          }
          else if (handCard(i, p) == gold){
            playCard(i, -1, -1, -1, p);
            money += 3;
          }
          i++;
        }
      }
      
      if (money >= 8) {
        printf("2: bought province\n");
        buyCard(province, p);
      }
      else if ((money >= 6) && (numVillage < 2)) {
        printf("2: bought village\n");
        buyCard(adventurer, p);
        numVillage++;
      }else if (money >= 6){
        printf("2: bought gold\n");
        buyCard(gold, p);
      }
      else if (money >= 3){
        printf("2: bought silver\n");
        buyCard(silver, p);
      }
      printf("2: endTurn\n");
      
      endTurn(p);
    }
    
    else {
      if (adventurerPos != -1) {
        printf("3: curpurse played from position %d\n", cutpursePos);
        playCard(cutpursePos, -1, -1, -1, p);
        money = 0;
        i=0;
        while(i<numHandCards(p)){
          if (handCard(i, p) == copper){
            playCard(i, -1, -1, -1, p);
            money++;
          }
          else if (handCard(i, p) == silver){
            playCard(i, -1, -1, -1, p);
            money += 2;
          }
          else if (handCard(i, p) == gold){
            playCard(i, -1, -1, -1, p);
            money += 3;
          }
          i++;
        }
      }
      
      if (money >= 8) {
        printf("3: bought province\n");
        buyCard(province, p);
      }
      else if ((money >= 4) && (numAdventurers < 2)) {
        printf("3: bought cutpurse\n");
        buyCard(cutpurse, p);
        numCutpurse++;
      }else if (money >= 6){
        printf("3: bought gold\n");
        buyCard(gold, p);
      }
      else if (money >= 3){
        printf("3: bought silver\n");
        buyCard(silver, p);
      }
      printf("3: endTurn\n");
      
      endTurn(p);
    }
    for (i = 0; i < players; i++) {
      printf ("Player %d score: %d\n", i, scoreFor(i, p));
    }
    
      
  } // end of While

  printf ("Finished game.\n");
  for (i = 0; i < players; i++) {
    printf ("Player %d score: %d\n", i, scoreFor(i, p));
  }

  return 0;
}
