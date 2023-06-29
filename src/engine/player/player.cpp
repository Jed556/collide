#include "player.h"

Player::Player(Vector2 size, Vector2 position, Vector2 origin, Color color, float speed) {
    this->size = size;
    this->position = position;
    this->prevPosition = position;
    this->origin = origin;
    this->color = color;
    this->speed = speed;
}

void Player::move(bool dPad, int scheme) {
    prevPosition = position;
    if (dPad) {
        int pressed = 0;
        switch (scheme) {
            case 0:
                pressed = move::WASD();
                break;
            case 1:
                pressed = move::arrow();
                break;
            case 2:
                pressed = move::IJKL();
                break;
            case 3:
                pressed = move::numpad();
                break;
        }
        switch (pressed) {
            case 1:
                position.y -= math::normSpeed(speed);
                break;
            case 2:
                position.x -= math::normSpeed(speed);
                break;
            case 3:
                position.y += math::normSpeed(speed);
                break;
            case 4:
                position.x += math::normSpeed(speed);
                break;
            default:
                break;
        }
    } else {
        switch (scheme) {
            case 0:
                if (move::W()) position.y -= math::normSpeed(speed);
                if (move::A()) position.x -= math::normSpeed(speed);
                if (move::S()) position.y += math::normSpeed(speed);
                if (move::D()) position.x += math::normSpeed(speed);
                break;
            case 1:
                if (move::up()) position.y -= math::normSpeed(speed);
                if (move::left()) position.x -= math::normSpeed(speed);
                if (move::down()) position.y += math::normSpeed(speed);
                if (move::right()) position.x += math::normSpeed(speed);
                break;
            case 2:
                if (move::I()) position.y -= math::normSpeed(speed);
                if (move::J()) position.x -= math::normSpeed(speed);
                if (move::K()) position.y += math::normSpeed(speed);
                if (move::L()) position.x += math::normSpeed(speed);
                break;
            case 3:
                if (move::numpad8()) position.y -= math::normSpeed(speed);
                if (move::numpad4()) position.x -= math::normSpeed(speed);
                if (move::numpad2()) position.y += math::normSpeed(speed);
                if (move::numpad6()) position.x += math::normSpeed(speed);
                break;
        }
    }
}

bool Player::collide(Vector2 start, Vector2 end) {
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

void Player::draw() {
    DrawRectanglePro({position.x, position.y, size.x, size.y}, origin, 0.0f, color);
}

Vector2 Player::getHalfSize() {
    return {size.x / 2.0f, size.y / 2.0f};
}