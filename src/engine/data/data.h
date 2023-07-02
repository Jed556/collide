#ifndef DATA_H
#define DATA_H

#include <raylib.h>
#include <raymath.h>

#include <filesystem>
#include <iostream>

#include "../../game/gameData.h"

namespace data {
/**
 * @brief Save game data to a file
 *
 * @param fileName File name / path
 * @param data Game data to be saved
 * @return true
 * @return false
 */
bool save(const char* fileName, GameData gameData);

/**
 * @brief Load game data from a file
 *
 * @param fileName File name / path
 * @return GameData
 */
void load(const char* fileName, GameDataRef& gameDataRef);

/**
 * @brief Parse game data loaded
 * 
 * @param loadedData Loaded game data
 * @param gameDataRef References to game data
 */
void parse(GameData* loadedData, GameDataRef& gameDataRef);
}  // namespace data

#endif  // DATA_H