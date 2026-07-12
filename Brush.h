#pragma once
#include "raylib.h"
struct Brush {
    Color color;
    Color prevColor;
    bool isEraser;
    float thickness;
    Brush(Color colorInit, float thicknessInit) : color(colorInit), prevColor(colorInit), isEraser(false), thickness(thicknessInit) {};

    void switchToEraser() {
        isEraser = true;
        thickness += 1;
        prevColor = color;
        color = RAYWHITE;
    }

    void switchToBrush() {
        isEraser = false;
        thickness -= 1;
        if (thickness < 1) {
            thickness = 1;
        }
        color = prevColor;  
    }
};
