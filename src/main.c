#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "PlaneEntity.h"
#include "BulletEntity.h"
#include "MonsterEntity.h"
#include "Context.h"
#include "common.h"



void Draw_all(Context *ctx) {

    Plane_Draw(ctx->plane);


    for (int i = 0; i <= ctx->monstercount; i++) {
        Monster *monster = &ctx->monsterarr[i];
        Monster_Draw(monster);
    }
    // for (int i = 0; i <= 5; i++) {
    //     Monster_Draw(&ctx->monsterarr[i]);
    // }
}

int main() {
    InitWindow(800, 450, "cyh");
    SetTargetFPS(60);

    Context ctx = {0};
    ContextInit(&ctx);

    for (int i = 0; i < ctx.monstercount; i++) {
        int rdx = get_rand(0, 50);
        int rdy = get_rand(0, 450);
        Monster monster;
        monster.pos.x = rdx;
        monster.pos.y = rdy;
        monster.color = YELLOW;
        monster.moveAxis.x = 1;
        monster.moveAxis.y = 0;
        monster.radius = 10;
        monster.speed = 120;
        ctx.monsterarr[i] = monster;
    }

    int status = 0;
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);

        Plane_Axis(&ctx.plane);
        Plane_Move(&ctx.plane, ctx.plane.moveAxis, dt);


        if (status == 0) {

            for (int i = 0; i < ctx.monstercount; i++) {
                Monster_InputByTarget(&ctx.monsterarr[i], ctx.plane.pos);
                Monster_Move(&ctx.monsterarr[i], ctx.monsterarr->moveAxis, dt);
            }
        } else if (status == 1) {



        }

        for (int i = 0; i < ctx.monstercount; i++) {
            Monster *tmp = &ctx.monsterarr[i];
            bool iscircle = IsCirlceInsideCircle(tmp->radius, ctx.plane.radius, tmp->pos, ctx.plane.pos);
            if (iscircle) {
                status = 1;
            }
        }

        Draw_all(&ctx);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}