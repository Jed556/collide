#include "math.h"

namespace math {
float normSpeed(float speed) {
    // DO NOT CHANGE THIS ALL SYSTEM SPEEDS RELY ON THIS
    return speed * GetFrameTime();
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

Vector2 getMTV(Rectangle rect1, Rectangle rect2) {
    Vector2 mtv = {0, 0};

    float xOverlap = rect1.x + rect1.width - rect2.x;
    float yOverlap = rect1.y + rect1.height - rect2.y;
    float xOverlapNeg = rect2.x + rect2.width - rect1.x;
    float yOverlapNeg = rect2.y + rect2.height - rect1.y;

    if (xOverlap < xOverlapNeg && xOverlap < yOverlap && xOverlap < yOverlapNeg) {
        mtv.x = -xOverlap;
    } else if (xOverlapNeg < xOverlap && xOverlapNeg < yOverlap && xOverlapNeg < yOverlapNeg) {
        mtv.x = xOverlapNeg;
    } else if (yOverlap < xOverlap && yOverlap < xOverlapNeg && yOverlap < yOverlapNeg) {
        mtv.y = -yOverlap;
    } else {
        mtv.y = yOverlapNeg;
    }

    return mtv;
}
}  // namespace math