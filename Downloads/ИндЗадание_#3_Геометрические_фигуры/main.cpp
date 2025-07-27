#include <iostream>
#include <iomanip>
#include "Ellipse.h"
#include "Square.h"

const float moveX_1 = 1.0;
const float moveX_2 = -1.0;
const float moveY_1 = 1.0;
const float moveY_2 = -1.0;
const float scale_1 = 2.0;
const float scale_2 = -2.0;

void printShapeInfo(const Shape& shape);

int main() {
    try {
        //объекты фигур
        Ellipse ellipse(Point(0.0, 0.0), 3.0, 4.0);
        Square square(Point(2.0, 2.0), 2.0);
//        Ellipse ellipseW(Point(0.0, 0.0), -3.0, 4.0); // ошибка отрицательного радиуса
//        Square squareW(Point(2.0, 2.0), -2.0); // ошибка отрицательной стороны
        
        //массив указателей на класс базовый Shape
        Shape* shapes[] = { &ellipse, &square};
        
        for (Shape* shape : shapes) {
            try{
                printShapeInfo(*shape);
                shape->move(moveX_1, moveY_1);
                printShapeInfo(*shape);
                shape->move(moveX_2, moveY_2);
                printShapeInfo(*shape);
                shape->scale(scale_1);
                printShapeInfo(*shape);
                shape->scale(scale_2);
            } catch (const std::invalid_argument& ex) {
                std::cout << "Error: " << ex.what() << std::endl;
            }
        }
    } catch (const std::invalid_argument& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return 0;
}

void printShapeInfo(const Shape& shape) {
    FrameRectangle frame = shape.getFrameRectangle(); //полиморфный вызов
    std::cout << shape.getName() << " "
              << std::fixed << std::setprecision(1)
              << shape.getArea() << " "
              << frame.pos_.x_ - frame.width_ / 2 << " "
              << frame.pos_.y_ - frame.height_ / 2 << " "
              << frame.pos_.x_ + frame.width_ / 2 << " "
              << frame.pos_.y_ + frame.height_ / 2 << std::endl;
}
