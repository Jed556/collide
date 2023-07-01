#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>

#include "../control/control.h"
#include "../math/math.h"

struct Entity {
    Vector2 size;
    Vector2 position;
    Vector2 prevPosition;
    Vector2 origin;
    Color color;
    float speed;

    /**
     * @brief Construct a new Player object
     *
     * @param size size of player
     * @param position position of player
     * @param origin origin of player
     * @param color color of player
     * @param speed speed of player
     */
    Entity(Vector2 size, Vector2 position, Vector2 origin, Color color, float speed);

    /**
     * @brief Update player position based on input
     *
     * @param dPad if only one key can be pressed at a time
     * @param scheme 0 for WASD, 1 for arrow keys, 2 for IJKL, 3 for numpad
     */
    void move(bool dPad = false, int scheme = 0);

    /**
     * @brief Move player randomly
     *
     * @param mapSize size of map
     */
    void randomMove(Vector2 mapSize);

    /**
     * @brief Check if player collides with object
     *
     * @param start start of map
     * @param end end of map
     * @return true if player is out of bounds
     */
    bool outOfBounds(Vector2 start, Vector2 end);

    /**
     * @brief Check if player collides with object
     *
     * @param object object to check collision with
     * @return true if player collides with object
     */
    bool collidesWith(Rectangle object);

    /**
     * @brief Draw player
     *
     */
    void draw();

    /**
     * @brief Get half size of player
     *
     * @return Vector2
     */
    Vector2 getHalfSize();

    /**
     * @brief Get the Rectangle of the player
     *
     * @return Rectangle
     */
    Rectangle getRect();
};

#endif  // ENTITY_H