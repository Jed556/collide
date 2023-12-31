#include "entity.h"

void Entity::move(bool dPad, int scheme) {
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

void Entity::randomMove(Vector2 mapSize) {
    position = {(float)GetRandomValue(0, mapSize.x), (float)GetRandomValue(0, mapSize.y)};
}