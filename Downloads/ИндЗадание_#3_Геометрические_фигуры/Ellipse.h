#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

class Ellipse : public Shape {
private:
    Point center_;
    float radiusX_;
    float radiusY_;

public:
    Ellipse(const Point& center, float radiusX, float radiusY);

    float getArea() const override;
    FrameRectangle getFrameRectangle() const override;
    void move(const Point& newPos) override;
    void move(float dx, float dy) override;
    void scale(float factor) override;
    Shape* clone() const override;
    std::string getName() const override;
};

#endif

