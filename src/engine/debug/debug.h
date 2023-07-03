#ifndef DEBUG_H
#define DEBUG_H

#include <fmt/format.h>
#include <raylib.h>

#include <string>
#include <vector>

#include "../control/control.h"
#include "../display/display.h"
#include "../math/math.h"

class Debug {
   private:
    bool debugMode = false;
    Vector2 screenSize;
    int frameCount = 0;

    Font font;
    float fontSize = 20;
    float fontSpacing = 2;
    Color textColor = (Color){0, 0, 0, 255 / 3};
    Color gridColor = (Color){0, 0, 0, 50};

    int numShown = 0;
    float infoSpacing = 22;
    Vector2 infoPadding = {6, 5};
    Vector2 listPadding = {15, 15};

    float getNextInfoY();

   public:
    /**
     * @brief Construct a new Debug object
     *
     * @param screenSize Window dimensions
     */
    Debug(Vector2 screenSize, Font font);

    /**
     * @brief Toggle debug mode
     *
     */
    void toggle();

    /**
     * @brief Check if debug mode is active
     *
     * @return true
     * @return false
     */
    bool isActive();

    /**
     * @brief Begin debug / reset debug data
     *
     */
    void begin();

    /**
     * @brief Show pre-set overlays
     *
     * @param showCenterPoint Show center point
     * @param showCenterCross Show center cross
     */
    void showOverlays(bool showCenterPoint, bool showCenterCross);

    /**
     * @brief Show map grid
     *
     * @param mapSize Map size
     * @param tileSize Tile size
     */
    void showGrid(Vector2 mapSize, Vector2 tileSize);

    /**
     * @brief Show center point and cross
     *
     * @param showPoint Show center point
     * @param showCross Show center cross
     */
    void showCenter(bool showPoint, bool showCross);

    /**
     * @brief Show FPS
     *
     */
    void showFPS();

    /**
     * @brief Show memory usage
     *
     */
    // void showMemoryUsage();

    /**
     * @brief Get the current memory usage
     *
     * @return int
     */
    // int getCurrentMemoryUsage();

    /**
     * @brief Show mouse position
     *
     */
    void showMousePosition();

    /**
     * @brief Show key pressed
     *
     * @param valueOnly Show integer value only
     */
    void showKeyPressed(bool valueOnly);

    /**
     * @brief Show object position
     *
     * @param objectPosition Object position
     * @param objectSize Object size
     * @param centered Calculate center position
     * @param intPrecision Integer precision
     * @param name Object name
     */
    void showPosition(Vector2 objectPosition, Vector2 objectSize, bool centered, std::string name);
};  // namespace debug

#endif  // DEBUG_H