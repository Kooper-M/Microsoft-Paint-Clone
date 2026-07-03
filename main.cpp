#include "Paint.h"
#include "raylib.h"
#include <vector>
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
    

    while(!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            BeginTextureMode(canvas);
                DrawCircleV(GetMousePosition(), 10, RED);
            EndTextureMode();
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
        EndDrawing();
    }
    CloseWindow();

    return 0;
};