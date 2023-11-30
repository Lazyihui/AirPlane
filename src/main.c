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

    Vector2 loction;
    Vector2 pos;
    float speed = 120;
    loction.x = 0;
    loction.y = 0;
    pos.x = 50;
    pos.y = 50;
    float dt = GetFrameTime();
    int stute = 0;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        time_t current_time = time(NULL);

        Plane_Axis(&ctx.plane);
        Plane_Move(&ctx.plane, ctx.plane.moveAxis, dt);
        if (stute == 0) {
            if (IsKeyDown(KEY_SPACE)) {
                for (int i = 0; i < 700; i++) {
                    printf("a");
                    loction.x += dt;
                    Vector2 dir = Vector2Normalize(loction);
                    dir = Vector2Scale(dir, speed * dt);
                    pos = Vector2Add(pos, dir);
                }

                if (loction.x > 700) {
                    stute == 1;
                    printf("b");
                    loction.x -= dt;
                    Vector2 dir = Vector2Normalize(loction);
                    dir = Vector2Scale(dir, speed * dt);
                    pos = Vector2Add(pos, dir);
                }
            }
            DrawCircle(pos.x, pos.y, 30, GREEN);
        } else if (stute == 1) {
            DrawCircle(pos.x, pos.y, 30, RED);
        }
        // Draw_all(&ctx);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}