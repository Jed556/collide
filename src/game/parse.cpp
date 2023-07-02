#include "../engine/data/data.h"

void data::parse(GameData* loadedData, GameDataRef& gameData) {

    // Change according to your game data
    gameData.control = loadedData->control;
    gameData.player = loadedData->player;
    gameData.player2 = loadedData->player2;
    gameData.player3 = loadedData->player3;
}