#ifndef CONTROL_H
#define CONTROL_H

#include <raylib.h>

namespace key {
/**
 * @brief Check if key is pressed
 *
 * @param key Key to check
 * @return true
 * @return false
 */
bool pressed(int key);

/**
 * @brief Check if key is held
 *
 * @param key Key to check
 * @return true
 * @return false
 */
bool held(int key);

/**
 * @brief Check if key is released
 *
 * @param key Key to check
 * @return true
 * @return false
 */
bool released(int key);

/**
 * @brief Check if debug key is pressed
 *
 * @return true
 * @return false
 */
bool debug();
}  // namespace key

namespace move {
/**
 * @brief Check if player is pressing W
 *
 * @return true
 * @return false
 */
bool W();

/**
 * @brief Check if player is pressing A
 *
 * @return true
 * @return false
 */
bool A();

/**
 * @brief Check if player is pressing S
 *
 * @return true
 * @return false
 */
bool S();

/**
 * @brief Check if player is pressing D
 *
 * @return true
 * @return false
 */
bool D();

/**
 * @brief Check if player is pressing WASD
 *
 * @return int (1 for W, 2 for A, 3 for S, 4 for D, 0 for none)
 */
int WASD();

/**
 * @brief Check if player is pressing up arrow
 *
 * @return true
 * @return false
 */
bool up();

/**
 * @brief Check if player is pressing left arrow
 *
 * @return true
 * @return false
 */
bool left();

/**
 * @brief Check if player is pressing down arrow
 *
 * @return true
 * @return false
 */
bool down();

/**
 * @brief Check if player is pressing right arrow
 *
 * @return true
 * @return false
 */
bool right();

/**
 * @brief Check if player is pressing arrow keys
 *
 * @return int (1 for up, 2 for left, 3 for down, 4 for right, 0 for none)
 */
int arrow();

/**
 * @brief Check if player is pressing I
 *
 * @return true
 * @return false
 */
bool I();

/**
 * @brief Check if player is pressing J
 *
 * @return true
 * @return false
 */
bool J();

/**
 * @brief Check if player is pressing K
 *
 * @return true
 * @return false
 */
bool K();

/**
 * @brief Check if player is pressing L
 *
 * @return true
 * @return false
 */
bool L();

/**
 * @brief Check if player is pressing IJKL
 *
 * @return int (1 for I, 2 for J, 3 for K, 4 for L, 0 for none)
 */
int IJKL();

/**
 * @brief Check if player is pressing numpad 8
 *
 * @return true
 * @return false
 */
bool numpad8();

/**
 * @brief Check if player is pressing numpad 4
 *
 * @return true
 * @return false
 */
bool numpad4();

/**
 * @brief Check if player is pressing numpad 2
 *
 * @return true
 * @return false
 */
bool numpad2();

/**
 * @brief Check if player is pressing numpad 6
 *
 * @return true
 * @return false
 */
bool numpad6();

/**
 * @brief Check if player is pressing numpad
 *
 * @return int (1 for 8, 2 for 4, 3 for 5, 4 for 6, 0 for none)
 */
int numpad();

/**
 * @brief Check if player is pressing space
 *
 * @return true
 * @return false
 */
bool space();
}  // namespace move

#endif  // CONTROL_H