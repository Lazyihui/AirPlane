#ifndef BULLETENTITY_H__
#define BULLETENTITY_H__
#include "..\include\raylib.h"
#include "..\include\raymath.h"
typedef struct Bullet {
    Color color;
    float radius;
    float speed;
    Vector2 pos;
    Vector2 movepos;
} Bullet;


void Bullet_Move(Bullet *bullet,float dt){
    Vector2 loction = Vector2Normalize(bullet->movepos);
    loction = Vector2Scale(loction,bullet->speed*dt);
    bullet->pos=Vector2Add(bullet->pos,loction);
}

void BUllet_Draw(Bullet *bullet){
    DrawCircle(bullet->pos.x,bullet->pos.y,bullet->radius,bullet->color);
}
#endif