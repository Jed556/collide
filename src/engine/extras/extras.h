#ifndef SHAPE_H
#define SHAPE_H

#include <raylib.h>

typedef struct Circle {
    float x;
    float y;
    float radius;
} Circle;

typedef Circle Circle2D;

namespace extras {
typedef struct Circle {
    float x;
    float y;
    float radius;

    Circle get();
    void draw(Color color);
    void drawGradient(Color color1, Color color2);
    void drawLines(Color color);
} Circle;

typedef struct Rectangle {
    float x;
    float y;
    float width;
    float height;

    Rectangle get();
    void draw(Color color);
    void drawGradientV(Color color1, Color color2);
    void drawGradientH(Color color1, Color color2);
    void drawGradient(Color col1, Color col2, Color col3, Color col4);
    void drawLines(Color color);
    void drawLinesEx(Color color, int lineThick);
    void drawRounded(float roundness, int segments, Color color);
    void drawRoundedLines(float roundness, int segments, int lineThick, Color color);
} Rectangle;
};  // namespace extras

#endif  // SHAPE_H