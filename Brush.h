#pragma once
#include "raylib.h"
class Brush {
    public:
        Brush();
        Brush(Color color, float thickness);
        void setThickness(float);
        //void changeBrush();
        void setColor(Color);
        Color getColor() const;
        float getThickness() const; 

    private:
        Color color_;
        float thickness_;
        

};