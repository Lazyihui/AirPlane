#ifndef CONTEXT_H__
#define CONTEXT_H__
#include "common.h"
#include "InputEntity.h"
#include "BulletEntity.h"
#include "PlaneEntity.h"
#include "MonsterEntity.h"
typedef struct Context {

    InputEntity input;

    //////////////////////////////////飞机
    Plane plane;

    //////////////////////////////////怪物
    Monster monsterarr[5];
    int monstercount;
    //////////////////////////////////子弹
    int bulletcount;
    Bullet bullets[1000];

} Context;

void ContextInit(Context *ctx) {

    ctx->input = (InputEntity){0};

    ctx->plane.color = RED;
    ctx->plane.pos.x = 400;
    ctx->plane.pos.y = 200;
    ctx->plane.radius = 20;
    ctx->plane.speed = 150;
    ctx->plane.hp = 100;
    ctx->plane.faceDir.x = 0;
    ctx->plane.faceDir.y = -1;

    ////////////////////////////////////////////////////////Bullet

    // bullet->color = GRAY;
    // bullet->moveAxis.x = 0;
    // bullet->moveAxis.y = 0;
    // bullet->pos = ctx->plane.pos;
    // bullet->radius = 10;
    // bullet->speed = 160;
    // bullet->isActive = false;

    // f//////////////////////////////////////////////////////////Monster
    ctx->monstercount = 5;
    for (int i = 0; i < ctx->monstercount; i++) {
        // int rdx = get_rand(0, 50);
        // int rdy = get_rand(0, 450);

        Monster monster = (Monster){0};
        monster.pos = Get_randVector();
        monster.color = YELLOW;
        monster.moveAxis.x = 1;
        monster.moveAxis.y = 0;
        monster.radius = 10;
        monster.speed = 50;
        monster.isAlive = true;
        ctx->monsterarr[i] = monster;
    }
}
#endif