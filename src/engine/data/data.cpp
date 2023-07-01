#include "data.h"

namespace data {
bool save(const char* fileName, GameData data) {
    unsigned int dataSize = sizeof(GameData);
    return SaveFileData(fileName, &data, dataSize);
}

void load(const char* fileName) {
    unsigned int dataSize;
    unsigned char* loadedGameData = LoadFileData(fileName, &dataSize);
    std::cout << "INFO: Loaded data size: " << dataSize << std::endl;
    std::cout << "INFO: Expected data size: " << sizeof(GameData) << std::endl;

    // Use the loaded game data
    if (loadedGameData != NULL) {
        if (dataSize == sizeof(GameData)) {
            GameData* dataPtr = (GameData*)loadedGameData;
            // return *dataPtr;
        } else {
            std::cout << "ERROR: Invalid game data size." << std::endl;
        }

        UnloadFileData(loadedGameData);
    } else {
        std::cout << "ERROR: Failed to load game data from file." << std::endl;
    }
}
}  // namespace data