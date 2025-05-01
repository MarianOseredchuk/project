#include <iostream>
#include "Sort.h"
using namespace std;

int main() {
    int n;
    cout << "Введіть кількість елементів: ";
    cin >> n;

    datatype arr[n];
    cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start, end;
    cout << "Введіть початковий і кінцевий індекси підмасиву (від 0): ";
    cin >> start >> end;

    if (start < 0 || end < 0 || start > end || end >= n) {
        cout << "Невірний діапазон для підмасиву\n";
        return 1;
    }

    cout << "Ваш масив: ";
    Show(arr, n, start, end);

    cout << "Оберіть метод сортування:\n";
    cout << "1 - Бульбашкове сортування\n";
    cout << "2 - Сортування вставкою\n";
    cout << "3 - Сортування вибором\n";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            SortBubble(arr, start, end);
            cout << "Відсортований масив (бульбашкове сортування): ";
            Show(arr, n, start, end);
            break;
        case 2:
            SortInsertion(arr, start, end);
            cout << "Відсортований масив (сортування вставкою): ";
            Show(arr, n, start, end);
            break;
        case 3:
            SortSelection(arr, start, end);
            cout << "Відсортований масив (сортування вибором): ";
            Show(arr, n, start, end);
            break;
        default:
            cout << "Невірний вибір\n";
    }

    return 0;
}
