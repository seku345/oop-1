#ifndef OOP_1_GEOMETRY_H
#define OOP_1_GEOMETRY_H

class Rectangle {
private:
    float length;
    float width;
    float x_cor;
    float y_cor;
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

    void setLength(float newLength);
    void setWidth(float newWidth);
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
public:
    Square(float length) : Rectangle(length, length) {};
    Square(float length, float x, float y) : Rectangle(length, length, x, y) {};
};

#endif //OOP_1_GEOMETRY_H