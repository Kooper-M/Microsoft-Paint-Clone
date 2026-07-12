#include "raylib.h"
#include <vector>
#include <stack>
#define RAYGUI_IMPLEMENTATION
#include "include/raygui/src/raygui.h"
#include <tuple>
#include "UndoStack.h"
#include "Gui.h"
#include "PaintApp.h"
//g++ -std=c++17 main.cpp PaintApp.cpp Canvas.cpp Gui.cpp UndoStack.cpp -o main.exe -lraylib -lopengl32 -lgdi32 -lwinmm && ./main.exe


int main() {
    PaintApp app;
    app.run();
    return 0;
}