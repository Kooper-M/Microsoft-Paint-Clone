#pragma once
#include "raylib.h"
#include "Gui.h"
#include "Canvas.h"
#include "Brush.h"
#include "UndoStack.h"
class PaintApp {
    public:
        PaintApp();
        ~PaintApp();
        void run();
        void update();
    private:
        Gui gui_;
        Canvas canvas_;
        UndoStack undoHelper;
        Brush brush_;    
        bool wasDrawing_; 
        Vector2 currentMousePos_;
        Vector2 prevMousePos_;
};