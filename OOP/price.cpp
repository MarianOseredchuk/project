#include "price.h"
#include <fstream>
#include <iostream>
#include <string>

void add(Price& a, const Price& b) {
    a.hryvnias += b.hryvnias;
    a.kopiykas += b.kopiykas;
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
    std::cout << price.hryvnias << " грн " << price.kopiykas << " коп";
}

void processPrices(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Помилка відкриття файлу!" << std::endl;
        return;
    }

    Price total{0, 0};
    Price item{0, 0};
    int quantity;

    while (file >> item.hryvnias >> item.kopiykas >> quantity) {
        multiply(item, quantity); // змінюємо item
        add(total, item); // додаємо до total
    }

    file.close();

    std::cout << "Загальна сума: ";
    print(total);
    std::cout << std::endl;

    roundTo10(total);
    std::cout << "Сума до оплати: ";
    print(total);
    std::cout << std::endl;
}

