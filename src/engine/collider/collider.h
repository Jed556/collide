#ifndef COLLIDER_H
#define COLLIDER_H

#include <raylib.h>

#include <iostream>
#include <vector>

#include "../extras/extras.h"

struct Collider {
    Rectangle rect;
    Circle circle;
    int type;  // 0 = rect, 1 = circle
    const char* name;
};

struct CollisionList {
    std::vector<Collider> list;

    /**
     * @brief Add a rectangle to list
     *
     * @param rect Rectangle to add
     * @param name Unique name of rectangle
     * @return int index of added rectangle (i + 1)
     */
    int add(Rectangle rect, const char* name);

    /**
     * @brief Add a circle to list
     *
     * @param circle Circle to add
     * @param name Unique name of circle
     * @return int index of added circle (i + 1)
     */
    int add(Circle circle, const char* name);

    /**
     * @brief Update a rectangle in the list
     *
     * @param index index of rectangle (i + 1)
     * @param rect new rectangle properties
     */
    void update(int index, Rectangle rect);

    /**
     * @brief Update a circle in the list
     *
     * @param index index of circle (i + 1)
     * @param circle new circle properties
     */
    void update(int index, Circle circle);

    /**
     * @brief Update a rectangle in the list
     *
     * @param name name of rectangle
     * @param rect new rectangle properties
     */
    void update(const char* name, Rectangle rect);

    /**
     * @brief Update a circle in the list
     *
     * @param name name of circle
     * @param circle new circle properties
     */
    void update(const char* name, Circle circle);

    /**
     * @brief Get the Rectangle object
     *
     * @param index index of rectangle (i + 1)
     * @return Rectangle
     */
    Rectangle getRect(int index);

    /**
     * @brief Get the Circle object
     *
     * @param index index of circle (i + 1)
     * @return Circle
     */
    Circle getCircle(int index);

    /**
     * @brief Get the name of the object
     *
     * @param index index of object (i + 1)
     * @return const char* name of object
     */
    const char* getName(int index);

    /**
     * @brief Get the list of objects
     *
     * @return std::vector<Collider>
     */
    std::vector<Collider> getList();

    /**
     * @brief Draw all collision boxes
     *
     * @param color color of collision box lines
     * @param fill fill collision boxes with color
     * @param width width of collision box lines (if fill is false)
     */
    void draw(Color color, bool fill, int width);

    /**
     * @brief Check if rectangle collides with any of the rectangles in the list
     *
     * @param rect rectangle to check collision with
     * @return int index of rectangle (i + 1)
     */
    std::vector<int> checkCollision(Rectangle rect);

    /**
     * @brief Check if circle collides with any of the circles in the list
     *
     * @param circle circle to check collision with
     * @return int index of circle (i + 1)
     */
    std::vector<int> checkCollision(Circle circle);

    /**
     * @brief Check if any of the objects in the list collide with any of the objects in the other list
     *
     * @param otherList list to check collision with
     * @return int index of object (i + 1)
     */
    std::vector<int> checkCollision(CollisionList otherList);

    /**
     * @brief Check if rectangle collides with any of the rectangles in the list
     *
     * @param rect rectangle to check collision with
     * @param name name of rectangle
     * @return int index of rectangle (i + 1)
     */
    std::vector<int> checkCollision(Rectangle rect, const char* name);

    /**
     * @brief Check if circle collides with any of the circles in the list
     *
     * @param circle circle to check collision with
     * @param name name of circle
     * @return int index of circle (i + 1)
     */
    std::vector<int> checkCollision(Circle circle, const char* name);

    /**
     * @brief Check if any of the objects in the list collide with any of the objects in the other list
     *
     * @param otherList list to check collision with
     * @param name name of object
     * @return int index of object (i + 1)
     */
    std::vector<int> checkCollision(CollisionList otherList, const char* name);
};

#endif  // COLLIDER_H