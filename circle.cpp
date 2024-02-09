#include "stdexcept"
#include "format"
#include "cstdlib"
#include "ctime"
#include "geometry.h"

Circle::Circle(float radius) {
    if (radius <= 0) {
        throw std::invalid_argument("The radius must be greater than 0");
    }
    this->radius = radius;
    this->x = 0.0;
    this->y = 0.0;
}
Circle::Circle(float radius, float x, float y) {
    if (radius <= 0) {
        throw std::invalid_argument("The radius must be greater than 0");
    }
    this->radius = radius;
    this->x = x;
    this->y = y;
}

float Circle::getRadius() const {

}
float Circle::getX() const {

}
float Circle::getY() const {

}
float Circle::getDiameter() const {

}
float Circle::getArea() const {

}
float Circle::getCircumference() const {

}

double Circle::getPI() {
    return Circle::PI;
}