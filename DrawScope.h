#pragma once
#include "raylib.h"

class DrawScope {
    public:
        DrawScope() {
            BeginDrawing();
        }
        ~DrawScope() {
            EndDrawing();
        }
};