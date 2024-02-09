#include "stdexcept"
#include "format"
#include "cstdlib"
#include "ctime"
#include "geometry.h"

Rectangle::Rectangle(float const length, float const width) {
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

Rectangle::Rectangle(float const length, float const width, float const x, float const y) {
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
    if (this->cachedArea == 0) {
        this->cachedArea = this->length * this->width;
    }
    return this->cachedArea;
}
float Rectangle::getPerimeter() const {
    if (this->cachedPerimeter == 0) {
        this->cachedPerimeter = 2 * (this->length + this->width);
    }
    return this->cachedPerimeter;
}

void Rectangle::setLength(float const newLength) {
     if (newLength <= 0) {
         throw std::invalid_argument("The length must be greater than 0");
     }
     this->length = newLength;
}
void Rectangle::setWidth(float const newWidth) {
    if (newWidth <= 0) {
        throw std::invalid_argument("The width must be greater than 0");
    }
    this->width = newWidth;
}
void Rectangle::setX(float const newX) {
    this->x_cor = newX;
}
void Rectangle::setY(float const newY) {
    this->y_cor = newY;
}

void Rectangle::resize(float const factor) {
    if (factor <= 0) {
        throw std::invalid_argument("The factor must be greater than 0");
    }
    resetCache();
    this->length *= factor;
    this->width *= factor;
}
void Rectangle::move(float const deltaX, float const deltaY) {
    this->x_cor += deltaX;
    this->y_cor += deltaY;
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

bool Rectangle::isPointInside(const float x, const float y) const {
    float x1{this->x_cor}, x2{this->x_cor + this->length}, y1{this->y_cor}, y2{this->y_cor + this->width};
    return (x >= x1 and x <= x2) and (y >= y1 and y <= y2);
}
bool Rectangle::isIntersecting(const Rectangle& other) const {
    float x1{this->x_cor}, x2{this->x_cor + this->length}, y1{this->y_cor}, y2{this->y_cor + this->width};
    float X1{other.x_cor}, X2{other.x_cor + other.length}, Y1{other.y_cor}, Y2{other.y_cor + other.width};
    return x1 <= X2 and x2 >= X1 and y1 <= Y2 and y2 >= Y1;
}
bool Rectangle::isEqual(const Rectangle &other) const {
    return ((this->length == other.length) and (this->width == other.width)) or
           ((this->length == other.width) and (this->width == other.length));
}

bool Rectangle::operator==(const Rectangle& other) const {
    return this->getArea() == other.getArea();
}
bool Rectangle::operator>(const Rectangle &other) const {
    return this->getArea() > other.getArea();
}
bool Rectangle::operator<(const Rectangle &other) const {
    return this->getArea() < other.getArea();
}
bool Rectangle::operator>=(const Rectangle &other) const {
    return this->getArea() >= other.getArea();
}
bool Rectangle::operator<=(const Rectangle &other) const {
    return this->getArea() <= other.getArea();
}
bool Rectangle::operator!=(const Rectangle &other) const {
    return this->getArea() != other.getArea();
}

Rectangle Rectangle::operator+(const Rectangle &other) const {
    float x1{this->x_cor}, x2{this->x_cor + this->length}, y1{this->y_cor}, y2{this->y_cor + this->width};
    float X1{other.x_cor}, X2{other.x_cor + other.length}, Y1{other.y_cor}, Y2{other.y_cor + other.width};
    float newX1 = std::min(x1, X1);
    float newY1 = std::min(y1, Y1);
    float newX2 = std::max(x2, X2);
    float newY2 = std::max(y2, Y2);
    return {newX2 - newX1, newY2 - newY1, newX1, newY1};
}
Rectangle Rectangle::operator&(const Rectangle &other) const {
    if (not this->isIntersecting(other)) {
        throw std::invalid_argument("Rectangles don't intersect");
    }
    float x1{this->x_cor}, x2{this->x_cor + this->length}, y1{this->y_cor}, y2{this->y_cor + this->width};
    float X1{other.x_cor}, X2{other.x_cor + other.length}, Y1{other.y_cor}, Y2{other.y_cor + other.width};
    float newX1 = std::max(x1, X1);
    float newY1 = std::max(y1, Y1);
    float newX2 = std::min(x2, X2);
    float newY2 = std::min(y2, Y2);
    if (newX1 == newX2 or newY1 == newY2) {
        throw std::invalid_argument("The area of the new Rectangle is zero");
    }
    return {newX2 - newX1, newY2 - newY1, newX1, newY1};
}
Rectangle Rectangle::operator*(const float& factor) const {
    if (factor <= 0) {
        throw std::invalid_argument("The factor must be greater than 0");
    }
    return {this->length * factor, this->width * factor, this->x_cor, this->y_cor};
}
Rectangle Rectangle::operator/(const float& factor) const {
    if (factor <= 0) {
        throw std::invalid_argument("The factor must be greater than 0");
    }
    return {this->length / factor, this->width / factor, this->x_cor, this->y_cor};
}

Rectangle Rectangle::createRandomRectangle() {
    std::srand(std::time(nullptr));
    auto randomLength = static_cast<float>(std::rand() % 20 + 1);
    auto randomWidth = static_cast<float>(std::rand() % 20 + 1);
    auto randomX = static_cast<float>(std::rand() % 200 - 50);
    auto randomY = static_cast<float>(std::rand() % 200 - 50);

    return {randomLength, randomWidth, randomX, randomY};
}