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
    void update();
    bool collide(Vector2 start, Vector2 end);
    void draw();
    Vector2 getHalfSize();
};

#endif  // PLAYER_H