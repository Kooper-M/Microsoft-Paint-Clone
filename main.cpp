#include "Paint.h"
#include "raylib.h"
#include <vector>

int main() {
    //Paint painter;
    //painter.print();
    InitWindow(800, 600, "Paint Program");
    SetTargetFPS(120);
    std::vector<Vector2> mousePositions;

    while(!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            mousePositions.push_back(GetMousePosition());
        }

        BeginDrawing();
        for (Vector2 pos : mousePositions) {
            DrawCircle(pos.x, pos.y, 10, RED);
        }

        ClearBackground(RAYWHITE);
        DrawText("Raylib test", 300, 280, 30, BLACK);
        EndDrawing();   
    }
    CloseWindow();

    return 0;
};