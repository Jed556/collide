#include "debug.h"

void Debug::showGrid(Vector2 mapSize, Vector2 tileSize) {
    if (!isActive()) return;

    // Old method
    // for (float y = 0; y < mapSize.y; y += tileSize.y)
    //     for (float x = 0; x < mapSize.x; x += tileSize.x) {
    //         float width = fmin(tileSize.x, mapSize.x - x);
    //         float height = fmin(tileSize.y, mapSize.y - y);
    //         // DrawRectangleV({x, y}, {width, height}, LIGHTGRAY);
    //         DrawRectangleLinesEx({x, y, width, height}, 1, gridColor);
    //     }

    for (float y = 0; y <= mapSize.y; y += tileSize.y)
        DrawLine(0, y, mapSize.x, y, gridColor);
    for (float x = 0; x <= mapSize.x; x += tileSize.x)
        DrawLine(x, 0, x, mapSize.y, gridColor);
}