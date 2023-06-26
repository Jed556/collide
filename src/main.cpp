#include "engine/engine.h"

const int screenWidth = 1000;
const int screenHeight = 800;
const int mapWidth = 800;
const int mapHeight = 450;

int main() {
    Player player;
    player.size = {50, 50};
    player.position = {screenWidth / 2.0f - player.size.x / 2.0f, screenHeight / 2.0f - player.size.y / 2.0f};
    player.prevPosition = player.position;
    player.color = GREEN;
    player.speed = 5.0f;

    InitWindow(screenWidth, screenHeight, "RPG (Test)");

    GameCamera camera;
    camera.prop.target = {player.position.x + player.size.x / 2.0f, player.position.y + player.size.y / 2.0f};
    camera.prop.offset = {screenWidth / 2.0f, screenHeight / 2.0f};
    camera.prop.rotation = 0.0f;
    camera.prop.zoom = 1.0f;
    camera.speed = 0.1f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Update camera and player
        player.update();
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
        DrawRectangleV({player.position.x, player.position.y}, player.size, player.color);

        // End camera mode
        camera.end();

        // Draw point at the center of the screen
        DrawCircle(screenWidth / 2.0f, screenHeight / 2.0f, 5, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}