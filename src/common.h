#ifndef COMMON_H__
#define COMMON_H__
#include "..\include\raylib.h"
#include "..\include\raymath.h"
/////////////////////////////////////////////////////[min,max)随机数

int get_rand(int min, int max) {
    return min + rand() % max;
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