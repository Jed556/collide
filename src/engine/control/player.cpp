#include "control.h"

namespace move {
bool W() {
    return key::held(KEY_W);
}

bool A() {
    return key::held(KEY_A);
}

bool S() {
    return key::held(KEY_S);
}

bool D() {
    return key::held(KEY_D);
}

int WASD() {
    if (W()) return 1;
    if (A()) return 2;
    if (S()) return 3;
    if (D()) return 4;
    return ' ';
}

bool up() {
    return key::held(KEY_UP);
}

bool left() {
    return key::held(KEY_LEFT);
}

bool down() {
    return key::held(KEY_DOWN);
}

bool right() {
    return key::held(KEY_RIGHT);
}

int arrow() {
    if (up()) return 1;
    if (left()) return 2;
    if (down()) return 3;
    if (right()) return 4;
    return ' ';
}

bool I() {
    return key::held(KEY_I);
}

bool J() {
    return key::held(KEY_J);
}

bool K() {
    return key::held(KEY_K);
}

bool L() {
    return key::held(KEY_L);
}

int IJKL() {
    if (I()) return 1;
    if (J()) return 2;
    if (K()) return 3;
    if (L()) return 4;
    return ' ';
}

bool numpad8() {
    return key::held(KEY_KP_8);
}

bool numpad4() {
    return key::held(KEY_KP_4);
}

bool numpad6() {
    return key::held(KEY_KP_6);
}

bool numpad2() {
    return key::held(KEY_KP_2);
}

int numpad() {
    if (numpad8()) return 1;
    if (numpad4()) return 2;
    if (numpad6()) return 3;
    if (numpad2()) return 4;
    return ' ';
}

bool space() {
    return key::held(KEY_SPACE);
}
}  // namespace move