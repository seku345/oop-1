#include "iostream"
#include "geometry.h"

int main() {
//    Rectangle my_rectangle = Rectangle::createRandomRectangle();
//    std::cout << my_rectangle.getRectInfo();
//    Rectangle rect{3, 4};
//    std::cout << rect.isPointInside(0, 0);
    Rectangle rect1{2, 2, 1, 0};
    Rectangle rect2{3, 2, 2, -1};
    Rectangle rect3 = (rect1 * 2);
    std::cout << rect3.getRectInfo();
}