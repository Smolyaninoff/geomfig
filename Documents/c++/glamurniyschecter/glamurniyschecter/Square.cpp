#include "Square.h"
#include <stdexcept>

Square::Square(const Point& bottomLeft, float side)
    : bottomLeft_(bottomLeft), side_(side) {
    if (side <= 0) {
        throw std::invalid_argument("Длина стороны должна быть положительной");
    }
}

float Square::getArea() const {
    return side_ * side_;
}

FrameRectangle Square::getFrameRectangle() const {
    Point center(bottomLeft_.x_ + side_ / 2, bottomLeft_.y_ + side_ / 2);
    return FrameRectangle(side_, side_, center);
}

void Square::move(const Point& newPos) {
    bottomLeft_ = Point(newPos.x_ - side_ / 2, newPos.y_ - side_ / 2);
}

void Square::move(float dx, float dy) {
    bottomLeft_.x_ += dx;
    bottomLeft_.y_ += dy;
}

void Square::scale(float factor) {
    FrameRectangle frame = getFrameRectangle();
    if (factor <= 0) {
        throw std::invalid_argument("Коэффициент должен быть положительным");
    }
    side_ *= factor;
    bottomLeft_.x_ = (frame.pos_.x_ - factor) * (frame.pos_.x_ - bottomLeft_.x_);
    bottomLeft_.y_ = (frame.pos_.y_ - factor) * (frame.pos_.y_ - bottomLeft_.y_);
    
}

Shape* Square::clone() const {
    return new Square(*this);
}

std::string Square::getName() const {
    return "SQUARE";
}
