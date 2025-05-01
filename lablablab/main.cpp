#include <iostream>
#include "triangle.h"
using namespace std;

int main() {
    Triangle t;
    Point p;
    cout << "Введіть точки трикутника:\nA: ";
    cin >> t.A.x >> t.A.y; checkStream(cin);
    cout << "B: ";
    cin >> t.B.x >> t.B.y; checkStream(cin);
    cout << "C: ";
    cin >> t.C.x >> t.C.y; checkStream(cin);

    if (!t.isExist()) {
        cout << "Трикутник не існує!\n";
        //return 1;
    }

    bool again = true;
    while (again) {
        cout << "Введіть точку P:\nP: ";
        cin >> p.x >> p.y; checkStream(cin);

        checkPointInT(t, p);

        cout << "Повторити операцію? (0 - ні, 1 - так): ";
        cin >> again; checkStream(cin);
    }
    return 0;
}