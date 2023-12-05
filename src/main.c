#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "common.h"
#include "PlaneEntity.h"
#include "BulletEntity.h"
#include "MonsterEntity.h"
#include "Context.h"
#include "BulletController.h"
#include "MonsterController.h"

void Draw_all(Context *ctx) {

    Plane_Draw(ctx->plane);
    plane_DrawUI(ctx->plane);

    for (int i = 0; i < ctx->monstercount; i++) {
        Monster *monster = &ctx->monsterarr[i];
        Monster_Draw(monster);
    }
    for (int i = 0; i < ctx->bulletcount; i++) {
        // printf("%d", ctx->bulletcount);

        Bullet *bullets = &ctx->bullets[i];
        BUllet_Draw(bullets);
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

        
        Input_Process(&ctx.input,ctx.plane.pos);


        Plane_Move(&ctx.plane, ctx.input.moveAxis, dt);
        Plane_rotate(&ctx.plane, ctx.input.mouseFaceDir);
        
        MonsterController_Tick(&ctx,dt);
        BulletController_Tick(&ctx,dt);

        Draw_all(&ctx);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}