#include <iostream>
#include "triangle.h"
using namespace std;

void checkPoint(double a, double b, double c) {
    const double eps = 1e-9;    
    if ((fabs(a) < eps && ((b > 0 && c > 0) || (b < 0 && c < 0))) ||
    (fabs(b) < eps && ((a > 0 && c > 0) || (a < 0 && c < 0))) ||
    (fabs(c) < eps && ((a > 0 && b > 0) || (a < 0 && b < 0)))) {
    cout << "Точка на межі трикутника\n";
    }
    else if ((fabs(a) < eps && ((b > 0 && c > 0) || (b < 0 && c < 0))) ||
    (fabs(b) < eps && ((a > 0 && c > 0) || (a < 0 && c < 0))) ||
    (fabs(c) < eps && ((a > 0 && b > 0) || (a < 0 && b < 0)))) {

        cout << "Точка всередині трикутника\n";
    }
    else {
        cout << "Точка зовні трикутника\n";
    }
}

void checkPointInT(const Triangle& t, const Point& p) {
    double cross1 = (t.B.x - t.A.x)*(p.y - t.A.y)-(p.x - t.A.x)*(t.B.y - t.A.y);
    double cross2 = (t.C.x - t.B.x)*(p.y - t.B.y)-(p.x - t.B.x)*(t.C.y - t.B.y);
    double cross3 = (t.A.x - t.C.x)*(p.y - t.C.y)-(p.x - t.C.x)*(t.A.y - t.C.y);

    checkPoint(cross1, cross2, cross3);
}

void checkStream(std::istream& is) {
    if (is.fail()) {
        cerr << "Некоректний ввід! Спробуйте ще раз.\n";
        exit(1);
    }
}