#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;
const int mapWidth = 800;   // Width of the game map
const int mapHeight = 450;  // Height of the game map

struct Player {
    Vector2 position;
    Vector2 prevPosition;
    Vector2 size;
    Color color;
    float speed;
};

void UpdatePlayer(Player& player) {
    player.prevPosition = player.position;

    if (IsKeyDown(KEY_D)) player.position.x += player.speed;
    if (IsKeyDown(KEY_A)) player.position.x -= player.speed;
    if (IsKeyDown(KEY_S)) player.position.y += player.speed;
    if (IsKeyDown(KEY_W)) player.position.y -= player.speed;
}

int main() {
    Player player;
    player.size = {50, 50};
    player.position = {screenWidth / 2.0f - player.size.x / 2.0f, screenHeight / 2.0f - player.size.y / 2.0f};
    player.prevPosition = player.position;
    player.color = GREEN;
    player.speed = 5.0f;

    InitWindow(screenWidth, screenHeight, "RPG (Test)");

    Camera2D camera;
    camera.target = {player.position.x + player.size.x / 2.0f, player.position.y + player.size.y / 2.0f};
    camera.offset = {screenWidth / 2.0f, screenHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    const float cameraSpeed = 0.1f;

    SetTargetFPS(60);

    RenderTexture2D accumulationBuffer = LoadRenderTexture(screenWidth, screenHeight);
    SetTextureFilter(accumulationBuffer.texture, TEXTURE_FILTER_BILINEAR);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Update
        UpdatePlayer(player);

        // Ease camera movement towards player position
        camera.target.x += ((player.position.x + player.size.x / 2.0f) - camera.target.x) * cameraSpeed;
        camera.target.y += ((player.position.y + player.size.y / 2.0f) - camera.target.y) * cameraSpeed;

        // Begin camera mode
        BeginMode2D(camera);

        // Draw the game map (assuming it's a static background)
        for (int y = 0; y < mapHeight; y += screenHeight) {
            for (int x = 0; x < mapWidth; x += screenWidth) {
                DrawRectangle(x, y, screenWidth, screenHeight, LIGHTGRAY);
            }
        }

        // Draw the player
        DrawRectangleV({player.position.x, player.position.y}, player.size, player.color);

        // End camera mode
        EndMode2D();

        // Draw point at the center of the screen
        DrawCircle(screenWidth / 2.0f, screenHeight / 2.0f, 5, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}