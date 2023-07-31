#include "debug.h"

void Debug::showGrid(Rectangle map, float tileSize) {
    if (!isActive()) return;

    // Old method
    // for (float y = 0; y < mapSize.y; y += tileSize.y)
    //     for (float x = 0; x < mapSize.x; x += tileSize.x) {
    //         float width = fmin(tileSize.x, mapSize.x - x);
    //         float height = fmin(tileSize.y, mapSize.y - y);
    //         // DrawRectangleV({x, y}, {width, height}, LIGHTGRAY);
    //         DrawRectangleLinesEx({x, y, width, height}, 1, gridColor);
    //     }

    for (float y = 0; y <= map.height; y += tileSize)
        DrawLine(map.x, map.y + y, map.width, map.y + y, gridColor);
    for (float x = 0; x <= map.width; x += tileSize)
        DrawLine(map.x + x, map.y, map.x + x, map.height, gridColor);
}