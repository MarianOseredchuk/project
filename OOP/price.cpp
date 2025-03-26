#include "price.h"
#include <fstream>
#include <iostream>

void add(Price& a, const Price& b) {
    a.hryvnias += b.hryvnias;
    a.kopiykas += b.kopiykas;
    if (a.kopiykas >= 100) {
        a.hryvnias += a.kopiykas / 100;
        a.kopiykas %= 100;
    }
}

void multiply(Price& a, int quantity) {
    int totalKopiykas = (a.hryvnias * 100 + a.kopiykas) * quantity;
    a.hryvnias = totalKopiykas / 100;
    a.kopiykas = totalKopiykas % 100;
}

void roundTo10(Price& a) {
    a.kopiykas = (a.kopiykas + 5) / 10 * 10;
    if (a.kopiykas == 100) {
        a.hryvnias += 1;
        a.kopiykas = 0;
    }
}

void print(const Price& price) {
    cout << price.hryvnias << " грн " << price.kopiykas << " коп";
}

void processPrices(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }

    Price total(0, 0);
    int hryvnias, quantity;
    short kopiykas;

    while (file >> hryvnias >> kopiykas >> quantity) {
        Price item(hryvnias, kopiykas);
        multiply(item, quantity);
        add(total, item);
    }

    file.close();

    cout << "Загальна сума: ";
    print(total);
    cout << endl;

    roundTo10(total);
    cout << "Сума до оплати: ";
    print(total);
    cout << endl;
}
