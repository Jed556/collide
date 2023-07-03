#ifndef DISPLAY_H
#define DISPLAY_H

#include <raylib.h>

namespace display {
/**
 * @brief Set window FPS
 *
 * @param fps FPS to set (0 = monitor refresh rate)
 */
void setFPS(int fps);

/**
 * @brief Get frame count
 *
 * @return int frame count
 */
int getFrameCount();

/**
 * @brief display user defined cursor
 *
 */
void showCustomCursor();

/**
 * @brief Initialize window
 *
 * @param dimension Window dimension to set
 * @param title Window title to set
 */
void init(Vector2 dimension, const char* title, const char* iconPath);

/**
 * @brief Close window
 */
void close();
}  // namespace display

#endif  // DISPLAY_H