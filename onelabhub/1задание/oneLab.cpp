#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void printHex8(unsigned char byte) {
    cout << setfill('0') << setw(2) << hex << static_cast<int>(byte) << " ";
}

void printDec8(unsigned char byte) {
    cout << setfill('0') << setw(3) << dec << static_cast<int>(byte) << " ";
}

void printHex16(uint16_t word) {
    cout << setfill('0') << setw(4) << hex << word << " ";
}

void printDec16(uint16_t word) {
    cout << setfill('0') << setw(5) << dec << word << " ";
}

void printHex32(uint32_t value) {
    cout << setfill('0') << setw(8) << hex << value << " ";
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Использование: " << argv[0] << " <формат> <путь_к_файлу>" << endl;
        return 1;
    }

    string format = argv[1];
    string filepath = argv[2];

    ifstream file(filepath, ios::binary);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл." << endl;
        return 1;
    }

    if (format == "hex8") {
        unsigned char byte;
        while (file.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
            printHex8(byte);
        }
    } else if (format == "dec8") {
        unsigned char byte;
        while (file.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
            printDec8(byte);
        }
    } else if (format == "hex16") {
        uint16_t word;
        while (file.read(reinterpret_cast<char*>(&word), sizeof(word))) {
            printHex16(word);
        }
    } else if (format == "dec16") {
        uint16_t word;
        while (file.read(reinterpret_cast<char*>(&word), sizeof(word))) {
            printDec16(word);
        }
    } else if (format == "hex32") {
        uint32_t value;
        while (file.read(reinterpret_cast<char*>(&value), sizeof(value))) {
            printHex32(value);
        }
    } else {
        cout << "Неподдерживаемый формат: " << format << endl;
        return 1;
    }

    file.close();
    cout << endl;

    return 0;
}
