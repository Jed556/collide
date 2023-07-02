#include "data.h"

namespace data {
bool save(const char* fileName, GameData gameData) {
    unsigned int dataSize = sizeof(GameData);

    // Create directory if it doesn't exist
    std::filesystem::path filePath(fileName);
    std::filesystem::create_directories(filePath.parent_path());

    bool saved = SaveFileData(fileName, &gameData, dataSize);
    std::cout << "INFO: Saved data size: " << dataSize << std::endl;
    return saved;
}

void load(const char* fileName, GameDataRef& gameDataRef) {
    unsigned int dataSize;
    unsigned char* loadedGameData = LoadFileData(fileName, &dataSize);
    std::cout << "INFO: Loaded data size: " << dataSize << std::endl;
    std::cout << "INFO: Expected data size: " << sizeof(GameData) << std::endl;

    // Use the loaded game data
    if (loadedGameData != NULL) {
        if (dataSize == sizeof(GameData)) {
            GameData* dataPtr = (GameData*)loadedGameData;
            parse(dataPtr, gameDataRef);
        } else {
            std::cout << "ERROR: Invalid game data size." << std::endl;
        }

        UnloadFileData(loadedGameData);
    } else {
        std::cout << "ERROR: Failed to load game data from file." << std::endl;
    }
}
}  // namespace data