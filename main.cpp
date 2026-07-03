#include "Paint.h"
#include "raylib.h"
#include <vector>
#define RAYGUI_IMPLEMENTATION
#include "include/raygui/src/raygui.h"
//#include "DrawScope.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    SetTargetFPS(120);


    InitWindow(screenWidth, screenHeight, "Paint Program");
    RenderTexture2D canvas = LoadRenderTexture(screenWidth, screenHeight);

    BeginTextureMode(canvas);
        ClearBackground(RAYWHITE);
    EndTextureMode();

    Color brushColor = RED;
    float brushThickness = 5;
    Vector2 previousMousePos{};
    bool wasDrawing = false;

    while(!WindowShouldClose()) {
        Vector2 currentMousePos = GetMousePosition();
        
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            BeginTextureMode(canvas);
            if (wasDrawing) {
                DrawLineEx(previousMousePos, currentMousePos, brushThickness*2, brushColor);
            }
            DrawCircleV(currentMousePos, brushThickness, brushColor);

            EndTextureMode();
            previousMousePos = currentMousePos;
            wasDrawing = true;
        } else {
            wasDrawing = false;
        }
        
        if (IsKeyPressed(KEY_C)) {
            BeginTextureMode(canvas);
                ClearBackground(RAYWHITE);
            EndTextureMode();
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawTextureRec(
                canvas.texture,
                Rectangle{0, 0, (float)canvas.texture.width, -(float)canvas.texture.height},
                Vector2{0,0},
                RAYWHITE);

            DrawText("Hold L-click to draw", 20, 20, 10, RED);
            DrawText("Press C to clear", 20, 30, 10, RED);

            if (GuiButton(Rectangle{600, 50, 100, 30}, "Blue")) {
                brushColor = BLUE;
            }
            if (GuiButton(Rectangle{600, 80, 100, 30}, "Red")) {
                brushColor = RED;
            }
            GuiSliderBar(Rectangle{600, 150, 100, 30}, "Brush Size", NULL, &brushThickness, 1, 10);
        EndDrawing();
    }
    CloseWindow();

    return 0;
};