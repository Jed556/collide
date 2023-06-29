#include "math.h"

namespace math {
float normSpeed(float speed) {
    // DO NOT CHANGE THIS ALL SYSTEM SPEEDS RELY ON THIS
    return speed * 10.0f * GetFrameTime();
}

std::string addLeadingZeroes(double num, int targetLength, bool zeroesOnly) {
    std::ostringstream ss;
    ss << num;
    std::string str = ss.str();
    int len = str.length();
    std::string zeroes = "";
    if (len < targetLength) zeroes = std::string(targetLength - len, '0');

    return zeroes + (zeroesOnly ? "" : str);
}
}  // namespace math