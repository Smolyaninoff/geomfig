#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
private:
    Point bottomLeft_;
    float side_;

public:
    Square(const Point& bottomLeft, float side);

    float getArea() const override;
    FrameRectangle getFrameRectangle() const override;
    void move(const Point& newPos) override;
    void move(float dx, float dy) override;
    void scale(float factor) override;
    Shape* clone() const override;
    std::string getName() const override;
};

#endif
