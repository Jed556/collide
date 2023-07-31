#include "engine/engine.h"

// Window configurations
const int windowWidth = 1000;
const int windowHeight = 900;
const int targetFPS = 0;  // 0 = auto detect
const char* savePath = "../save/save.dat";
const char* windowTitle = "RPG (Test)";
const char* iconPath = "../res/images/logo.png";

// Game configurations
Vector2 mapSize = {1920, 1080};
float tileSize = 40;
Vector2 playerSize = {40, 40};

// Auto generated configuration
Vector2 windowDimension = {windowWidth, windowHeight};
Debug debug({windowDimension.x, windowDimension.y}, GetFontDefault());
Map map({0, 0}, mapSize, tileSize, "def");
int control = 1;
// Game objects
CollisionList objectList;
Entity player("Player1", objectList, playerSize, {playerSize.x / 2, playerSize.y / 2}, {playerSize.x / 2, playerSize.y / 2}, GREEN, 500.0f);
Entity player2("Player2", objectList, playerSize, {mapSize.x / 2, mapSize.y / 2}, {playerSize.x / 2, playerSize.y / 2}, YELLOW, 500.0f);
Entity player3("Player3", objectList, playerSize, {mapSize.x - playerSize.x / 2, mapSize.y - playerSize.y / 2}, {playerSize.x / 2, playerSize.y / 2}, ORANGE, 500.0f);
GameCamera camera(player.position, {windowDimension.x / 2 - player.position.x, windowDimension.y / 2 - player.position.y}, 0.0f, 1.0f, 20.0f);

GameDataRef gameDataRef = {player, player2, player3, control};

// MAIN CODE
int main() {
    display::init(windowDimension, windowTitle, iconPath);
    display::setFPS(targetFPS);

    data::load(savePath, gameDataRef);
    player.updateCollider(objectList);
    player2.updateCollider(objectList);
    player3.updateCollider(objectList);

    MapTile tile1("def", {-1, -1}, {1, 1}, false, false, false, LIGHTGRAY);
    MapTile tile2("boi", {2, 2}, {2, 2}, false, false, false, BLACK);
    map.addTile(tile1);
    map.addTile(tile2);

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
                player.collidesWithList(objectList);
                player.outOfBounds(player.getHalfSize(), mapSize);
                camera.update(player.position, EaseType::EaseInOutQuad);
                player.updateCollider(objectList);
                break;
            case 2:
                player2.move();
                player2.collidesWithList(objectList);
                player2.outOfBounds(player2.getHalfSize(), mapSize);
                camera.update(player2.position, EaseType::EaseInOutQuad);
                player2.updateCollider(objectList);
                break;
            case 3:
                player3.move();
                player3.collidesWithList(objectList);
                player3.outOfBounds(player3.getHalfSize(), mapSize);
                camera.update(player3.position, EaseType::EaseInOutQuad);
                player3.updateCollider(objectList);
                break;
        }

        // Begin camera mode
        camera.begin();

        // Draw the map
        map.draw();

        // Draw the player
        player.draw();
        player2.draw();
        player3.draw();

        // Draw debug grid
        debug.showGrid(map.getRect(), map.tileSize);
        if (debug.isActive()) objectList.draw(RED, false, 2);

        // End camera mode
        camera.end();

        display::showCustomCursor();

        // Show debug info
        debug.showOverlays(true, false);
        debug.showPosition(camera.prop.target, {0}, false, "Camera");
        debug.showPosition(player.position, player.size, false, "Player1");
        debug.showPosition(player2.position, player2.size, false, "Player2");
        debug.showPosition(player3.position, player3.size, false, "Player3");
        debug.showValue(control, "Control");

        // End drawing / swap buffers
        EndDrawing();
    }

    // Save game data
    GameData gameData = {player, player2, player3, control};
    data::save(savePath, gameData);

    // Bye!
    display::close();
    return 0;
}