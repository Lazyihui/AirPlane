#include <stdio.h>
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "PlaneEntity.h"
#include "BulletEntity.h"
#include "MonsterEntity.h"
#include "Context.h"
#include "common.h"


void ContextInit(Context *ctx){

        ctx->plane.color=RED;
        ctx->plane.pos.x=400;
        ctx->plane.pos.y=400;
        ctx->plane.radius=20;
        ctx->plane.speed=150;

}

void Draw_all(Context *ctx){

    Plane_Draw(ctx->plane);
}
int main() {
    InitWindow(800, 450, "cyh");

    Context ctx;
    ContextInit(&ctx);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        time_t current_time = time(NULL);





        Plane_Axis(&ctx.plane);
        Plane_Move(&ctx.plane,ctx.plane.moveAxis,dt);








        Draw_all(&ctx);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}