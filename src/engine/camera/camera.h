#ifndef CAMERA_H
#define CAMERA_H

#include <raylib.h>

#include "../entity/entity.h"
#include "../math/math.h"

struct GameCamera {
    Camera2D prop;  // camera properties
    float speed;

    /**
     * @brief Construct a new Game Camera object
     *
     * @param target target position of camera
     * @param offset offset of camera
     * @param rotation rotation of camera
     * @param zoom zoom of camera
     * @param speed speed of camera
     */
    GameCamera(Vector2 target, Vector2 offset, float rotation, float zoom, float speed);

    /**
     * @brief Update camera position
     *
     * @param position position of object to follow
     * @param size size of object to follow
     * @param easeType ease type to use
     */
    void update(Vector2 position, EaseType easeType);

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