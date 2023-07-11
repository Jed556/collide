#include "extras.h"

namespace extras {
Circle Circle::get() {
    return {x, y, radius};
}

void Circle::draw(Color color) {
    DrawCircle(x, y, radius, color);
}

void Circle::drawGradient(Color color1, Color color2) {
    DrawCircleGradient(x, y, radius, color1, color2);
}

void Circle::drawLines(Color color) {
    DrawCircleLines(x, y, radius, color);
}

Rectangle Rectangle::get() {
    return {x, y, width, height};
}

void Rectangle::draw(Color color) {
    DrawRectangle(x, y, width, height, color);
}

void Rectangle::drawGradientV(Color color1, Color color2) {
    DrawRectangleGradientV(x, y, width, height, color1, color2);
}

void Rectangle::drawGradientH(Color color1, Color color2) {
    DrawRectangleGradientH(x, y, width, height, color1, color2);
}

void Rectangle::drawGradient(Color col1, Color col2, Color col3, Color col4) {
    DrawRectangleGradientEx({x, y, width, height}, col1, col2, col3, col4);
}

void Rectangle::drawLines(Color color) {
    DrawRectangleLines(x, y, width, height, color);
}

void Rectangle::drawLinesEx(Color color, int lineThick) {
    DrawRectangleLinesEx({x, y, width, height}, lineThick, color);
}

void Rectangle::drawRounded(float roundness, int segments, Color color) {
    DrawRectangleRounded({x, y, width, height}, roundness, segments, color);
}

void Rectangle::drawRoundedLines(float roundness, int segments, int lineThick, Color color) {
    DrawRectangleRoundedLines({x, y, width, height}, roundness, segments, lineThick, color);
}

}  // namespace extras