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
    plane_DrawUI(ctx->plane);

    for (int i = 0; i < ctx->monstercount; i++) {
        Monster *monster = &ctx->monsterarr[i];
        Monster_Draw(monster);
    }
    if (ctx->bullet.isActive) {
        BUllet_Draw(&ctx->bullet);
    }
}

int main() {
    InitWindow(800, 450, "cyh");
    SetTargetFPS(60);

    Context ctx = {0};
    ContextInit(&ctx);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);

        Plane_Axis(&ctx.plane);
        Plane_Move(&ctx.plane, ctx.plane.moveAxis, dt);
        Plane_rotate(&ctx.plane);
        // All Monster Logic
        for (int i = 0; i < ctx.monstercount; i++) {
            Monster *monster = &ctx.monsterarr[i];

            if (monster->isAlive) {
                // Monster Input
                Monster_InputByTarget(monster, ctx.plane.pos);

                // Monster Move
                Monster_Move(monster, monster->moveAxis, dt);

                // Monster Hit
                bool iscircle = IsCirlceInsideCircle(monster->radius, ctx.plane.radius, monster->pos, ctx.plane.pos);
                if (iscircle) {
                    monster->isAlive = false;
                    ctx.plane.hp -= 10;
                }
            }
        }

        // Monster needs to Destroy
        for (int i = ctx.monstercount - 1; i >= 0; i--) {
            Monster monster = ctx.monsterarr[i];
            if (!monster.isAlive) {
                ctx.monsterarr[i] = ctx.monsterarr[ctx.monstercount - 1];
                ctx.monsterarr[ctx.monstercount - 1] = monster;
                ctx.monstercount -= 1;
            }
        }

        Bullet *bullet = &ctx.bullet;
        if (bullet->isActive) {
            Bullet_Move(&ctx.bullet, dt);
        }

        if (IsKeyDown(KEY_SPACE)) {
            bullet->isActive = true;
            bullet->pos = ctx.plane.pos;
            bullet->moveAxis = ctx.plane.faceDir;
        }

        Draw_all(&ctx);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}