#include "Brush.h"
Brush::Brush() : color_(RED), thickness_(5.0f) {}
Brush::Brush(Color color, float thickness) : color_(color), thickness_(thickness) {}

void Brush::setThickness(float thickness) {
    thickness_ = thickness;
}

void Brush::setColor(Color color) {
    color_ = color;
}

Color Brush::getColor() const {
    return color_;
}

float Brush::getThickness() const {
    return thickness_;
}