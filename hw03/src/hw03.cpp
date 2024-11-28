#include <hw03.h>
#include <iostream>
#include <cstring> 


void hw03(char* str, const char* pattern) {
    // проверяем на нулевые указатали
    if (str == nullptr || pattern == nullptr) {
        return;
    }

    // проверка что строка пустая
    // если так, то просто возвращаем
    if (*str == '\0') {
        return;
    }

    // определение длины подстроки
    size_t patternLen = std::strlen(pattern);

    // если подстрока равен 0, то ничего не делаем
    if (patternLen == 0) {
        return;
    }

    // найдем первое вхождение pattern в строку
    char* pos = std::strstr(str, pattern);

    // подстрока не найдена так же ничего не делаем
    if (pos == nullptr) {
        return;
    }

    // длина строки
    size_t strLen = std::strlen(str);

    // сдвигаем оставшуюся часть строки влево, чтобы удалить подстроку
    std::memmove(pos, pos + patternLen, strLen - (pos - str) - patternLen + 1);
}
