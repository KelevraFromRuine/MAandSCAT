// 3.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

// Функция для вычисления НОД (наибольшего общего делителя)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Функция для нахождения обратного элемента a по модулю M (a^(-1) mod M)
int modInverse(int a, int M) {
    for (int x = 1; x < M; x++) {
        if ((a * x) % M == 1) {
            return x;
        }
    }
    return -1; // Обратного элемента нет
}

int main() {
    setlocale(LC_ALL, "ru");
    int a, b, M;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите M: ";
    cin >> M;

    // Сложение (a + b) mod M
    int sum = (a + b) % M;
    cout << "(a + b) mod M = " << sum << endl;

    // Вычитание (a - b) mod M
    int diff = (a - b + M) % M;
    cout << "(a - b) mod M = " << diff << endl;

    // Умножение (a * b) mod M
    int product = (a * b) % M;
    cout << "(a * b) mod M = " << product << endl;

    // Возведение в степень (a^b) mod M
    int result = 1;
    for (int i = 0; i < b; i++) {
        result = (result * a) % M;
    }
    cout << "(a^b) mod M = " << result << endl;

    // Поиск обратного элемента a по модулю M (a^(-1) mod M)
    int inverse_a = modInverse(a, M);
    if (inverse_a != -1) {
        cout << "a^(-1) mod M = " << inverse_a << endl;
    }
    else {
        cout << "a^(-1) mod M = нет решения" << endl;
    }

    // Поиск обратного элемента b по модулю M (b^(-1) mod M)
    int inverse_b = modInverse(b, M);
    if (inverse_b != -1) {
        cout << "b^(-1) mod M = " << inverse_b << endl;
    }
    else {
        cout << "b^(-1) mod M = нет решения" << endl;
    }

    // Деление (a / b) mod M
    if (gcd(b, M) == 1) {
        int division = (a * modInverse(b, M)) % M;
        cout << "(a / b) mod M = " << division << endl;
    }
    else {
        cout << "(a / b) mod M = нет решения (b и M не взаимно просты)" << endl;
    }

    return 0;
}
