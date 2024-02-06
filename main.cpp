#include "iostream"
#include "geometry.h"

int main() {
    Rectangle my_rectangle = Rectangle::createRandomRectangle();
    std::cout << my_rectangle.getRectInfo();
}