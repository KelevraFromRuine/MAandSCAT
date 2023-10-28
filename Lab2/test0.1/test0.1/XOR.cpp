#include <iostream>
#include <cstdint>

uint8_t calculateXOR(const uint8_t* data, int size) {
    uint8_t result = 0;
    for (int i = 0; i < size; ++i) {
        result ^= data[i];
    }
    return result;
}

int main() {
    const int dataSize = 8;
    uint8_t data[dataSize] = {0b10101010, 0b11001100, 0b11110000, 0b00001111, 0b01010101, 0b11100000, 0b00001111, 0b10101010};
    
    uint8_t initialXOR = calculateXOR(data, dataSize);

    // Изменяем несколько битов
    data[3] ^= 0b00100000;  // Изменяем 3-й бит в байте

    uint8_t modifiedXOR = calculateXOR(data, dataSize);

    std::cout << "Исходная XOR-сумма: " << static_cast<int>(initialXOR) << std::endl;
    std::cout << "Модифицированная XOR-сумма: " << static_cast<int>(modifiedXOR) << std::endl;

    if (initialXOR != modifiedXOR) {
        std::cout << "Обнаружены изменения в данных!" << std::endl;
    }

    return 0;
}
