#include "PaintApp.h"
#include <iostream>

PaintApp::PaintApp() : canvas_(800,600), wasDrawing_(false), brush_(Brush(RED, 5.0)) {}

PaintApp::~PaintApp() {
    canvas_.unload();
    CloseWindow();
}

void PaintApp::update() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        undoHelper.addToUndoStack(LoadImageFromTexture(canvas_.getTexture()));
        undoHelper.clearRedoStack();
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        BeginTextureMode(canvas_.get2DTexture());
        if (wasDrawing_) {
            DrawLineEx(prevMousePos_, currentMousePos_, brush_.thickness*2, brush_.color);
        }
        DrawCircleV(currentMousePos_, brush_.thickness, brush_.color);
        EndTextureMode();

        prevMousePos_ = currentMousePos_;
        wasDrawing_ = true;
    } else {
        wasDrawing_ = false;
    }
    
    if (IsKeyPressed(KEY_C)) {
        BeginTextureMode(canvas_.get2DTexture());
            ClearBackground(RAYWHITE);
            undoHelper.clear();
        EndTextureMode();
    }

    if (IsKeyPressed(KEY_R)) {
        if (!undoHelper.undoStackEmpty()) {
            undoHelper.addToRedoStack(LoadImageFromTexture(canvas_.getTexture()));
            BeginTextureMode(canvas_.get2DTexture());
                ClearBackground(RAYWHITE);
                Texture2D prevCanvas = LoadTextureFromImage(undoHelper.getAndPopUndoTop());
                DrawTexture(prevCanvas,0,0,WHITE);
            EndTextureMode();
        }
    }

    if (IsKeyPressed(KEY_E)) {
        if (!brush_.isEraser) {
            brush_.switchToEraser();
        } else {
            brush_.switchToBrush();
        }
    }

    if (IsKeyPressed(KEY_Y)) {

        if (!undoHelper.redoStackEmpty()) {
            undoHelper.addToUndoStack(LoadImageFromTexture(canvas_.getTexture()));
            BeginTextureMode(canvas_.get2DTexture());
                ClearBackground(RAYWHITE);
                Texture2D prevCanvas = LoadTextureFromImage(undoHelper.getAndPopRedoTop());
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
            gui_.drawGui(brush_, canvas_.get2DTexture());
        EndDrawing();
    }
}