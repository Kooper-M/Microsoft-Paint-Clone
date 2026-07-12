#include "Gui.h"
#include "raylib.h"
#include "include/raygui/src/raygui.h"
#include <memory>

void Gui::drawGui(Brush& brush, RenderTexture2D& canvas) {
    for (int i = 0; i < instructions_.size(); ++i) {
        DrawText(instructions_[i].c_str(), textX_, textX_ + lineSpacing_*i, fontSize_, guiColor_);
    }

    if (GuiButton(Rectangle{600, 50, 100, 30}, "Blue")) {
        brush.color = BLUE;
    }
    if (GuiButton(Rectangle{600, 80, 100, 30}, "Red")) {
        brush.color = RED;
    }
    if (GuiButton(Rectangle{600,110,100,30}, "Green")) {
        brush.color = GREEN;
    }
    float thickness = brush.thickness;
    if (!brush.isEraser) {
        GuiSliderBar(Rectangle{600, 150, 100, 30}, "Brush Size", NULL, &thickness, 1, 10);
    } else {
        GuiSliderBar(Rectangle{600, 150, 100, 30}, "Eraser Size", NULL, &thickness, 1, 30);
    }
    
    brush.thickness = thickness;
}
