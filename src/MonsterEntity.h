#ifndef MONSTERENTITY_H__
#define MONSTERENTITY_H__
#include "..\include\raylib.h"
#include "..\include\raymath.h"

typedef struct Monster {
    Color color;
    float radius;
    float speed;
    Vector2 pos;
    Vector2 moveAxis;
} Monster;

void Monster_inputzy(Monster *monster) {

    if (monster->pos.x > 700) {
        monster->moveAxis.x = -1;
    } else if (monster->pos.x < 50) {
        monster->moveAxis.x = 1;
    }
}

void Monster_InputByTarget(Monster *monster , Vector2 targetpos){
    monster->moveAxis=Vector2Subtract(targetpos,monster->pos);
    
}
////z//////////////////////////根据输入方向 改变坐标
void Monster_Move(Monster *monster, Vector2 moveAxis, float dt) {

    Vector2 *posptr = &monster->pos;
    Vector2 offset = Vector2Normalize(moveAxis);
    offset = Vector2Scale(offset, monster->speed * dt);
    *posptr = Vector2Add(*posptr, offset);
    if (posptr->x >= 800) {
        posptr->x = 800;
    }
    if (posptr->x <= 0) {
        posptr->x = 0;
    }
    if (posptr->y >= 450) {
        posptr->y = 450;
    }
    if (posptr->y <= 0) {
        posptr->y = 0;
    }
}

void Monster_Draw(Monster *monster) {
    DrawCircle(monster->pos.x, monster->pos.y, monster->radius, monster->color);
}
#endif