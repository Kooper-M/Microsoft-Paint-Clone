#include "Paint.h"
#include "raylib.h"
#include <vector>
#include <stack>
#define RAYGUI_IMPLEMENTATION
#include "include/raygui/src/raygui.h"
#include <tuple>
#include "UndoStack.h"
#include "Gui.h"
//#include "DrawScope.h"
//g++ -std=c++17 main.cpp Paint.cpp Gui.cpp UndoStack.cpp -o main.exe -lraylib -lopengl32 -lgdi32 -lwinmm && ./main.exe
int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    SetTargetFPS(120);


    InitWindow(screenWidth, screenHeight, "Paint Program");
    RenderTexture2D canvas = LoadRenderTexture(screenWidth, screenHeight);

    BeginTextureMode(canvas);
        ClearBackground(RAYWHITE);
    EndTextureMode();

    Gui gui;
    Color brushColor = RED;
    float brushThickness = 5;
    Vector2 previousMousePos{};
    bool wasDrawing = false;
    UndoStack undoHelper;

    while(!WindowShouldClose()) {
        Vector2 currentMousePos = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            undoHelper.addToUndoStack(LoadImageFromTexture(canvas.texture));
        }
        
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

        if (IsKeyPressed(KEY_R)) {
            if (undoHelper.getStack().size() > 0) {
                BeginTextureMode(canvas);
                    ClearBackground(RAYWHITE);
                    Texture2D prevCanvas = LoadTextureFromImage(undoHelper.getAndPopTop());
                    DrawTexture(prevCanvas,0,0,WHITE);
                EndTextureMode();
            }
        }
        
        gui.drawGui(brushColor, canvas, brushThickness);
    }
    CloseWindow();


    return 0;
};