#ifndef CONTEXT_H__
#define CONTEXT_H__
#include "common.h"
typedef struct Context {
    //////////////////////////////////飞机
    Plane plane;

    //////////////////////////////////怪物
    Monster monsterarr[5];
    int monstercount;
    //////////////////////////////////子弹
    Bullet bullet;

    Vector2 a;
    Vector2 pos;
    float speed;

} Context;

void ContextInit(Context *ctx) {

    ctx->plane.color = RED;
    ctx->plane.pos.x = 400;
    ctx->plane.pos.y = 200;
    ctx->plane.radius = 20;
    ctx->plane.speed = 150;
    ctx->plane.hp=100;
    ctx->plane.faceDir.x=0;
    ctx->plane.faceDir.y=-1;

    ////////////////////////////////////////////////////////Bullet

    Bullet *bullet = &ctx->bullet;
    bullet->color=GRAY;
    bullet->moveAxis.x=0;
    bullet->moveAxis.y=0;
    bullet->pos=ctx->plane.pos;
    bullet->radius=10;
    bullet->speed=160;
    bullet->isActive=false;
    // f//////////////////////////////////////////////////////////Monster
    ctx->monstercount = 5;
    for (int i = 0; i < ctx->monstercount; i++) {
        // int rdx = get_rand(0, 50);
        // int rdy = get_rand(0, 450);
        Monster monster=(Monster){0};
        monster.pos = Get_randVector();
        monster.color = YELLOW;
        monster.moveAxis.x = 1;
        monster.moveAxis.y = 0;
        monster.radius = 10;
        monster.speed = 120;
        monster.isAlive = true;
        ctx->monsterarr[i] = monster;
    }
}
#endif