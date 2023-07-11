#include "collider.h"

int CollisionList::add(Rectangle rect, const char* name) {
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

int CollisionList::add(Circle circle, const char* name) {
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

void CollisionList::update(int index, Rectangle rect) {
    list[index - 1].rect = rect;
}

void CollisionList::update(int index, Circle circle) {
    list[index - 1].circle = circle;
}

void CollisionList::update(const char* name, Rectangle rect) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].name == name) {
            list[i].rect = rect;
            return;
        }
    }
}

void CollisionList::update(const char* name, Circle circle) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].name == name) {
            list[i].circle = circle;
            return;
        }
    }
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

std::vector<Collider> CollisionList::getList() {
    return list;
}

void CollisionList::draw(Color color, bool fill, int width) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].type == 0) {
            if (fill) {
                DrawRectangleRec(list[i].rect, color);
            } else {
                DrawRectangleLinesEx(list[i].rect, width, color);
            }
        } else {
            if (fill) {
                DrawCircle(list[i].circle.x, list[i].circle.y, list[i].circle.radius, color);
            } else {
                DrawCircleLines(list[i].circle.x, list[i].circle.y, list[i].circle.radius, color);
            }
        }
    }
}

std::vector<int> CollisionList::checkCollision(Rectangle rect) {
    std::vector<int> collided;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].type == 0) {
            if (CheckCollisionRecs(rect, list[i].rect)) {
                collided.push_back(i + 1);
            }
        } else {
            if (CheckCollisionCircleRec({list[i].circle.x, list[i].circle.y}, list[i].circle.radius, rect)) {
                collided.push_back(i + 1);
            }
        }
    }
    return collided;
}

std::vector<int> CollisionList::checkCollision(Circle circle) {
    std::vector<int> collided;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].type == 0) {
            if (CheckCollisionCircleRec({circle.x, circle.y}, circle.radius, list[i].rect)) {
                collided.push_back(i + 1);
            }
        } else {
            if (CheckCollisionCircles({circle.x, circle.y}, circle.radius, {list[i].circle.x, list[i].circle.y}, list[i].circle.radius)) {
                collided.push_back(i + 1);
            }
        }
    }
    return collided;
}

std::vector<int> CollisionList::checkCollision(CollisionList otherList) {
    std::vector<int> collided;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].type == 0) {
            if (!otherList.checkCollision(list[i].rect).empty()) {
                collided.push_back(i + 1);
            }
        } else {
            if (!otherList.checkCollision(list[i].circle).empty()) {
                collided.push_back(i + 1);
            }
        }
    }
    return collided;
}

std::vector<int> CollisionList::checkCollision(Rectangle rect, const char* name) {
    std::vector<int> collided;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].name == name) {
            if (list[i].type == 0) {
                if (CheckCollisionRecs(rect, list[i].rect)) {
                    collided.push_back(i + 1);
                }
            } else {
                if (CheckCollisionCircleRec({list[i].circle.x, list[i].circle.y}, list[i].circle.radius, rect)) {
                    collided.push_back(i + 1);
                }
            }
        }
    }
    return collided;
}

std::vector<int> CollisionList::checkCollision(Circle circle, const char* name) {
    std::vector<int> collided;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].name == name) {
            if (list[i].type == 0) {
                if (CheckCollisionCircleRec({circle.x, circle.y}, circle.radius, list[i].rect)) {
                    collided.push_back(i + 1);
                }
            } else {
                if (CheckCollisionCircles({circle.x, circle.y}, circle.radius, {list[i].circle.x, list[i].circle.y}, list[i].circle.radius)) {
                    collided.push_back(i + 1);
                }
            }
        }
    }
    return collided;
}

std::vector<int> CollisionList::checkCollision(CollisionList otherList, const char* name) {
    std::vector<int> collided;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].name == name) {
            if (list[i].type == 0) {
                if (!otherList.checkCollision(list[i].rect).empty()) {
                    collided.push_back(i + 1);
                }
            } else {
                if (!otherList.checkCollision(list[i].circle).empty()) {
                    collided.push_back(i + 1);
                }
            }
        }
    }
    return collided;
}