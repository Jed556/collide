#include "control.h"

namespace key {
bool pressed(int key) {
    return IsKeyPressed(key);
}

bool held(int key) {
    return IsKeyDown(key);
}

bool released(int key) {
    return IsKeyReleased(key);
}
}  // namespace key