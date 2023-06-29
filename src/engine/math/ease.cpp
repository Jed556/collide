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

float Ease(float time, EaseType easeType, float start, float end) {
    float ease = 0;
    switch (easeType) {
        case EaseType::None:
            ease = None(time);
            break;
        case EaseType::Linear:
            ease = Linear(time);
            break;

        // Quadratic Easing
        case EaseType::EaseInQuad:
            ease = EaseInQuad(time);
            break;
        case EaseType::EaseOutQuad:
            ease = EaseOutQuad(time);
            break;
        case EaseType::EaseInOutQuad:
            ease = EaseInOutQuad(time);
            break;

        // Cubic Easing
        case EaseType::EaseInCubic:
            ease = EaseInCubic(time);
            break;
        case EaseType::EaseOutCubic:
            ease = EaseOutCubic(time);
            break;
        case EaseType::EaseInOutCubic:
            ease = EaseInOutCubic(time);
            break;

        // Quartic Easing
        case EaseType::EaseInQuart:
            ease = EaseInQuart(time);
            break;
        case EaseType::EaseOutQuart:
            ease = EaseOutQuart(time);
            break;
        case EaseType::EaseInOutQuart:
            ease = EaseInOutQuart(time);
            break;

        // Quintic Easing
        case EaseType::EaseInQuint:
            ease = EaseInQuint(time);
            break;
        case EaseType::EaseOutQuint:
            ease = EaseOutQuint(time);
            break;
        case EaseType::EaseInOutQuint:
            ease = EaseInOutQuint(time);
            break;

        // Sine Easing
        case EaseType::EaseInSine:
            ease = EaseInSine(time);
            break;
        case EaseType::EaseOutSine:
            ease = EaseOutSine(time);
            break;
        case EaseType::EaseInOutSine:
            ease = EaseInOutSine(time);
            break;

        // Elastic Easing
        case EaseType::EaseInElastic:
            ease = EaseInElastic(time);
            break;
        case EaseType::EaseOutElastic:
            ease = EaseOutElastic(time);
            break;
        case EaseType::EaseInOutElastic:
            ease = EaseInOutElastic(time);
            break;

        // Bounce Easing
        case EaseType::EaseInBounce:
            ease = EaseInBounce(time);
            break;
        case EaseType::EaseOutBounce:
            ease = EaseOutBounce(time);
            break;
        case EaseType::EaseInOutBounce:
            ease = EaseInOutBounce(time);
            break;
    }

    return start + (end - start) * ease;
}
}  // namespace ease
