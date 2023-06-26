#include "math.h"

namespace math {
float normSpeed(float speed) {
    return speed * 10.0f * GetFrameTime();
}
}  // namespace math