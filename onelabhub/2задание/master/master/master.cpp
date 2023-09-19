#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Функция для выполнения команды XOR
unsigned long long performXOR(unsigned long long num1, unsigned long long num2) {
    return num1 ^ num2;
}

// Функция для выполнения команды AND
unsigned long long performAND(unsigned long long num1, unsigned long long num2) {
    return num1 & num2;
}

// Функция для выполнения команды OR
unsigned long long performOR(unsigned long long num1, unsigned long long num2) {
    return num1 | num2;
}

// Функция для выполнения команды SET1
unsigned long long performSET1(unsigned long long num1, int bitIndex) {
    return num1 | (1ULL << bitIndex);
}

// Функция для выполнения команды SET0
unsigned long long performSET0(unsigned long long num1, int bitIndex) {
    return num1 & ~(1ULL << bitIndex);
}

// Функция для выполнения команды SHL
unsigned long long performSHL(unsigned long long num1, int shiftAmount) {
    return num1 << shiftAmount;
}

// Функция для выполнения команды SHR
unsigned long long performSHR(unsigned long long num1, int shiftAmount) {
    return num1 >> shiftAmount;
}

// Функция для выполнения команды ROL
unsigned long long performROL(unsigned long long num1, int shiftAmount) {
    return (num1 << shiftAmount) | (num1 >> (64 - shiftAmount));
}

// Функция для выполнения команды ROR
unsigned long long performROR(unsigned long long num1, int shiftAmount) {
    return (num1 >> shiftAmount) | (num1 << (64 - shiftAmount));
}

// Функция для выполнения команды MIX
unsigned long long performMIX(unsigned long long num1, unsigned long long num2) {
    unsigned long long result = 0;
    for (int i = 0; i < 8; i++) {
        int bitIndex = (num1 >> (i * 4)) & 0xF;
        result |= ((num2 >> bitIndex) & 0x1) << i;
    }
    return result;
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    if (argc != 4) {
        cout << "Использование: " << argv[0] << " <команда> <число1> <число2>" << endl;
        return 1;
    }

    string command = argv[1];
    unsigned long long num1 = stoull(argv[2]);
    unsigned long long num2 = stoull(argv[3]);

    unsigned long long result = 0;

    if (command == "xor") {
        result = performXOR(num1, num2);
    }
    else if (command == "and") {
        result = performAND(num1, num2);
    }
    else if (command == "or") {
        result = performOR(num1, num2);
    }
    else if (command == "set1") {
        result = performSET1(num1, num2);
    }
    else if (command == "set0") {
        result = performSET0(num1, num2);
    }
    else if (command == "shl") {
        result = performSHL(num1, num2);
    }
    else if (command == "shr") {
        result = performSHR(num1, num2);
    }
    else if (command == "rol") {
        result = performROL(num1, num2);
    }
    else if (command == "ror") {
        result = performROR(num1, num2);
    }
    else if (command == "mix") {
        result = performMIX(num1, num2);
    }
    else {
        cout << "Неподдерживаемая команда: " << command << endl;
        return 1;
    }

    // Вывод результата в различных форматах
    cout << "Десятичное: " << result << endl;
    cout << "Шестнадцатеричное: 0x" << hex << result << endl;

    // Вывод бинарного представления
    cout << "Бинарное: ";
    for (int i = 63; i >= 0; i--) {
        cout << ((result >> i) & 1);
        if (i % 4 == 0) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
