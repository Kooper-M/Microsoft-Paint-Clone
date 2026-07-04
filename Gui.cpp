#include "Gui.h"
#include "raylib.h"
#include "include/raygui/src/raygui.h"
#include <memory>

void Gui::drawGui(Color& brushColor, RenderTexture2D& canvas, float& brushThickness) {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawTextureRec(
                canvas.texture,
                Rectangle{0, 0, (float)canvas.texture.width, -(float)canvas.texture.height},
                Vector2{0,0},
                RAYWHITE);

            DrawText("Hold L-click to draw", 20, 20, 10, RED);
            DrawText("Press C to clear", 20, 30, 10, RED);

            if (GuiButton(Rectangle{600, 50, 100, 30}, "Blue")) {
                brushColor = BLUE;
            }
            if (GuiButton(Rectangle{600, 80, 100, 30}, "Red")) {
                brushColor = RED;
            }
            if (GuiButton(Rectangle{600,110,100,30}, "Green")) {
                brushColor = GREEN;
            }
            GuiSliderBar(Rectangle{600, 150, 100, 30}, "Brush Size", NULL, &brushThickness, 1, 10);
        EndDrawing();
}
