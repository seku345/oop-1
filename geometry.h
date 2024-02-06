#ifndef OOP_1_GEOMETRY_H
#define OOP_1_GEOMETRY_H

class Rectangle {
private:
    float length;
    float width;
    float x_cor;
    float y_cor;
public:
    Rectangle(float length, float width, float x = 0.0, float y = 0.0);

    float getLength() const;
    float getWidth() const;
    float getX() const;
    float getY() const;
};

#endif //OOP_1_GEOMETRY_H