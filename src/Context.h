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
    ctx->plane.pos.y = 400;
    ctx->plane.radius = 20;
    ctx->plane.speed = 150;

    ////////////////////////////////////////////////////////Bullet

    // ctx->bullet.color = GREEN;
    // ctx->bullet.pos.x = 0;
    // ctx->bullet.pos.y = 0;
    // ctx->bullet.radius = 100;
    // ctx->bullet.speed = 200;

    // f//////////////////////////////////////////////////////////Monster
    ctx->monstercount = 5;
    for (int i = 0; i < ctx->monstercount; i++) {
        int rdx = get_rand(0, 50);
        int rdy = get_rand(0, 450);
        Monster monster=(Monster){0};
        monster.pos.x = rdx;
        monster.pos.y = rdy;
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