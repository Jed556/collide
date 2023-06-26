#include "engine/engine.h"

const int screenWidth = 1000;
const int screenHeight = 800;
const int mapWidth = 1000;
const int mapHeight = 800;

int main() {
    Player player;
    player.size = {40, 40};
    player.position = {screenWidth / 2.0f - player.size.x / 2.0f, screenHeight / 2.0f - player.size.y / 2.0f};
    player.prevPosition = player.position;
    player.color = GREEN;
    player.speed = 5.0f;

    GameCamera camera;
    camera.prop.target = {player.position.x + player.size.x / 2.0f, player.position.y + player.size.y / 2.0f};
    camera.prop.offset = {screenWidth / 2.0f, screenHeight / 2.0f};
    camera.prop.rotation = 0.0f;
    camera.prop.zoom = 1.0f;
    camera.speed = 0.1f;

    Debug debug({(float)screenWidth, (float)screenHeight});

    InitWindow(screenWidth, screenHeight, "RPG (Test)");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Begin debug mode
        debug.begin();

        // Refresh screen
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Update camera and player
        player.update();
        player.collide({0, 0}, {mapWidth, mapHeight});
        camera.update(player.position, player.size, true, 5);

        // Begin camera mode
        camera.begin();

        // Draw the game map (assuming it's a static background)
        for (int y = 0; y < mapHeight; y += screenHeight) {
            for (int x = 0; x < mapWidth; x += screenWidth) {
                DrawRectangle(x, y, screenWidth, screenHeight, LIGHTGRAY);
            }
        }

        // Draw the player
        player.draw();

        // End camera mode
        camera.end();

        // Show debug info
        debug.showAll(true, false);
        debug.showPosition(player.position, player.size, true, 3, "Player");
        debug.showPosition(player.position, player.size, false, 3, "Player");
        debug.showPosition(camera.prop.target, {0}, false, 3, "Camera");

        // End drawing / swap buffers
        EndDrawing();
    }

    // Bye!
    CloseWindow();
    return 0;
}