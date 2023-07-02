#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <raylib.h>

#include "../engine/engine.h"

// Change the GameData and GameDataRef structs according to your game data

/**
 * @brief Game data to be saved
 *
 */
struct GameData {
    Entity player;
    Entity player2;
    Entity player3;
    int control;
};

/**
 * @brief References to game data from your game
 * @brief where the data will be loaded
 *
 */
struct GameDataRef {
    Entity& player;
    Entity& player2;
    Entity& player3;
    int& control;
};

#endif  // GAMEDATA_H