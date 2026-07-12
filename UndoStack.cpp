#include "UndoStack.h"

void UndoStack::addToUndoStack(Image undoData) {
    ImageFlipVertical(&undoData);
    undoStack_.push(undoData);
};

void UndoStack::addToRedoStack(Image redoData) {
    ImageFlipVertical(&redoData);
    redoStack_.push(redoData);
}

std::stack<Image> UndoStack::getUndoStack() {
    return undoStack_;
}

std::stack<Image> UndoStack::getRedoStack() {
    return redoStack_;
}

Image UndoStack::getAndPopUndoTop() {
    Image tempStackTop = undoStack_.top();
    undoStack_.pop();
    return tempStackTop;
}

Image UndoStack::getAndPopRedoTop() {
    Image tempStackTop = redoStack_.top(); 
    redoStack_.pop();
    return tempStackTop;
}

void UndoStack::clear() {
    redoStack_ = std::stack<Image>();
    undoStack_ = std::stack<Image>(); 
}

void UndoStack::clearUndoStack() {
    undoStack_ = std::stack<Image>();
}
void UndoStack::clearRedoStack() {
    redoStack_ = std::stack<Image>();
}

bool UndoStack::undoStackEmpty() {
    return undoStack_.empty();
}

bool UndoStack::redoStackEmpty() {
    return redoStack_.empty();
}