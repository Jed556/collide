#include "collider.h"

int CollisionList::addRect(Rectangle rect, const char* name) {
    // check if name is unique
    for (int i = 0; i < list.size(); i++) {
        if (list[i].name == name) {
            std::cerr << "Error: name is not unique" << std::endl;
            return 0;
        }
    }

    Collider collider;
    collider.rect = rect;
    collider.type = 0;
    collider.name = name;
    list.push_back(collider);

    return list.size();
}

int CollisionList::addCircle(Circle circle, const char* name) {
    // check if name is unique
    for (int i = 0; i < list.size(); i++) {
        if (list[i].name == name) {
            std::cerr << "Error: name is not unique" << std::endl;
            return 0;
        }
    }

    Collider collider;
    collider.circle = circle;
    collider.type = 1;
    collider.name = name;
    list.push_back(collider);

    return list.size();
}

Rectangle CollisionList::getRect(int index) {
    return list[index - 1].rect;
}

Circle CollisionList::getCircle(int index) {
    return list[index - 1].circle;
}

const char* CollisionList::getName(int index) {
    return list[index - 1].name;
}

int CollisionList::checkCollisionRect(Rectangle rect) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].type == 0) {
            if (CheckCollisionRecs(rect, list[i].rect)) {
                return i + 1;
            }
        } else {
            if (CheckCollisionCircleRec({list[i].circle.x, list[i].circle.y}, list[i].circle.radius, rect)) {
                return i + 1;
            }
        }
    }
    return 0;
}

int CollisionList::checkCollisionCircle(Circle circle) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].type == 0) {
            if (CheckCollisionCircleRec({circle.x, circle.y}, circle.radius, list[i].rect)) {
                return i + 1;
            }
        } else {
            if (CheckCollisionCircles({circle.x, circle.y}, circle.radius, {list[i].circle.x, list[i].circle.y}, list[i].circle.radius)) {
                return i + 1;
            }
        }
    }
    return 0;
}

int CollisionList::checkCollisionList(CollisionList otherList) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].type == 0) {
            if (otherList.checkCollisionRect(list[i].rect)) {
                return i + 1;
            }
        } else {
            if (otherList.checkCollisionCircle(list[i].circle)) {
                return i + 1;
            }
        }
    }
    return 0;
}

int CollisionList::checkCollisionNameRect(Rectangle rect, const char* name) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].name == name) {
            if (list[i].type == 0) {
                if (CheckCollisionRecs(rect, list[i].rect)) {
                    return i + 1;
                }
            } else {
                if (CheckCollisionCircleRec({list[i].circle.x, list[i].circle.y}, list[i].circle.radius, rect)) {
                    return i + 1;
                }
            }
        }
    }
    return 0;
}

int CollisionList::checkCollisionNameCircle(Circle circle, const char* name) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].name == name) {
            if (list[i].type == 0) {
                if (CheckCollisionCircleRec({circle.x, circle.y}, circle.radius, list[i].rect)) {
                    return i + 1;
                }
            } else {
                if (CheckCollisionCircles({circle.x, circle.y}, circle.radius, {list[i].circle.x, list[i].circle.y}, list[i].circle.radius)) {
                    return i + 1;
                }
            }
        }
    }
    return 0;
}

int CollisionList::checkCollisionNameList(CollisionList otherList, const char* name) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].name == name) {
            if (list[i].type == 0) {
                if (otherList.checkCollisionRect(list[i].rect)) {
                    return i + 1;
                }
            } else {
                if (otherList.checkCollisionCircle(list[i].circle)) {
                    return i + 1;
                }
            }
        }
    }
    return 0;
}