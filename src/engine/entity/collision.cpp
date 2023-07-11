#include "entity.h"

void Entity::updateCollider(CollisionList& list) {
    list.update(name, {position.x - origin.x, position.y - origin.y, size.x, size.y});
}

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

bool Entity::collidesWithRect(Rectangle other) {
    if (CheckCollisionRecs({position.x, position.y, size.x, size.y}, other)) {
        Vector2 mtv = math::getMTV(getRect(), other);
        position.x += mtv.x;
        position.y += mtv.y;
        return true;
    }
    return false;
}

std::vector<int> Entity::collidesWithList(CollisionList& list) {
    std::vector<int> collided;
    std::vector<int> index = list.checkCollision(getRect());
    for (int i = 0; i < index.size(); i++) {
        if (list.getName(index[i]) != this->name) {
            Vector2 mtv = math::getMTV(getRect(), list.getRect(index[i]));
            position.x += mtv.x;
            position.y += mtv.y;
            collided.push_back(index[i]);
        }
    }
    return collided;
}