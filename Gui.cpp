#include "Gui.h"
#include "raylib.h"
#include "include/raygui/src/raygui.h"
#include <memory>

void Gui::drawGui(Brush& brush, RenderTexture2D& canvas) {
    DrawText("Hold L-click to draw", 20, 20, 10, RED);
    DrawText("Press C to clear", 20, 30, 10, RED);

    if (GuiButton(Rectangle{600, 50, 100, 30}, "Blue")) {
        brush.setColor(BLUE);
    }
    if (GuiButton(Rectangle{600, 80, 100, 30}, "Red")) {
        brush.setColor(RED);
    }
    if (GuiButton(Rectangle{600,110,100,30}, "Green")) {
        brush.setColor(GREEN);
    }
    float thickness = brush.getThickness();
    GuiSliderBar(Rectangle{600, 150, 100, 30}, "Brush Size", NULL, &thickness, 1, 10);
    brush.setThickness(thickness);
}
