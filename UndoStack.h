#include <stack>
#include "raylib.h"
#pragma once

class UndoStack {
    public:
        void addToUndoStack(Image);
        void addToRedoStack(Image); 
        void clear();
        void clearUndoStack();
        void clearRedoStack();
        bool undoStackEmpty();
        bool redoStackEmpty();
    
        std::stack<Image> getUndoStack();
        std::stack<Image> getRedoStack();
        Image getAndPopUndoTop();
        Image getAndPopRedoTop();
        

    private:
        std::stack<Image> undoStack_;
        std::stack<Image> redoStack_;
};