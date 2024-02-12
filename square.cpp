#include "stdexcept"
#include "ctime"
#include "geometry.h"

void Square::setLength(float newLength) {
    if (newLength <= 0) {
        throw std::invalid_argument("The length must be greater than 0");
    }
    this->length = newLength;
    this->width = newLength;
}
void Square::setWidth(float newWidth) {
    if (newWidth <= 0) {
        throw std::invalid_argument("The length must be greater than 0");
    }
    this->length = newWidth;
    this->width = newWidth;
}

Square Square::createRandomSquare() {
    std::srand(std::time(nullptr));
    auto randomLength = static_cast<float>(std::rand() % 20 + 1);
    auto randomX = static_cast<float>(std::rand() % 200 - 50);
    auto randomY = static_cast<float>(std::rand() % 200 - 50);

    return {randomLength, randomX, randomY};
}