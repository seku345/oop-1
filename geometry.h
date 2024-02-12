#ifndef OOP_1_GEOMETRY_H
#define OOP_1_GEOMETRY_H

#include <string>

class Rectangle {
protected:
    float length;
    float width;
    float x;
    float y;
    mutable float cachedArea{0};
    mutable float cachedPerimeter{0};
public:
    Rectangle(float length, float width);
    Rectangle(float length, float width, float x, float y);

    std::string getRectInfo() const;
    float getLength() const;
    float getWidth() const;
    float getX() const;
    float getY() const;
    float getArea() const;
    float getPerimeter() const;

    virtual void setLength(float newLength);
    virtual void setWidth(float newWidth);
    void setX(float newX);
    void setY(float newY);

    void resize(float factor);
    void move(float deltaX, float deltaY);

    void resetCache();

    bool isPointInside(float x, float y) const;
    bool isIntersecting(const Rectangle& other) const;
    bool isEqual(const Rectangle& other) const;

    bool operator==(const Rectangle& other) const;
    bool operator>(const Rectangle& other) const;
    bool operator>=(const Rectangle& other) const;
    bool operator<(const Rectangle& other) const;
    bool operator<=(const Rectangle& other) const;
    bool operator!=(const Rectangle& other) const;

    Rectangle operator+(const Rectangle& other) const;
    Rectangle operator&(const Rectangle& other) const;
    Rectangle operator*(const float& factor) const;
    Rectangle operator/(const float& factor) const;

    static Rectangle createRandomRectangle();
};

class Square : public Rectangle {
private:
    using Rectangle::createRandomRectangle;
public:
    Square(float length) : Rectangle(length, length) {};
    Square(float length, float x, float y) : Rectangle(length, length, x, y) {};

    void setLength(float newLength) override;
    void setWidth(float newWidth) override;

    static Square createRandomSquare();
};

class Circle {
private:
    float radius;
    float x;
    float y;
    mutable float cachedDiameter{0};
    mutable float cachedArea{0};
    mutable float cachedCircumference{0};
    constexpr static double const PI{3.1415926535897932384626433832795};
public:
    Circle(float radius);
    Circle(float radius, float x, float y);

    std::string getCircleInfo() const;
    float getRadius() const;
    float getX() const;
    float getY() const;
    float getDiameter() const;
    float getArea() const;
    float getCircumference() const;
    static double getPI();
};

#endif //OOP_1_GEOMETRY_H