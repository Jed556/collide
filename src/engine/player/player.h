#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

struct Player {
    Vector2 position;
    Vector2 prevPosition;
    Vector2 size;
    Color color;
    float speed;
    void update();
    bool collide(Vector2 start, Vector2 end);
    void draw();
};

#endif  // PLAYER_H