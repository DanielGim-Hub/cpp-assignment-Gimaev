#include <hw01.h>

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int sum_of_digits(int num) {
    return (num / 10) + (num % 10);
}

int hw01(int start, int end) {
    // Проверка, что start и end — двузначные числа
    if (start < 10 || start > 99 || end < 10 || end > 99) {
        return -1;
    }

    // Перестановка значений, если start больше end
    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }


    int sum = 0;
    for (int i = start; i <= end; ++i) {
        if (is_prime(i)) {
            sum += sum_of_digits(i);
        }
    }

    return sum;
}