#ifndef PLANEENTITY_H__
#define PLANEENTITY_H__
#include "..\include\raylib.h"
#include "..\include\raymath.h"

typedef struct Plane {
    Color color;
    float speed;
    Vector2 pos;
    float radius;
    Vector2 faceDir;
    int hp;
} Plane;

////////////////////////////////////////////////////////移动

void Plane_Move(Plane *plane, Vector2 moveAxis, float dt) {
    Vector2 *posptr = &plane->pos;
    Vector2 offset = Vector2Normalize(moveAxis);
    offset = Vector2Scale(offset, plane->speed * dt);
    *posptr = Vector2Add(*posptr, offset);
    //////////////////////////////////////////////////////////////////////边界/////////////有问题
    if (posptr->x >= 800) {
        posptr->x = 800;
    }
    if (posptr->x <= 0) {
        posptr->x = 0;
    }
    if (posptr->y >= 450) {
        posptr->y = 450;
    }
    if (posptr->y <= 0) {
        posptr->y = 0;
    }
}

void Plane_rotate(Plane *plane,Vector2 moveAxis) {
    if (moveAxis.x == 0 && moveAxis.y == 0) {////不变
        return;    
    } 
    plane->faceDir=moveAxis;    
}


void Plane_Draw(Plane plane) {
    // 机身
    Vector2 pos = plane.pos;
    DrawCircle(pos.x, pos.y, plane.radius, plane.color);

    // 枪口
    Vector2 muzzleEndPos = Vector2Scale(plane.faceDir, 50);
    muzzleEndPos = Vector2Add(pos, muzzleEndPos);
    DrawLineV(pos, muzzleEndPos, GREEN);
}

void plane_DrawUI(Plane plane) {
    const char *b = TextFormat("%d", plane.hp);
    DrawText(b, 10, 10, 30, RED);
}

#endif