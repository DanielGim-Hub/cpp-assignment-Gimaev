#include <hw04.h>

std::size_t hw04(const int* input_array, std::size_t elem_count)
{
    if (input_array == nullptr || elem_count == 0)
        return 0;

    std::size_t sum = 0;
    int* out_data = nullptr; // Указатель на массив
    std::size_t out_size = 0;

    for (std::size_t i = 0; i < elem_count; ++i)
    {
        if (input_array[i] < 0)
            break;

        // Увеличиваем размер массива
        int* new_out_data = new int[out_size + 1];
        
        // Копируем старые данные
        for (std::size_t j = 0; j < out_size; ++j)
        {
            new_out_data[j] = out_data[j];
        }

        // Добавляем новый элемент
        new_out_data[out_size] = input_array[i];
        ++out_size;

        // Освобождаем старую память
        delete[] out_data;

        // Указатель на новый массив
        out_data = new_out_data;
    }

    // Подсчёт суммы элементов в out_data
    for (std::size_t i = 0; i < out_size; ++i)
    {
        sum += out_data[i];
    }

    // Освобождаем память
    delete[] out_data;

    return sum;
}

