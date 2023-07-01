#include "engine/engine.h"

// Window configurations
const int windowWidth = 1000;
const int windowHeight = 900;
const int targetFPS = 0;  // 0 = auto detect
const char* windowTitle = "RPG (Test)";

// Game configurations
Vector2 mapSize = {1920, 1080};
Vector2 tileSize = {40, 40};
Vector2 playerSize = {40, 40};

// Auto generated configuration
Vector2 windowDimension = {windowWidth, windowHeight};
Debug debug({windowDimension.x, windowDimension.y});
int control = 1;
// Game objects
Entity player(playerSize, {0}, {playerSize.x / 2, playerSize.y / 2}, GREEN, 500.0f);
Entity player2(playerSize, {mapSize.x / 2, mapSize.y / 2}, {playerSize.x / 2, playerSize.y / 2}, YELLOW, 500.0f);
Entity player3(playerSize, {mapSize.x - playerSize.x / 2, mapSize.y - playerSize.y / 2}, {playerSize.x / 2, playerSize.y / 2}, ORANGE, 500.0f);
GameCamera camera(player.position, {windowDimension.x / 2 - player.position.x, windowDimension.y / 2 - player.position.y}, 0.0f, 1.0f, 20.0f);

// MAIN CODE
int main() {
    display::init(windowDimension, windowTitle);
    display::setFPS(targetFPS);

    unsigned int dataSize;
    unsigned char* loadedGameData = LoadFileData("../save/save.dat", &dataSize);
    std::cout << "Loaded game data size: " << dataSize << std::endl;
    std::cout << "Game data size: " << sizeof(GameData) << std::endl;

    // Use the loaded game data
    if (loadedGameData != NULL && dataSize == sizeof(GameData)) {
        GameData* dataPtr = (GameData*)loadedGameData;
        control = dataPtr->control;
        player = dataPtr->player;
        player2 = dataPtr->player2;
        player3 = dataPtr->player3;

        UnloadFileData(loadedGameData);
    } else {
        if (loadedGameData == NULL) {
            std::cout << "Error: Failed to load game data from file." << std::endl;
        } else {
            std::cout << "Error: Invalid game data size." << std::endl;
        }
        // Use default game data
    }

    while (!WindowShouldClose()) {
        // Begin debug mode
        debug.begin();
        if (key::debug()) {
            debug.toggle();
        }

        // Switch between players
        if (key::pressed(KEY_Q)) {
            ++control;
            if (control > 3) control = 1;
        }
        if (key::pressed(KEY_E)) {
            --control;
            if (control < 1) control = 3;
        }

        // Refresh screen
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Update camera and player
        switch (control) {
            case 1:
                player.move();
                player.collidesWith(player2.getRect());
                player.collidesWith(player3.getRect());
                player.outOfBounds(player.getHalfSize(), mapSize);
                camera.update(player.position, EaseType::EaseInOutQuad);
                break;
            case 2:
                player2.move();
                player2.collidesWith(player.getRect());
                player2.collidesWith(player3.getRect());
                player2.outOfBounds(player2.getHalfSize(), mapSize);
                camera.update(player2.position, EaseType::EaseInOutQuad);
                break;
            case 3:
                player3.move();
                player3.collidesWith(player.getRect());
                player3.collidesWith(player2.getRect());
                player3.outOfBounds(player3.getHalfSize(), mapSize);
                camera.update(player3.position, EaseType::EaseInOutQuad);
                break;
        }

        // Begin camera mode
        camera.begin();

        // Draw the map
        for (int x = 0; x < mapSize.x; x += tileSize.x) {
            for (int y = 0; y < mapSize.y; y += tileSize.y) {
                DrawRectangle(x, y, tileSize.x, tileSize.y, LIGHTGRAY);
            }
        }

        // Draw the player
        player.draw();
        player2.draw();
        player3.draw();

        // Draw debug grid
        debug.showGrid(mapSize, tileSize);

        // End camera mode
        camera.end();

        // Show debug info
        debug.showOverlays(true, false);
        debug.showPosition(player.position, player.size, false, "Player1");
        debug.showPosition(player2.position, player2.size, false, "Player2");
        debug.showPosition(player3.position, player3.size, false, "Player3");
        debug.showPosition(camera.prop.target, {0}, false, "Camera");

        // End drawing / swap buffers
        EndDrawing();
    }

    // Save game data
    GameData gameData = {player, player2, player3, control};
    data::save("../save/save.dat", gameData);

    // Bye!
    display::close();
    return 0;
}