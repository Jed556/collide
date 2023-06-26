#include "player.h"

void Player::update() {
    prevPosition = position;

    if (IsKeyDown(KEY_D)) position.x += speed;
    if (IsKeyDown(KEY_A)) position.x -= speed;
    if (IsKeyDown(KEY_S)) position.y += speed;
    if (IsKeyDown(KEY_W)) position.y -= speed;
}