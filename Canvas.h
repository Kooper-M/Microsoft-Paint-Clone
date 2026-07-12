#pragma once
#include "raylib.h"
class Canvas {
    public:
        Canvas(int width, int height);
        Canvas();
        int getWidth() const;
        int getHeight() const;
        void init();
        Texture getTexture() const;
        RenderTexture2D& get2DTexture();
        void unload();
        void drawCanvas();
    private:
        int width_;
        int height_;
        bool loaded_ = false;
        RenderTexture2D canvas_;
        
};