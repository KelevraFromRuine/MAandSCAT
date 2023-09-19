#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool negative;

public:
    // Конструктор по умолчанию
    BigInteger() : negative(false) {}

    // Конструктор из строки
    BigInteger(const string& numStr) {
        if (numStr.empty()) {
            negative = false;
            return;
        }

        if (numStr[0] == '-') {
            negative = true;
            for (int i = numStr.size() - 1; i >= 1; i--) {
                digits.push_back(numStr[i] - '0');
            }
        }
        else {
            negative = false;
            for (int i = numStr.size() - 1; i >= 0; i--) {
                digits.push_back(numStr[i] - '0');
            }
        }
    }

    // Конструктор из целого числа
    BigInteger(int num) {
        negative = (num < 0);
        num = abs(num);
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    // Сложение
    BigInteger operator+(const BigInteger& other) const {
        if (negative == other.negative) {
            BigInteger result;
            int carry = 0;
            int maxSize = max(digits.size(), other.digits.size());

            for (int i = 0; i < maxSize || carry; i++) {
                if (i == result.digits.size()) {
                    result.digits.push_back(0);
                }
                int sum = result.digits[i] + carry;
                if (i < digits.size()) {
                    sum += digits[i];
                }
                if (i < other.digits.size()) {
                    sum += other.digits[i];
                }
                result.digits[i] = sum % 10;
                carry = sum / 10;
            }

            result.negative = negative;
            return result;
        }
        else {
            if (negative) {
                return other - (-*this);
            }
            else {
                return *this - (-other);
            }
        }
    }

    // Умножение
    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.digits.resize(digits.size() + other.digits.size());

        for (int i = 0; i < digits.size(); i++) {
            int carry = 0;
            for (int j = 0; j < other.digits.size() || carry; j++) {
                long long cur = result.digits[i + j] +
                    digits[i] * 1LL * (j < other.digits.size() ? other.digits[j] : 0) + carry;
                result.digits[i + j] = cur % 10;
                carry = cur / 10;
            }
        }

        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }

        result.negative = (negative != other.negative);
        return result;
    }

    // Приведение по модулю
    BigInteger operator%(const BigInteger& mod) const {
        BigInteger result = *this;
        result.negative = false; // Результат всегда положительный

        BigInteger current = mod;
        while (current <= result) {
            BigInteger temp = current;
            int power = 1;
            while (result >= (temp << 1)) {
                temp <<= 1;
                power <<= 1;
            }
            result = result - temp;
        }

        return result;
    }

    // Вывод на экран
    friend ostream& operator<<(ostream& os, const BigInteger& num) {
        if (num.negative && !(num.digits.size() == 1 && num.digits[0] == 0)) {
            os << "-";
        }
        for (int i = num.digits.size() - 1; i >= 0; i--) {
            os << num.digits[i];
        }
        return os;
    }
};

int main() {
    // Пример использования класса BigInteger
    BigInteger num1("123456789012345678901234567890");
    BigInteger num2(987654321);

    BigInteger sum = num1 + num2;
    BigInteger product = num1 * num2;
    BigInteger modulo = num1 % num2;

    cout << "Сумма: " << sum << endl;
    cout << "Произведение: " << product << endl;
    cout << "Остаток от деления: " << modulo << endl;

    return 0;
}
