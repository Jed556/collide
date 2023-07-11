#include "entity.h"

Entity::Entity(const char* name, CollisionList& list, Vector2 size, Vector2 position, Vector2 origin, Color color, float speed)
    : name(name), size(size), position(position), prevPosition(position), origin(origin), color(color), speed(speed) {
    this->listIndex = list.add({position.x - origin.x, position.y - origin.y, size.x, size.y}, name);
}

void Entity::draw() {
    DrawRectanglePro({position.x, position.y, size.x, size.y}, origin, 0.0f, color);
}

Vector2 Entity::getHalfSize() {
    return {size.x / 2.0f, size.y / 2.0f};
}

Rectangle Entity::getRect() {
    return {position.x - origin.x, position.y - origin.y, size.x, size.y};
}