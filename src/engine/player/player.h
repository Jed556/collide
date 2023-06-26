#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

#include "../math/math.h"

struct Player {
    Vector2 size;
    Vector2 position;
    Vector2 prevPosition;
    Vector2 origin;
    Color color;
    float speed;

    /**
     * @brief Update player position
     *
     */
    void update();

    /**
     * @brief Check if player collides with object
     *
     * @param start start of object
     * @param end end of object
     * @return true if player collides with object
     * @return false if player does not collide with object
     */
    bool collide(Vector2 start, Vector2 end);

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
};

#endif  // PLAYER_H