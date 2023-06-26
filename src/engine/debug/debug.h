#ifndef DEBUG_H
#define DEBUG_H

#include <raylib.h>
#include <raymath.h>

#include <string>

class Debug {
   private:
    Vector2 screenSize;

    Font font = GetFontDefault();
    float fontSize = 20;
    float fontSpacing = 2;
    Color textColor = (Color){0, 0, 0, 255 / 3};
    Color gridColor = (Color){0, 0, 0, 50};

    int numShown = 0;
    float infoSpacing = 22;
    Vector2 infoPadding = {6, 5};

   public:
    Debug(Vector2 screenSize);
    void begin();
    void showOverlays(bool showCenterPoint, bool showCenterCross);
    void showGrid(Vector2 mapSize, Vector2 tileSize);
    void showCenter(bool showPoint, bool showCross);
    void showFPS();
    void showPosition(Vector2 objectPosition, Vector2 objectSize, bool centered, int intPrecision, std::string name);
};  // namespace debug

#endif  // DEBUG_H