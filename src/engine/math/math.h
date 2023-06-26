#ifndef MATH_H
#define MATH_H

#include <raylib.h>
#include <raymath.h>

namespace math {
/**
 * @brief Normalize speed
 *
 * @param speed speed to normalize
 * @return float normalized speed
 */
float normSpeed(float speed);
}  // namespace math

#endif  // MATH_H