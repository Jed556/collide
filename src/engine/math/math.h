#ifndef MATH_H
#define MATH_H

#include <raylib.h>
#include <raymath.h>

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

namespace math {
struct Number {
    std::string integer;
    std::string decimal;
};

/**
 * @brief Normalize speed
 *
 * @param speed speed to normalize
 * @return float normalized speed
 */
float normSpeed(float speed);

/**
 * @brief Add leading zeroes to a number
 *
 * @param num number to add leading zeroes to
 * @param targetLength target length of the number
 * @param zeroesOnly only return zeroes
 * @return std::string number with leading zeroes
 */
std::string addLeadingZeroes(double num, int targetLength, bool zeroesOnly);
}  // namespace math

enum EaseType {
    None,
    Legacy,
    Linear,

    // Quadratic Easing
    EaseInQuad,
    EaseOutQuad,
    EaseInOutQuad,

    // Cubic Easing
    EaseInCubic,
    EaseOutCubic,
    EaseInOutCubic,

    // Quartic Easing
    EaseInQuart,
    EaseOutQuart,
    EaseInOutQuart,

    // Quic Easing
    EaseInQuint,
    EaseOutQuint,
    EaseInOutQuint,

    // Sine Easing
    EaseInSine,
    EaseOutSine,
    EaseInOutSine,

    // Elastic Easing
    EaseInElastic,
    EaseOutElastic,
    EaseInOutElastic,

    // Bounce Easing
    EaseInBounce,
    EaseOutBounce,
    EaseInOutBounce,
};

namespace ease {
// Linear Interpolation (LERP)
/**
 * @brief Linear interpolation
 *
 * @param time time
 * @return float
 */
float Linear(float time);

// Quadratic Easing
/**
 * @brief Quadratic easing in
 *
 * @param time time
 * @return float
 */
float EaseInQuad(float time);

/**
 * @brief Quadratic easing out
 *
 * @param time time
 * @return float
 */
float EaseOutQuad(float time);

/**
 * @brief Quadratic easing in and out
 *
 * @param time time
 * @return float
 */
float EaseInOutQuad(float time);

// Cubic Easing
/**
 * @brief Cubic easing in
 *
 * @param time time
 * @return float
 */
float EaseInCubic(float time);

/**
 * @brief Cubic easing out
 *
 * @param time time
 * @return float
 */
float EaseOutCubic(float time);

/**
 * @brief Cubic easing in and out
 *
 * @param time time
 * @return float
 */
float EaseInOutCubic(float time);

// Quartic Easing
/**
 * @brief Quartic easing in
 *
 * @param time time
 * @return float
 */
float EaseInQuart(float time);

/**
 * @brief Quartic easing out
 *
 * @param time time
 * @return float
 */
float EaseOutQuart(float time);

/**
 * @brief Quartic easing in and out
 *
 * @param time time
 * @return float
 */
float EaseInOutQuart(float time);

// Quintic Easing
/**
 * @brief Quintic easing in
 *
 * @param time time
 * @return float
 */
float EaseInQuint(float time);

/**
 * @brief Quintic easing out
 *
 * @param time time
 * @return float
 */
float EaseOutQuint(float time);

/**
 * @brief Quintic easing in and out
 *
 * @param time time
 * @return float
 */
float EaseInOutQuint(float time);

// Sine Easing
/**
 * @brief Sine easing in
 *
 * @param time time
 * @return float
 */
float EaseInSine(float time);

/**
 * @brief Sine easing out
 *
 * @param time time
 * @return float
 */
float EaseOutSine(float time);

/**
 * @brief Sine easing in and out
 *
 * @param time time
 * @return float
 */
float EaseInOutSine(float time);

// Elastic Easing
/**
 * @brief Elastic easing in
 *
 * @param time time
 * @return float
 */
float EaseInElastic(float time);

/**
 * @brief Elastic easing out
 *
 * @param time time
 * @return float
 */
float EaseOutElastic(float time);

/**
 * @brief Elastic easing in and out
 *
 * @param time time
 * @return float
 */
float EaseInOutElastic(float time);

// Bounce Easing
/**
 * @brief Bounce easing in
 *
 * @param time time
 * @return float
 */
float EaseInBounce(float time);

/**
 * @brief Bounce easing out
 *
 * @param time time
 * @return float
 */
float EaseOutBounce(float time);

/**
 * @brief Bounce easing in and out
 *
 * @param time time
 * @return float
 */
float EaseInOutBounce(float time);

/**
 * @brief Ease a value
 *
 * @param time time
 * @param easeType ease type
 * @return float
 */
float Ease(float time, EaseType easeType);
}  // namespace ease

#endif  // MATH_H