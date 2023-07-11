#ifndef COLLIDER_H
#define COLLIDER_H

#include <raylib.h>

#include <vector>
#include <iostream>

#include "../extras/extras.h"

class CollisionList {
   private:
    struct Collider {
        Rectangle rect;
        Circle circle;
        int type;  // 0 = rect, 1 = circle
        const char* name;
    };

    std::vector<Collider> list;

   public:
    /**
     * @brief Add a rectangle to list
     *
     * @param rect Rectangle to add
     * @param name Unique name of rectangle
     * @return int index of added rectangle (i + 1)
     */
    int addRect(Rectangle rect, const char* name);

    /**
     * @brief Add a circle to list
     *
     * @param circle Circle to add
     * @param name Unique name of circle
     * @return int index of added circle (i + 1)
     */
    int addCircle(Circle circle, const char* name);

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
     * @brief Check if rectangle collides with any of the rectangles in the list
     *
     * @param rect rectangle to check collision with
     * @return int index of rectangle (i + 1)
     */
    int checkCollisionRect(Rectangle rect);

    /**
     * @brief Check if circle collides with any of the circles in the list
     *
     * @param circle circle to check collision with
     * @return int index of circle (i + 1)
     */
    int checkCollisionCircle(Circle circle);

    /**
     * @brief Check if any of the objects in the list collide with any of the objects in the other list
     *
     * @param otherList list to check collision with
     * @return int index of object (i + 1)
     */
    int checkCollisionList(CollisionList otherList);

    /**
     * @brief Check if rectangle collides with any of the rectangles in the list
     *
     * @param rect rectangle to check collision with
     * @param name name of rectangle
     * @return int index of rectangle (i + 1)
     */
    int checkCollisionNameRect(Rectangle rect, const char* name);

    /**
     * @brief Check if circle collides with any of the circles in the list
     *
     * @param circle circle to check collision with
     * @param name name of circle
     * @return int index of circle (i + 1)
     */
    int checkCollisionNameCircle(Circle circle, const char* name);

    /**
     * @brief Check if any of the objects in the list collide with any of the objects in the other list
     *
     * @param otherList list to check collision with
     * @param name name of object
     * @return int index of object (i + 1)
     */
    int checkCollisionNameList(CollisionList otherList, const char* name);
};

#endif  // COLLIDER_H