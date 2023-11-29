#ifndef PLANEENTITY_H__
#define PLANEENTITY_H__
#include "..\include\raylib.h"
#include "..\include\raymath.h"

typedef struct Plane {
    Color color;
    float speed;
    Vector2 pos;
    float radius;
    Vector2 moveAxis;
} Plane;


void Plane_Draw(Plane plane){
        DrawCircle(plane.pos.x,plane.pos.y,plane.radius,plane.color);

}

////////////////////////////////////////////////////////移动
void Plane_Axis(Plane *Plane) {
    Plane->moveAxis.x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    Plane->moveAxis.y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
}

void Plane_Move(Plane *plane , Vector2 moveAxis,float dt){
            Vector2 loction = Vector2Normalize(moveAxis);
            loction = Vector2Scale(loction,plane->speed*dt);
            plane->pos= Vector2Add(plane->pos,loction);
//////////////////////////////////////////////////////////////////////边界/////////////有问题
            if(plane->pos.x>=800 ){
                plane->speed=0; 
                if(IsKeyDown(KEY_A)){
                    plane->speed=150;
                }
            }
            if(plane->pos.x<=0 ){
                plane->speed=0; 
                if(IsKeyDown(KEY_D)){
                    plane->speed=150;
                }
            }if(plane->pos.y>=450 ){
                plane->speed=0; 
                if(IsKeyDown(KEY_W)){
                    plane->speed=150;
                }
            }if(plane->pos.y<=0 ){
                plane->speed=0; 
                if(IsKeyDown(KEY_S)){
                    plane->speed=150;
                }
            }


}

#endif