// 3,2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <bitset>

using namespace std;

// Функция для выполнения операции сложения в поле GF(2,n)
bitset<8> gf2n_addition(const bitset<8>& a, const bitset<8>& b) {
    return a ^ b;  // XOR для сложения
}

// Функция для выполнения операции вычитания в поле GF(2,n)
bitset<8> gf2n_subtraction(const bitset<8>& a, const bitset<8>& b) {
    return a ^ b;  // XOR для вычитания
}

// Функция для выполнения операции умножения в поле GF(2,n)
bitset<8> gf2n_multiplication(const bitset<8>& a, const bitset<8>& b, const bitset<8>& M) {
    bitset<8> result(0);
    for (int i = 0; i < 8; i++) {
        if (b[i]) {
            result ^= (a << i);
        }
    }

    while (result[7]) {
        result ^= (M << (result.size() - M.size()));
    }
    return result;
}

// Функция для поиска обратного элемента a в поле GF(2,n)
bitset<8> gf2n_inverse(const bitset<8>& a, const bitset<8>& M) {
    if (a == 0) {
        cerr << "Обратного элемента нет (деление на ноль)." << endl;
        return bitset<8>(0);
    }
    bitset<8> b = a;
    bitset<8> result(1);

    while (b != 1) {
        int shift = b.size() - 1;
        while (!b[shift]) {
            shift--;
        }
        if (shift > 0) {
            result ^= (M << (shift - 1));
            b ^= (a << (shift - 1));
        }
        else {
            result ^= M;
            break;
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");
    int a, b, M;
    cout << "Введите a (десятичное число): ";
    cin >> a;
    cout << "Введите b (десятичное число): ";
    cin >> b;
    cout << "Введите M (десятичное число): ";
    cin >> M;

    bitset<8> bit_a(a);
    bitset<8> bit_b(b);
    bitset<8> bit_M(M);

    cout << "a (битовое представление): " << bit_a << endl;
    cout << "b (битовое представление): " << bit_b << endl;
    cout << "M (битовое представление): " << bit_M << endl;

    // Сложение a + b в поле GF(2)
    bitset<8> sum = gf2n_addition(bit_a, bit_b);
    cout << "a + b = " << sum << endl;

    // Вычитание a - b в поле GF(2)
    bitset<8> diff = gf2n_subtraction(bit_a, bit_b);
    cout << "a - b = " << diff << endl;

    // Умножение a * b в поле GF(2)
    bitset<8> product = gf2n_multiplication(bit_a, bit_b, bit_M);
    cout << "a * b = " << product << endl;

    // Поиск обратного элемента a в поле GF(2)
    bitset<8> inverse_a = gf2n_inverse(bit_a, bit_M);
    cout << "Обратный элемент a = " << inverse_a << endl;

    return 0;
}



