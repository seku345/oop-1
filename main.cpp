#include "iostream"
#include "geometry.h"

int main() {
//    Rectangle my_rectangle = Rectangle::createRandomRectangle();
//    std::cout << my_rectangle.getRectInfo();
    Rectangle rect{3, 4};
    std::cout << rect.isPointInside(0, 0);
}