#include "stdexcept"
#include "geometry.h"

Rectangle::Rectangle(float length, float width, float x, float y) {
    if (length <= 0) {
        throw std::invalid_argument("The length must be greater than 0");
    }
    if (width <= 0 ) {
        throw std::invalid_argument("The width must be greater than 0");
    }
    this->length = length;
    this->width = width;
    this->x_cor = x;
    this->y_cor = y;
}

float Rectangle::getLength() const {
    return this->length;
}
float Rectangle::getWidth() const {
    return this->width;
}
float Rectangle::getX() const {
    return this->x_cor;
}
float Rectangle::getY() const {
    return this->y_cor;
}