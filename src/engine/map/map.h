#ifndef MAP_H
#define MAP_H

#include <raylib.h>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

struct MapTile {
    const char* name;  // name of tile

    // Uses tile unit (e.g. tileX = 1.5 means 1.5 tiles from the left of the map)
    float tileX;       // X position of tile in tiles
    float tileY;       // Y position of tile in tiles
    float tileWidth;   // size of tile in tiles
    float tileHeight;  // size of tile in tiles

    // To be filled in by the engine (DO NOT MODIFY, UNLESS YOU KNOW WHAT YOU ARE DOING)
    float mapX;       // X position of the map
    float mapY;       // Y position of the map
    float mapWidth;   // width of the map
    float mapHeight;  // height of the map
    float tileSize;   // size of a tile

    bool collidable;  // if true, will be added to specified collision list
    bool hasTexture;  // if true, will use texture instead of color
    bool procedural;  // if true, will be generated procedurally, ignoring the x and y values
    Color color;
    Texture2D texture;

    /**
     * @brief Construct a new MapTile object
     *
     * @param name Name of tile
     * @param tilePos Position of tile in tiles
     * @param tileSize Size of tile in tiles
     * @param collidable If true, will be added to specified collision list
     * @param hasTexture If true, will use texture instead of color
     * @param procedural If true, will be generated procedurally, ignoring the x and y values
     * @param color Color of tile
     */
    MapTile(const char* name, Vector2 tilePos, Vector2 tileSize, bool collidable, bool hasTexture, bool procedural, Color color);

    /**
     * @brief Construct a new MapTile object
     *
     * @param name Name of tile
     * @param tilePos Position of tile in tiles
     * @param tileSize Size of tile in tiles
     * @param collidable If true, will be added to specified collision list
     * @param hasTexture If true, will use texture instead of color
     * @param procedural If true, will be generated procedurally, ignoring the x and y values
     * @param texture Texture of tile
     */
    MapTile(const char* name, Vector2 tilePos, Vector2 tileSize, bool collidable, bool hasTexture, bool procedural, Texture2D texture);

    /**
     * @brief Draw the tile
     *
     */
    void draw();

    /**
     * @brief Draw the tile at a specified position
     *
     * @param x X position of tile in tiles
     * @param y Y position of tile in tiles
     */
    void draw(float tileX, float tileY);

    /**
     * @brief Get the Rectangle of the tile
     *
     * @return Rectangle
     */
    Rectangle getRect();
};

struct Map {
    float x;         // X position of map (unit: pixel)
    float y;         // Y position of map (unit: pixel)
    float width;     // width of map (unit: pixel)
    float height;    // height of map (unit: pixel)
    float tileSize;  // size of each tile

    std::vector<MapTile> tiles;   // list of tiles
    const char* defaultTileName;  // default tile to use when a position has no tile

    float genSeed;
    float genTileSpacing;

    Map(Vector2 mapPos, Vector2 mapSize, float tileSize, const char* defaultTileName);

    /**
     * @brief Check if the tiles fit in the map without cuts or spaces
     *
     * @return true if the tiles fit in the map without cuts or spaces
     */
    bool check();

    /**
     * @brief Add a tile to the map
     *
     * @param tile Tile to add
     */
    void addTile(MapTile tile);

    /**
     * @brief Draw the map
     *
     */
    void draw();

    /**
     * @brief Draw the map at a specified position
     *
     * @param x X position of map in pixels
     * @param y Y position of map in pixels
     */
    void draw(float x, float y);

    /**
     * @brief Get the Rectangle of the map
     *
     * @return Rectangle
     */
    Rectangle getRect();

    /**
     * @brief Randomize the seed of the map's procedural generation
     *
     */
    void randomizeSeed();
};

#endif  // MAP_H