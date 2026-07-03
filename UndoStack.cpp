#include "UndoStack.h"

void UndoStack::addToUndoStack(Image undoData) {
    ImageFlipVertical(&undoData);
    undoStack_.push(undoData);
};

std::stack<Image> UndoStack::getStack() {
    return undoStack_;
}

Image UndoStack::getAndPopTop() {
    Image tempStackTop = undoStack_.top();
    undoStack_.pop();
    return tempStackTop;
}