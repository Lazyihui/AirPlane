#ifndef MONSTERENTITY_H__
#define MONSTERENTITY_H__
#include "..\include\raylib.h"
#include "..\include\raymath.h"

typedef struct Monster {
    Color color;
    float radius;
    float speed;
    Vector2 pos;
}Monster;

void Monster_Draw(Monster monster){

}

#endif