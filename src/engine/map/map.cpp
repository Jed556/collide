#include "map.h"

Map::Map(Vector2 mapPos, Vector2 mapSize, float tileSize, const char* defaultTileName) {
    this->x = mapPos.x;
    this->y = mapPos.y;
    this->width = mapSize.x;
    this->height = mapSize.y;
    this->tileSize = tileSize;
    this->defaultTileName = defaultTileName;
}

bool Map::check() {
    int tileX = static_cast<int>(x / tileSize);
    int tileY = static_cast<int>(y / tileSize);
    int tileRightX = static_cast<int>((x + width) / tileSize + ((fmod(x + width, tileSize) == 0) ? 0 : 1));
    int tileBottomY = static_cast<int>((y + height) / tileSize + ((fmod(y + height, tileSize) == 0) ? 0 : 1));
    return tileX == tileRightX - 1 && tileY == tileBottomY - 1;
}

void Map::draw() {
    draw(x, y);
}

void Map::draw(float x, float y) {
    for (int i = 0; i < width / tileSize; i++) {
        for (int j = 0; j < height / tileSize; j++) {
            bool tileFound = false;
            for (int k = 0; k < tiles.size(); k++) {
                if (tiles[k].tileX == i && tiles[k].tileY == j) {
                    tiles[k].draw();
                    tileFound = true;
                    break;
                }
            }
            if (!tileFound) {
                bool overlaps = false;
                for (const auto& tile : tiles) {
                    if (tile.tileX <= i && i < tile.tileX + tile.tileWidth && tile.tileY <= j && j < tile.tileY + tile.tileHeight) {
                        overlaps = true;
                        break;
                    }
                }
                if (!overlaps) {
                    auto it = std::find_if(tiles.begin(), tiles.end(), [&](const MapTile& tile) {
                        return std::strcmp(tile.name, defaultTileName) == 0;
                    });
                    if (it != tiles.end()) {
                        it->draw(i, j);
                    }
                }
            }
        }
    }
}

Rectangle Map::getRect() {
    return {x, y, width, height};
}

void Map::addTile(MapTile tile) {
    MapTile newTile(tile.name, {tile.tileX, tile.tileY}, {tile.tileWidth, tile.tileHeight}, tile.collidable, tile.hasTexture, tile.procedural, PURPLE);

    if (tile.hasTexture)
        newTile.texture = tile.texture;
    else
        newTile.color = tile.color;

    newTile.mapX = x;
    newTile.mapY = y;
    newTile.mapWidth = width;
    newTile.mapHeight = height;
    newTile.tileSize = tileSize;
    tiles.push_back(newTile);
}