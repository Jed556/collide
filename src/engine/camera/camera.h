#ifndef CAMERA_H
#define CAMERA_H

#include <raylib.h>

#include "../player/player.h"

struct GameCamera {
    Camera2D prop;  // camera properties
    float speed;

    /**
     * @brief Update camera position
     *
     * @param position position of object to follow
     * @param size size of object to follow
     * @param ease ease camera movement
     * @param focus focus on anchor 1-8 (1: top left, 5: center, 8: bottom right)
     */
    void update(Vector2 position, Vector2 size, bool ease, int focus);

    /**
     * @brief Begin camera mode
     *
     */
    void begin();

    /**
     * @brief End camera mode
     *
     */
    void end();
};

#endif  // CAMERA_H