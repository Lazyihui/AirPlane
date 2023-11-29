#ifndef BULLETENTITY_H__
#define BULLETENTITY_H__
#include "..\include\raylib.h"
#include "..\include\raymath.h"
typedef struct Bullet {
    Color color;
    float radius;
    float speed;
    Vector2 pos;
} Bullet;

#endif