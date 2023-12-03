#ifndef COMMON_H__
#define COMMON_H__
#include "..\include\raylib.h"
#include "..\include\raymath.h"
#include "time.h"
#include "stdlib.h"
/////////////////////////////////////////////////////[min,max)随机数

int get_rand(int min, int max) {
    return min + rand() % max;
}

Vector2 Get_randVector() {
    int rdSide = get_rand(0, 4);
    const int LEFT = 0;
    const int RIGHT = 1;
    const int TOP = 2;
    const int BOTTOM = 3;

    Vector2 result = (Vector2){0};

    if (rdSide == LEFT) {
        // Left
        result.x = get_rand(0, 50);
        result.y = get_rand(0, 450);
    } else if (rdSide == RIGHT) {
        result.x = get_rand(750, 800);
        result.y = get_rand(0, 450);
    } else if (rdSide == TOP) {
        result.x = get_rand(0, 800);
        result.y = get_rand(0, 50);
    } else if (rdSide == BOTTOM) {
        result.x = get_rand(0, 50);
        result.y = get_rand(400, 450);
    }

    return result;
}
////////////////////////////////////////////////////两个圆的检测
bool IsCirlceInsideCircle(float hookr, float rockr, Vector2 hooky, Vector2 rocky) {
    Vector2 diff = Vector2Subtract(hooky, rocky);
    float lengthsqr = Vector2LengthSqr(diff);
    if (lengthsqr >= (hookr + rockr) * (hookr + rockr)) {
        return false;
    } else {
        return true;
    }
}

#endif