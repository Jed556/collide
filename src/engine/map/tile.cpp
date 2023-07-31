#include "map.h"

MapTile::MapTile(const char* name, Vector2 tilePos, Vector2 tileSize, bool collidable, bool hasTexture, bool procedural, Color color) {
    this->name = name;
    this->tileX = tilePos.x;
    this->tileY = tilePos.y;
    this->tileWidth = tileSize.x;
    this->tileHeight = tileSize.y;
    this->collidable = collidable;
    this->hasTexture = hasTexture;
    this->procedural = procedural;
    this->color = color;
}

MapTile::MapTile(const char* name, Vector2 tilePos, Vector2 tileSize, bool collidable, bool hasTexture, bool procedural, Texture2D texture) {
    this->name = name;
    this->tileX = tilePos.x;
    this->tileY = tilePos.y;
    this->tileWidth = tileSize.x;
    this->tileHeight = tileSize.y;
    this->collidable = collidable;
    this->hasTexture = hasTexture;
    this->procedural = procedural;
    this->texture = texture;
}

void MapTile::draw() {
    draw(tileX, tileY);
}

void MapTile::draw(float tileX, float tileY) {
    if (hasTexture) {
        DrawTexture(texture, (tileX * tileSize) + mapX, (tileY * tileSize) + mapY, WHITE);
    } else {
        // DrawRectangle((tileX * tileSize) + mapX, (tileY * tileSize) + mapY, tileWidth * tileSize, tileHeight * tileSize, color);
        float x = (tileX * tileSize) + mapX;
        float y = (tileY * tileSize) + mapY;
        float width = tileWidth * tileSize;
        float height = tileHeight * tileSize;

        // Check width and height for negative values
        if (width < 0) {
            x += tileSize;
        }
        if (height < 0) {
            y += tileSize;
        }

        // Position is less than map position
        if (x < mapX) {
            width += x;
            x = mapX;
        }
        if (y < mapY) {
            height += y;
            y = mapY;
        }

        // Position is greater than map size
        if (x > mapX + mapWidth) {
            width = 0;
        }
        if (y > mapY + mapHeight) {
            height = 0;
        }

        // Dimensions are less than map position
        if (width < 0 && x + width < mapX) {
            width = mapX - x;
        }
        if (height < 0 && y + height < mapY) {
            height = mapY - y;
        }

        // Dimensions are greater than map size
        if (x + width > mapWidth) {
            width = mapWidth - x;
        }
        if (y + height > mapHeight) {
            height = mapHeight - y;
        }

        DrawRectangle(x, y, width, height, color);
    }
}