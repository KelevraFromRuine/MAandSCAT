
/*
Первая итерация простого кода, который выделяет блок памяти, 
заполняет его случайными данными, вычисляет XOR-сумму и проверяет изменения в ней.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Выделяем блок памяти размером 10 байт
    const int size = 10;
    unsigned char* data = new unsigned char[size];
    
    // Инициализируем генератор случайных чисел
    std::srand(std::time(nullptr));

    while (true) {
        // Заполняем блок случайными данными
        for (int i = 0; i < size; i++) {
            data[i] = std::rand() % 256; // Генерируем случайное значение от 0 до 255
        }

        // Вычисляем XOR-сумму
        unsigned char xorSum = 0;
        for (int i = 0; i < size; i++) {
            xorSum ^= data[i];
        }

        // Задержка на 1 секунду (1000 миллисекунд)
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Повторно вычисляем XOR-сумму
        unsigned char newSum = 0;
        for (int i = 0; i < size; i++) {
            newSum ^= data[i];
        }

        // Проверяем, изменилась ли XOR-сумма
        if (xorSum != newSum) {
            std::cout << "Обнаружены изменения в данных!" << std::endl;
        }
    }

    // Освобождаем память
    delete[] data;

    return 0;
}
