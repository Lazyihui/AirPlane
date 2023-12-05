#ifndef MONSTERCONTROLLER_H__
#define MONSTERCONTROLLER_H__
#include "Context.h"
#include "MonsterEntity.h"
#include "common.h"

void MonsterController_Tick(Context *ctx, float dt) {
    // All Monster Logic
    for (int i = 0; i < ctx->monstercount; i++) {
        Monster *monster = &ctx->monsterarr[i];

        if (monster->isAlive) {
            // Monster Input
            Monster_InputByTarget(monster, ctx->plane.pos);

            // Monster Move
            Monster_Move(monster, monster->moveAxis, dt);

            // Monster Hit
            bool iscircle = IsCirlceInsideCircle(monster->radius, ctx->plane.radius, monster->pos, ctx->plane.pos);
            if (iscircle) {
                monster->isAlive = false;
                ctx->plane.hp -= 10;
            }
        }
    }

    // Monster needs to Destroy
    for (int i = ctx->monstercount - 1; i >= 0; i--) {
        Monster monster = ctx->monsterarr[i];
        if (!monster.isAlive) {
            ctx->monsterarr[i] = ctx->monsterarr[ctx->monstercount - 1];
            ctx->monsterarr[ctx->monstercount - 1] = monster;
            ctx->monstercount -= 1;
        }
    }
}

#endif