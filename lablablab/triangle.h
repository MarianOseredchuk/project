#pragma once
#include <iostream>
#include <cmath>

struct Point { 
    double x, y; 
};

struct Triangle {
    Point A, B, C;
    bool isExist() const {
        double area2 = (B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y);
        const double eps = 1e-9;
        return std::abs(area2) > eps;
    }
};

bool triangleExist(const Triangle& t);
void checkPoint(double a, double b, double c);
void checkPointInT(const Triangle& t, const Point& p);

void checkStream(std::istream& is);