#include "engine/engine.h"

const int screenWidth = 1000;
const int screenHeight = 800;
Vector2 mapSize = {1000, 800};

int main() {
    Player player;
    player.size = {40, 40};
    player.position = {screenWidth / 2.0f, screenHeight / 2.0f};
    player.prevPosition = player.position;
    player.origin = player.getHalfSize();
    player.color = GREEN;
    player.speed = 5.0f;

    GameCamera camera;
    camera.prop.target = {player.position.x, player.position.y};
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
        player.collide(player.getHalfSize(), mapSize);
        camera.update(player.position, player.size, true);

        // Begin camera mode
        camera.begin();

        // Draw the game map (assuming it's a static background)
        for (int y = 0; y < mapSize.y; y += screenHeight) {
            for (int x = 0; x < mapSize.x; x += screenWidth) {
                DrawRectangle(x, y, screenWidth, screenHeight, LIGHTGRAY);
            }
        }

        // Draw the player
        player.draw();

        // End camera mode
        camera.end();

        // Show debug info
        debug.showAll(true, false);
        debug.showPosition(player.position, player.size, false, 3, "Player");
        debug.showPosition(camera.prop.target, {0}, false, 3, "Camera");

        // End drawing / swap buffers
        EndDrawing();
    }

    // Bye!
    CloseWindow();
    return 0;
}