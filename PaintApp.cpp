#include "PaintApp.h"
#include <iostream>

PaintApp::PaintApp() : canvas_(800,600), wasDrawing_(false) {}

PaintApp::~PaintApp() {
    canvas_.unload();
    CloseWindow();
}

void PaintApp::update() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        undoHelper.addToUndoStack(LoadImageFromTexture(canvas_.getTexture().texture));
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        BeginTextureMode(canvas_.getTexture());
        if (wasDrawing_) {
            DrawLineEx(prevMousePos_, currentMousePos_, brush_.getThickness()*2, brush_.getColor());
        }
        DrawCircleV(currentMousePos_, brush_.getThickness(), brush_.getColor());
        EndTextureMode();

        prevMousePos_ = currentMousePos_;
        wasDrawing_ = true;
    } else {
        wasDrawing_ = false;
    }
    
    if (IsKeyPressed(KEY_C)) {
        BeginTextureMode(canvas_.getTexture());
            ClearBackground(RAYWHITE);
        EndTextureMode();
    }

    if (IsKeyPressed(KEY_R)) {
        if (undoHelper.getStack().size() > 0) {
            BeginTextureMode(canvas_.getTexture());
                ClearBackground(RAYWHITE);
                Texture2D prevCanvas = LoadTextureFromImage(undoHelper.getAndPopTop());
                DrawTexture(prevCanvas,0,0,WHITE);
            EndTextureMode();
        }
    }
}

void PaintApp::run() {
    InitWindow(canvas_.getWidth(), canvas_.getHeight(), "KM Paint");
    SetTargetFPS(120);

    canvas_.init();

    while (!WindowShouldClose())
    {
        currentMousePos_ = GetMousePosition();
        update();
        BeginDrawing();
            ClearBackground(RAYWHITE);
            canvas_.drawCanvas();
            gui_.drawGui(brush_, canvas_.getTexture());
        EndDrawing();
    }
}