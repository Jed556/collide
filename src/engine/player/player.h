#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

#include "../control/control.h"
#include "../math/math.h"

struct Player {
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
    Player(Vector2 size, Vector2 position, Vector2 origin, Color color, float speed);

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