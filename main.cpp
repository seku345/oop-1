#include "iostream"
#include "geometry.h"

int main() {
//    Rectangle my_rectangle = Rectangle::createRandomRectangle();
//    std::cout << my_rectangle.getRectInfo();
//    Rectangle rect{3, 4};
//    std::cout << rect.isPointInside(0, 0);
//    Rectangle rect1{4, 2, 0, 0};
//    Rectangle rect2{1, 8, 2, 0};
//    std::cout << (rect1 == rect2) << '\n';
//    std::cout << rect1.isEqual(rect2);
//    Circle circle{5};
//    std::cout << Circle::getPI();
    Square square{1, 2, 0};
    Rectangle rect{2, 3, 1, -1};
    Rectangle sum = (square + rect);
    Square square1 = Square::createRandomSquare();
    square1.setLength(10);
    std::cout << square1.getRectInfo();
}