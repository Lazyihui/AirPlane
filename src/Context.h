#ifndef CONTEXT_H__
#define CONTEXT_H__

typedef struct Context
{
//////////////////////////////////飞机
    Plane plane;

//////////////////////////////////怪物
    Monster monster;
    Monster monsterarr[5];
    float monstercount;
//////////////////////////////////子弹
    Bullet bullet;


    Vector2 a;
    Vector2 pos;
    float speed;
    
}Context;

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
    Monster *monster = &ctx->monster;
    monster->color = YELLOW;
    monster->pos.x = 50;
    monster->pos.y = 50;
    monster->radius = 10;
    monster->speed = 120;
    monster->moveAxis.x = 1;
    monster->moveAxis.y = 0;
    ctx->monstercount=5;
}
#endif