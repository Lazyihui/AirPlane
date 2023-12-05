#ifndef BULLETCONTROLLER_H__
#define BULLETCONTROLLER_H__
#include "Context.h"
#include "common.h"
#include "BulletEntity.h"
#include "MonsterEntity.h"

void BulletController_Tick(Context *ctx,float dt) {

    if (ctx->input.isMouseDown) {
        ctx->bulletcount += 1;
        Bullet *bullet = &ctx->bullets[ctx->bulletcount - 1];
        bullet->pos = ctx->plane.pos;
        bullet->moveAxis = ctx->plane.faceDir;
        bullet->color = GRAY;
        bullet->pos = ctx->plane.pos;
        bullet->radius = 10;
        bullet->speed = 160;
        bullet->isActive = true;
    }

    for (int i = 0; i < ctx->bulletcount; i += 1) {
        Bullet *bullet = &ctx->bullets[i];
        // 移动
        Bullet_Move(bullet, dt); /////
        // 边界
        if (bullet->pos.x > 800 || bullet->pos.x < 0 || bullet->pos.y > 450 || bullet->pos.y < 0) {
            bullet->isActive = false;
        }

        // 击中敌人判断
        for (int j = 0; j < ctx->monstercount; j++) {
            Monster *monster = &ctx->monsterarr[j];
            if (monster->isAlive) {
                bool isbulletmonster = IsCirlceInsideCircle(bullet->radius, monster->radius, bullet->pos, monster->pos);
                if (isbulletmonster) {
                    monster->isAlive = false;
                    bullet->isActive = false;
                }
            }
        }
    }

    for (int i = ctx->bulletcount - 1; i >= 0; i--) {
        Bullet bullet = ctx->bullets[i];
        if (!bullet.isActive) {
            ctx->bullets[i] = ctx->bullets[ctx->bulletcount - 1];
            ctx->bullets[ctx->bulletcount - 1] = bullet;
            ctx->bulletcount -= 1;
        }
    }
}

#endif