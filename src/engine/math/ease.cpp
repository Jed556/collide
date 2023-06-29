#include "math.h"

namespace ease {
float None(float time) {
    return time;
}

float Linear(float time) {
    return time;
}

// Quadratic Easing
float EaseInQuad(float time) {
    return time * time;
}

float EaseOutQuad(float time) {
    return time * (2 - time);
}

float EaseInOutQuad(float time) {
    time *= 2;
    if (time < 1)
        return 0.5f * time * time;
    time--;
    return -0.5f * (time * (time - 2) - 1);
}

// Cubic Easing
float EaseInCubic(float time) {
    return time * time * time;
}

float EaseOutCubic(float time) {
    time--;
    return time * time * time + 1;
}

float EaseInOutCubic(float time) {
    time *= 2;
    if (time < 1)
        return 0.5f * time * time * time;
    time -= 2;
    return 0.5f * (time * time * time + 2);
}

// Quartic Easing
float EaseInQuart(float time) {
    return time * time * time * time;
}

float EaseOutQuart(float time) {
    time--;
    return -(time * time * time * time - 1);
}

float EaseInOutQuart(float time) {
    time *= 2;
    if (time < 1)
        return 0.5f * time * time * time * time;
    time -= 2;
    return -0.5f * (time * time * time * time - 2);
}

// Quintic Easing
float EaseInQuint(float time) {
    return time * time * time * time * time;
}

float EaseOutQuint(float time) {
    time--;
    return time * time * time * time * time + 1;
}

float EaseInOutQuint(float time) {
    time *= 2;
    if (time < 1)
        return 0.5f * time * time * time * time * time;
    time -= 2;
    return 0.5f * (time * time * time * time * time + 2);
}

// Sine Easing
float EaseInSine(float time) {
    return 1 - cos(time * PI / 2);
}

float EaseOutSine(float time) {
    return sin(time * PI / 2);
}

float EaseInOutSine(float time) {
    return -0.5f * (cos(PI * time) - 1);
}

// Elastic Easing
float EaseInElastic(float time) {
    if (time == 0 || time == 1)
        return time;
    float p = 0.3f;
    float s = p / 4;
    time -= 1;
    return -powf(2, 10 * time) * sinf((time - s) * (2 * PI) / p);
}

float EaseOutElastic(float time) {
    if (time == 0 || time == 1)
        return time;
    float p = 0.3f;
    float s = p / 4;
    return powf(2, -10 * time) * sinf((time - s) * (2 * PI) / p) + 1;
}

float EaseInOutElastic(float time) {
    if (time == 0 || time == 1)
        return time;
    time *= 2;
    float p = 0.3f * 1.5f;
    float s = p / 4;
    if (time < 1) {
        time -= 1;
        return -0.5f * (powf(2, 10 * time) * sinf((time - s) * (2 * PI) / p));
    }
    time -= 1;
    return powf(2, -10 * time) * sinf((time - s) * (2 * PI) / p) * 0.5f + 1;
}

// Bounce Easing
float EaseInBounce(float time) {
    return 1 - EaseOutBounce(1 - time);
}

float EaseOutBounce(float time) {
    if (time < (1 / 2.75f))
        return 7.5625f * time * time;
    else if (time < (2 / 2.75f)) {
        time -= (1.5f / 2.75f);
        return 7.5625f * time * time + 0.75f;
    } else if (time < (2.5 / 2.75)) {
        time -= (2.25f / 2.75f);
        return 7.5625f * time * time + 0.9375f;
    } else {
        time -= (2.625f / 2.75f);
        return 7.5625f * time * time + 0.984375f;
    }
}

float EaseInOutBounce(float time) {
    if (time < 0.5f)
        return EaseInBounce(time * 2) * 0.5f;
    return EaseOutBounce(time * 2 - 1) * 0.5f + 0.5f;
}

float Ease(float time, EaseType easeType) {
    switch (easeType) {
        case EaseType::None:
            return None(time);
        case EaseType::Linear:
            return Linear(time);

        // Quadratic Easing
        case EaseType::EaseInQuad:
            return EaseInQuad(time);
        case EaseType::EaseOutQuad:
            return EaseOutQuad(time);
        case EaseType::EaseInOutQuad:
            return EaseInOutQuad(time);

        // Cubic Easing
        case EaseType::EaseInCubic:
            return EaseInCubic(time);
        case EaseType::EaseOutCubic:
            return EaseOutCubic(time);
        case EaseType::EaseInOutCubic:
            return EaseInOutCubic(time);

        // Quartic Easing
        case EaseType::EaseInQuart:
            return EaseInQuart(time);
        case EaseType::EaseOutQuart:
            return EaseOutQuart(time);
        case EaseType::EaseInOutQuart:
            return EaseInOutQuart(time);

        // Quintic Easing
        case EaseType::EaseInQuint:
            return EaseInQuint(time);
        case EaseType::EaseOutQuint:
            return EaseOutQuint(time);
        case EaseType::EaseInOutQuint:
            return EaseInOutQuint(time);

        // Sine Easing
        case EaseType::EaseInSine:
            return EaseInSine(time);
        case EaseType::EaseOutSine:
            return EaseOutSine(time);
        case EaseType::EaseInOutSine:
            return EaseInOutSine(time);

        // Elastic Easing
        case EaseType::EaseInElastic:
            return EaseInElastic(time);
        case EaseType::EaseOutElastic:
            return EaseOutElastic(time);
        case EaseType::EaseInOutElastic:
            return EaseInOutElastic(time);

        // Bounce Easing
        case EaseType::EaseInBounce:
            return EaseInBounce(time);
        case EaseType::EaseOutBounce:
            return EaseOutBounce(time);
        case EaseType::EaseInOutBounce:
            return EaseInOutBounce(time);
    }

    return 0;
}
}  // namespace ease
