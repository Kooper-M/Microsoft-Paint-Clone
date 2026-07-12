#include "Canvas.h"

Canvas::Canvas(int width, int height) {
    width_ = width;
    height_ = height;
}
Canvas::Canvas() {
    width_ = 800;
    height_ = 600;
}

int Canvas::getWidth() const {return width_;}

int Canvas::getHeight() const {return height_;}

Texture Canvas::getTexture() const {return canvas_.texture;}

RenderTexture2D& Canvas::get2DTexture() {return canvas_;}

void Canvas::init() {
    canvas_ = LoadRenderTexture(width_, height_);
    loaded_ = true;

    BeginTextureMode(canvas_);
        ClearBackground(RAYWHITE);
    EndTextureMode();
}

void Canvas::unload() {
    if (loaded_) {
        UnloadRenderTexture(canvas_);
        loaded_ = false;
    }
}

void Canvas::drawCanvas() {
        DrawTextureRec(
        canvas_.texture,
        Rectangle{0, 0, (float)canvas_.texture.width, -(float)canvas_.texture.height},
        Vector2{0,0},
        RAYWHITE);
}