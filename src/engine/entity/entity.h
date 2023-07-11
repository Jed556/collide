#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>

#include "../collider/collider.h"
#include "../control/control.h"
#include "../math/math.h"

struct Entity {
    // list properties
    // CollisionList& list; // list the entity hitbox belongs to
    const char* name;  // unique name of entity
    int listIndex;     // index of entity in list (i + 1)

    // entity properties
    Vector2 size;          // size of entity
    Vector2 position;      // position of entity
    Vector2 prevPosition;  // previous position of entity
    Vector2 origin;        // anchor point of entity
    Color color;           // color of entity
    float speed;           // speed of entity

    /**
     * @brief Construct a new Entity object
     *
     * @param name name of entity
     * @param list list the entity hitbox belongs to
     * @param size size of entity
     * @param position position of entity
     * @param origin origin of entity
     * @param color color of entity
     * @param speed speed of entity
     */
    Entity(const char* name, CollisionList& list, Vector2 size, Vector2 position, Vector2 origin, Color color, float speed);

    /**
     * @brief Update entity position based on input
     *
     * @param dPad if only one key can be pressed at a time
     * @param scheme 0 for WASD, 1 for arrow keys, 2 for IJKL, 3 for numpad
     */
    void move(bool dPad = false, int scheme = 0);

    /**
     * @brief Move entity randomly
     *
     * @param mapSize size of map
     */
    void randomMove(Vector2 mapSize);

    /**
     * @brief Update entity collision list
     *
     * @param list list to update (entity name must be in list)
     * @return true if collider is updated
     */
    void updateCollider(CollisionList& list);

    /**
     * @brief Check if entity collides with object
     *
     * @param start start of map
     * @param end end of map
     * @return true if entity is out of bounds
     */
    bool outOfBounds(Vector2 start, Vector2 end);

    /**
     * @brief Check if entity collides with object
     *
     * @param object object to check collision with
     * @return true if entity collides with object
     */
    bool collidesWithRect(Rectangle object);

    /**
     * @brief Check if player collides with object
     *
     * @param object object to check collision with
     * @return int index of object in list collided (i + 1)
     */
    std::vector<int> collidesWithList(CollisionList& list);

    /**
     * @brief Draw player
     *
     */
    void draw();

    /**
     * @brief Get half size of player
     *
     * @return Vector2
     */
    Vector2 getHalfSize();

    /**
     * @brief Get the Rectangle of the player
     *
     * @return Rectangle
     */
    Rectangle getRect();
};

#endif  // ENTITY_H