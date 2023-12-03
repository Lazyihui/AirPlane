#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "PlaneEntity.h"
#include "BulletEntity.h"
#include "MonsterEntity.h"
#include "Context.h"
#include "common.h"

void ContextInit(Context *ctx) {

    ctx->plane.color = RED;
    ctx->plane.pos.x = 400;
    ctx->plane.pos.y = 400;
    ctx->plane.radius = 20;
    ctx->plane.speed = 150;

    ////////////////////////////////////////////////////////Bullet

    ctx->bullet.color = GREEN;
    ctx->bullet.pos.x = 0;
    ctx->bullet.pos.y = 0;
    ctx->bullet.radius = 100;
    ctx->bullet.speed = 200;

    // f//////////////////////////////////////////////////////////Monster
    Monster *monster=&ctx->monster;
    monster->color = YELLOW;
    monster->pos.x = 50;
    monster->pos.y = 50;
    monster->radius = 30;
    monster->speed = 120;
    monster->moveAxis.x=1;
    monster->moveAxis.y=0;


}

void Draw_all(Context *ctx) {

    Plane_Draw(ctx->plane);
    Bullet bullet = ctx->bullet;
    // BUllet_Draw(&bullet);/
    Monster monster = ctx->monster;
    Monster_Draw(&monster);
}
int main() {
    InitWindow(800, 450, "cyh");
    SetTargetFPS(60);

    Context ctx;
    ContextInit(&ctx);

    int status = 0;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        time_t current_time = time(NULL);

        Plane_Axis(&ctx.plane);
        Plane_Move(&ctx.plane, ctx.plane.moveAxis, dt);

        Monster_InputByTarget(&ctx.monster,ctx.plane.pos);
        Monster_Move(&ctx.monster,ctx.monster.moveAxis,dt);


        Draw_all(&ctx);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}