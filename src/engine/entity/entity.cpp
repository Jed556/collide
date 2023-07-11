#include "entity.h"

Entity::Entity(const char* name, CollisionList& list, Vector2 size, Vector2 position, Vector2 origin, Color color, float speed) {
    this->name = name;
    this->listIndex = list.addRect({position.x, position.y, size.x, size.y}, name);

    this->size = size;
    this->position = position;
    this->prevPosition = position;
    this->origin = origin;
    this->color = color;
    this->speed = speed;
}

void Entity::draw() {
    DrawRectanglePro({position.x, position.y, size.x, size.y}, origin, 0.0f, color);
}

Vector2 Entity::getHalfSize() {
    return {size.x / 2.0f, size.y / 2.0f};
}

Rectangle Entity::getRect() {
    return {position.x, position.y, size.x, size.y};
}