#include "iostream"
#include "stdexcept"
#include "format"
#include "geometry.h"

Rectangle::Rectangle(float length, float width) {
    if (length <= 0) {
        throw std::invalid_argument("The length must be greater than 0");
    }
    if (width <= 0 ) {
        throw std::invalid_argument("The width must be greater than 0");
    }
    this->length = length;
    this->width = width;
    this->x_cor = 0.0;
    this->y_cor = 0.0;
}

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
float Rectangle::getArea() const {
    if (cachedArea == 0) {
        cachedArea = this->length * this->width;
    }
    return cachedArea;
}
float Rectangle::getPerimeter() const {
    if (cachedPerimeter == 0) {
        cachedPerimeter = 2 * (this->length + this->width);
    }
    return cachedPerimeter;
}

void Rectangle::resetCache() {
    this->cachedArea = 0;
    this->cachedPerimeter = 0;
}

std::string Rectangle::getRectInfo() const {
    return std::format("Length: {}\nWidth: {}\nX: {}\nY: {}\nArea: {}\nPerimeter: {}",
                       this->getLength(), this->getWidth(), this->getX(), this->getY(),
                       this->getArea(), this->getPerimeter());
}