#include <hw02.h>
#include <iostream>
#include <string>
using namespace std;

string hw02(string input_str) {
    string result;
    // Отбираем первый символ строки
    for (size_t i = 0; i < input_str.length(); i++) {
        char simvol = input_str[i];
        bool simvol_found = false; // флаг чтобы понять встречался или нет
        // Проверяем встречался ли символ ранее в result
        for (size_t j = 0; j < result.length(); j++) {
            if (result[j] == simvol) {
                simvol_found = true; // флаг что символ уже встречался
                break;
            }
        }

        // Добавляем его если не встречался
        if (!simvol_found) {
            result += simvol;
        }
    }
    return result;
}