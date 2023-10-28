#include <iostream>
#include <cstdint>
#include <cstring>

int main() {
    const int dataSize = 10;
    uint8_t data[dataSize] = {0};  // Исходные данные, все байты установлены в 0
    
    // Вывод исходных данных
    std::cout << "Исходные данные: ";
    for (int i = 0; i < dataSize; ++i) {
        std::cout << static_cast<int>(data[i]) << " ";
    }
    std::cout << std::endl;

    // Меняем несколько байтов
    data[1] = 42;
    data[3] = 99;

    // Вывод измененных данных
    std::cout << "Измененные данные: ";
    for (int i = 0; i < dataSize; ++i) {
        std::cout << static_cast<int>(data[i]) << " ";
    }
    std::cout << std::endl;

    return 0;
}
