#pragma once
#include "raylib.h"
class Canvas {
    public:
        Canvas(int width, int height);
        Canvas();
        int getWidth() const;
        int getHeight() const;
        void init();
        RenderTexture2D& getTexture();
        void unload();
        void drawCanvas();
    private:
        int width_;
        int height_;
        bool loaded_ = false;
        RenderTexture2D canvas_;
        
};