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
    ctx->monster.color = YELLOW;
    ctx->monster.pos.x = 50;
    ctx->monster.pos.y = 50;
    ctx->monster.radius = 30;
    ctx->monster.speed = 120;

    ctx->a.x = 0;
    ctx->a.y = 0;
    ctx->speed = 120;
    ctx->pos.x = 50;
    ctx->pos.y = 50;
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

    Context *ctx;
    ContextInit(ctx);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        time_t current_time = time(NULL);

        Plane_Axis(&ctx->plane);
        Plane_Move(&ctx->plane, ctx->plane.moveAxis, dt);

        // for (int i = 0; i < 800; i++) {
        //     ctx.a.x = ctx.a.x + ctx.a.x * dt;
        //     DrawCircle(ctx.a.x, ctx.a.y, 30, GRAY);
        //     if (ctx.a.x > 750) {
        //         for (int i = 0; i < 800; i++) {
        //             ctx.a.x = ctx.a.x - ctx.a.x * dt;
        //             DrawCircle(ctx.a.x, ctx.a.y, 30, RED);
        //         }
        //     }
        // }
                DrawCircle(ctx->pos.x, ctx->pos.y, 30, GREEN);

        if (IsKeyDown(KEY_SPACE)) {

            for (int i = 0; i < 800; i++) {
                Vector2 a = Vector2Normalize(ctx->a);
                a.x++;
                a = Vector2Scale(a, ctx->speed * dt);
                ctx->pos = Vector2Add(ctx->pos, ctx->a);

                DrawCircle(ctx->pos.x, ctx->pos.y, 30, GRAY);
                printf("a");
                if (ctx->a.x > 750) {

                    for (int i = 0; i < 800; i++) {
                        Vector2 a = Vector2Normalize(ctx->a);
                        a.x--;
                        a = Vector2Scale(a, ctx->speed * dt);
                        ctx->pos = Vector2Add(ctx->pos, ctx->a);

                        DrawCircle(ctx->pos.x, ctx->pos.y, 30, RED);
                    printf("B");
                    }
                }
            }
        }

        // Draw_all(&ctx);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}