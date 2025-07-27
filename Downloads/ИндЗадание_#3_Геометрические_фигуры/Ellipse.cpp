#include "Ellipse.h"
#include <stdexcept>
#include <math.h>

Ellipse::Ellipse(const Point& center, float radiusX, float radiusY)
    : center_(center), radiusX_(radiusX), radiusY_(radiusY) {
    if (radiusX <= 0 || radiusY <= 0) {
        throw std::invalid_argument("Радиусы должны быть положительными");
    }
}

float Ellipse::getArea() const {
    return M_PI * radiusX_ * radiusY_;
}

FrameRectangle Ellipse::getFrameRectangle() const {
    return FrameRectangle(2 * radiusX_, 2 * radiusY_, center_);
}

void Ellipse::move(const Point& newPos) {
    center_ = newPos;
}

void Ellipse::move(float dx, float dy) {
    center_.x_ += dx;
    center_.y_ += dy;
}

void Ellipse::scale(float factor) {
    if (factor <= 0) {
        throw std::invalid_argument("Коэффициент должен быть положительным");
    }
    radiusX_ *= factor;
    radiusY_ *= factor;
}

Shape* Ellipse::clone() const {
    return new Ellipse(*this);
}

std::string Ellipse::getName() const {
    return "ELLIPSE";
}

