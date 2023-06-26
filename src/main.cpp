#include "engine/engine.h"
#include "raymath.h"

const int screenWidth = 1000;
const int screenHeight = 800;
Vector2 mapSize = {1920, 1080};
Vector2 tileSize = {40, 40};

int main() {
    Player player;
    player.size = {40, 40};
    player.position = {mapSize.x / 2.0f, mapSize.y / 2.0f};
    player.prevPosition = player.position;
    player.origin = player.getHalfSize();
    player.color = GREEN;
    player.speed = 5.0f;

    GameCamera camera;
    camera.prop.target = player.position;
    camera.prop.offset = {player.position.x - (mapSize.x / 2.0f - screenWidth / 2.0f), player.position.y - (mapSize.y / 2.0f - screenHeight / 2.0f)};
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
        camera.update(player.position, true);

        // Begin camera mode
        camera.begin();

        // Draw the player
        player.draw();

        // Draw debug grid
        debug.showGrid(mapSize, tileSize);

        // End camera mode
        camera.end();

        // Show debug info
        debug.showOverlays(true, false);
        debug.showPosition(player.position, player.size, false, 3, "Player");
        debug.showPosition(camera.prop.target, {0}, false, 3, "Camera");

        // End drawing / swap buffers
        EndDrawing();
    }

    // Bye!
    CloseWindow();
    return 0;
}