#include <iostream>

#include "engine/engine.h"

// Window configurations
const int windowWidth = 1000;
const int windowHeight = 900;
const int targetFPS = 144;
const char* windowTitle = "RPG (Test)";

// Game configurations
Vector2 mapSize = {1920, 1080};
Vector2 tileSize = {40, 40};
Vector2 playerSize = {40, 40};

// Auto generated configuration
Vector2 windowDimension = {windowWidth, windowHeight};
Debug debug({windowDimension.x, windowDimension.y});
// Game objects
Player player(playerSize, {mapSize.x / 2.0f, mapSize.y / 2.0f}, {playerSize.x / 2, playerSize.y / 2}, GREEN, 50.0f);
GameCamera camera(player.position,{windowDimension.x / 2 - player.position.x, windowDimension.y / 2 - player.position.y}, 0.0f, 1.0f, 1.0f);

void Initialize() {
    debug.toggle();
    InitWindow((int)windowDimension.x, (int)windowDimension.y, windowTitle);
    SetTargetFPS(targetFPS);
}

int main() {
    Initialize();

    // int precision = 0;
    // int mapDimension = std::max(mapSize.x, mapSize.y);
    // while (mapDimension % 10 != 0 && precision < INT_MAX) {
    //     mapDimension *= 10;
    //     precision++;
    // }

    while (!WindowShouldClose()) {
        // Begin debug mode
        debug.begin();

        // Refresh screen
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Update camera and player
        player.move();
        player.collide(player.getHalfSize(), mapSize);
        camera.update(player.position, EaseType::EaseInOutQuad);

        // Begin camera mode
        camera.begin();

        // Draw the player
        player.draw();

        // Draw debug grid
        debug.showGrid(mapSize, tileSize);

        // End camera mode
        camera.end();

        // Show debug info
        if (debug.isActive()) {
            debug.showOverlays(true, false);
            debug.showPosition(player.position, player.size, false, "Player");
            debug.showPosition(camera.prop.target, {0}, false, "Camera");
        }

        // End drawing / swap buffers
        EndDrawing();
    }

    // Bye!
    CloseWindow();
    return 0;
}