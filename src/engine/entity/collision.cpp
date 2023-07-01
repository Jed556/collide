#include "entity.h"

bool Entity::outOfBounds(Vector2 start, Vector2 end) {
    bool out = false;

    if (position.x < start.x) {
        position.x = start.x;
        out = true;
    } else if (position.x + size.x > start.x + end.x) {
        position.x = start.x + end.x - size.x;
        out = true;
    }

    if (position.y < start.y) {
        position.y = start.y;
        out = true;
    } else if (position.y + size.y > start.y + end.y) {
        position.y = start.y + end.y - size.y;
        out = true;
    }

    return out;
}

bool Entity::collidesWith(Rectangle other) {
    if (CheckCollisionRecs({position.x, position.y, size.x, size.y}, other)) {
        Vector2 mtv = math::getMTV(getRect(), other);
        position.x += mtv.x;
        position.y += mtv.y;
        return true;
    } else {
        return false;
    }
}