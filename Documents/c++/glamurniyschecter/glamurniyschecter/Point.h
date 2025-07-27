#ifndef POINT_H
#define POINT_H

struct Point {
    float x_;
    float y_;

    Point(float x_ = 0, float y_ = 0) : x_(x_), y_(y_) {}
};

#endif
