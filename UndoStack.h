#include <stack>
#include "raylib.h"
#pragma once

struct undoInfo {
    bool line;
    Vector2 prevMousePos;
    Vector2 currentPos;
    int brushSize;
};

class UndoStack {
    public:
        void addToUndoStack(Image);
        std::stack<Image> getStack();
        Image getAndPopTop();

    private:
        std::stack<Image> undoStack_;
};