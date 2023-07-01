#ifndef DATA_H
#define DATA_H

#include <raylib.h>
#include <raymath.h>

#include <iostream>
#include <filesystem>

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
bool save(const char* fileName, GameData data);

/**
 * @brief Load game data from a file
 *
 * @param fileName File name / path
 * @return GameData
 */
void load(const char* fileName);
}  // namespace data

#endif  // DATA_H