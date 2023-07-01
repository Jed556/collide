#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <raylib.h>

#include "../engine/engine.h"

struct GameData {
    Entity player;
    Entity player2;
    Entity player3;
    int control;
};

#endif  // GAMEDATA_H