// 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

// Функция для вывода первых N простых чисел с использованием решета Эратосфена
void printFirstNPrimes(int N) {
    if (N <= 0) {
        cout << "Введите положительное число N." << endl;
        return;
    }

    vector<bool> isPrime(N * 10, true); // Используем вектор булевых значений для определения простых чисел
    vector<int> primes;

    for (int p = 2; p * p < N * 10; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i < N * 10; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p < N * 10 && primes.size() < N; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    cout << "Первые " << N << " простых чисел:" << endl;
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;
}

// Функция для проверки числа на простоту
bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "ru");

    int choice, N, number;

    cout << "Выберите действие:" << endl;
    cout << "1. Вывести первые N простых чисел." << endl;
    cout << "2. Проверить число на простоту." << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Введите N: ";
        cin >> N;
        printFirstNPrimes(N);
        break;
    case 2:
        cout << "Введите число для проверки на простоту: ";
        cin >> number;
        if (isPrime(number)) {
            cout << number << " - простое число." << endl;
        }
        else {
            cout << number << " - не является простым числом." << endl;
        }
        break;
    default:
        cout << "Неверный выбор." << endl;
        break;
    }

    return 0;
}

