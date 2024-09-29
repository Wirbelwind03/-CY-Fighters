#ifndef BATTLE_H
#define BATTLE_H

#include <stdbool.h>

#include "player.h"

enum BATTLE_DIFFICULTY { BATTLE_DIFFICULTY_NOOB, BATTLE_DIFFICULTY_EASY, BATTLE_DIFFICULTY_NORMAL, BATTLE_DIFFICULTY_SIZE };

enum BATTLE_AGAINST_OPTION { BATTLE_AGAINST_OPTION_PLAYER, BATTLE_AGAINST_OPTION_COMPUTER, BATTLE_AGAINST_OPTION_SIZE};

typedef struct 
{
    // If the battle is finished
    bool is_over;

    // If it's a normal or quick battle
    bool is_quickBattle;

    // The difficulty of the battle
    enum BATTLE_DIFFICULTY difficulty;

} Battle;

// Constructor //

// Allocate memory for Battle*
Battle* Battle_Init();

// Gameplay Functions //

// Player choose against another Player or Computer
enum BATTLE_AGAINST_OPTION Battle_ChooseAgainst();

// Player choose which diffilcuty the computer is (If they choose to be against a Computer)
enum BATTLE_DIFFICULTY Battle_ChooseComputerDifficutly();

// Decide which player get to play it's turn 
void Battle_TakeTurn(Battle* battle, Player* player1, Player* player2);

// Update state of battle
void Battle_Update(Battle* battle, Player* player1, Player* player2);

// Announce at the end battle which player won
void Battle_AnnounceVictory(Player* player1, Player* player2);

// Destructor //

// Free Memory
void Battle_Free(Battle* battle);

#endif