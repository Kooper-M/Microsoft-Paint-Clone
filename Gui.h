#pragma once
#include <memory>
#include <raylib.h>
#include "Brush.h"
#include <array>
#include <string>
class Gui {
    public:
        void writeInstructions();
        void drawGui(Brush&, RenderTexture2D&);
    private:
        int textY_ = 20;
        const int textX_ = 20;
        const int lineSpacing_ = 10;
        const int fontSize_ = 10;
        const Color guiColor_ = RED;
        const std::array<std::string, 5> instructions_{
            "Hold L-click to draw",
            "Press R to Undo",
            "Press Y to Redo",
            "Press C to clear",
            "Press E to toggle eraser",
        };
};