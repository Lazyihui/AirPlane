#ifndef BULLETENTITY_H__
#define BULLETENTITY_H__
#include "..\include\raylib.h"
#include "..\include\raymath.h"
typedef struct Bullet {
    Color color;
    float radius;
    float speed;
    Vector2 pos;
    Vector2 moveAxis;
    bool isActive;
} Bullet;

// void Bullet_InputBytarget(Bullet *bullet , Plane *plane){
//     bullet->moveAxis= plane->moveAxis;
// }

// void Bullet_rotate(Bullet *bullet,Plane *plane) {
//     if (bullet->moveAxis.x == 0 && bullet->moveAxis.y == 0) {////不变
//         return;    
//     } 
//     bullet->moveAxis= plane->moveAxis;
// }


void  Bullet_Move(Bullet *bullet,float dt){
    Vector2 offset = Vector2Normalize(bullet->moveAxis);
    offset = Vector2Scale(offset,bullet->speed*dt);
    bullet->pos=Vector2Add(bullet->pos,offset);
}




void BUllet_Draw(Bullet *bullet){
    DrawCircle(bullet->pos.x,bullet->pos.y,bullet->radius,bullet->color);
}


#endif