#include "entity.h"

bool Entity::outOfBounds(Vector2 start, Vector2 end) {
    bool collided = false;
    Vector2 newPosition = position;

    if (position.x < start.x) {
        newPosition.x = start.x;
        collided = true;
    } else if (position.x + size.x > start.x + end.x) {
        newPosition.x = start.x + end.x - size.x;
        collided = true;
    }

    if (position.y < start.y) {
        newPosition.y = start.y;
        collided = true;
    } else if (position.y + size.y > start.y + end.y) {
        newPosition.y = start.y + end.y - size.y;
        collided = true;
    }

    if (collided) position = newPosition;
    return collided;
}

bool Entity::collidesWith(Rectangle other) {
    bool check = CheckCollisionRecs({position.x, position.y, size.x, size.y}, {other.x, other.y, other.width, other.height});
    if (check)
        position = prevPosition;
    return check;
}