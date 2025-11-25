#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"

// Функция из лаб.8
double func(double x) {
    return fabs(exp(x) - 2) + pow(x, 2);
}


// заполнение массива значениями
double* full_elements(double* ptr_array, int n) {

    double start = 1.0;
    double end = 3.0;
    double step = (end - start) / (n - 1); 
    double x = start;

    for (int i = 0; i < n; i++) {
        ptr_array[i] = func(x);
        x += step;
    }

    return ptr_array;
}


// печать элементов массива
int put_elements(double* ptr_array, int n) {
    if (n <= 0 || ptr_array == NULL) {
        printf("Ошибка: пустой или недопустимый массив.\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        printf("%.2f\n", ptr_array[i]);
    }

    return 0;
}


// отбросить дробную часть у всех элементов массива
double calc_elements(double* ptr_array, int n) {
    if (n <= 0 || ptr_array == NULL) {
        printf("Ошибка: невозможно обработать пустой массив.\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        ptr_array[i] = (int)ptr_array[i];
    }

    return 0;
}


// функция вычисления суммы элементов от begin до end включительно
double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}


// функцию поиска элемента равного а
int find_element(double* ptr_array, int n, double value) {
    if (n <= 0 || ptr_array == NULL) return -1;

    for (int i = 0; i < n; i++) {
        if (fabs(ptr_array[i] - value) < 1e-6) {
            return i;
        }
    }
    return -1;
}


// 14 лаба. Поиск порядкового номера максимального значения элементов, меньше заданного значения А
int find_max_below_A(double* ptr_array, int n, double A) {
    if (n <= 0 || ptr_array == NULL) {
        return -1;
    }

    int found_index = -1;

    for (int i = 0; i < n; i++) {
        if (ptr_array[i] < A) {
            if (found_index == -1 || ptr_array[i] > ptr_array[found_index]) {
                found_index = i;
            }
        }
    }

    return found_index;
}

// Заполнение массива случайными числами в заданном диапазоне
double* fill_random(double* ptr_array, int n, double min, double max) {
    if (ptr_array == NULL || n <= 0 || min >= max) {
        return ptr_array;
    }

    double range = max - min;

    for (int i = 0; i < n; i++) {
        ptr_array[i] = (double)rand() / RAND_MAX * range + min;
    }

    return ptr_array;
}

//  Удаление элемента по индексу сдвигая все элементы справа на одну позицию влево
int delete_k(double* ptr_arr, int size, int k) {
    int n = size - 1;

    for (int i = k; i < (size - 1); i++) ptr_arr[i] = ptr_arr[i + 1];

    return n;
}

// Удаление элементов меньших среднего арифметического
int remove_below_average(double* ptr_arr, int size) {
    if (ptr_arr == NULL || size <= 0) {
        return 0;
    }

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += ptr_arr[i];
    }
    double average = sum / size;

    printf("Среднее арифметическое: %.2f\n", average);

    int new_size = size;
    int i = 0;
    while (i < new_size) {
        if (ptr_arr[i] < average) {
            new_size = delete_k(ptr_arr, new_size, i);
        }
        else {
            i++;
        }
    }

    return new_size;
}

// Функция для вставки элемента в массив
double* insert(double* ptr_arr, int* size, int index, double num) {
    /*
    ptr_arr - адрес массива
    size - число элементов
    index - индекс добавляемого элемента
    num - вставляемое значение
    */
    int size_n = (*size) + 1;
    if (ptr_arr == NULL) return NULL;
    double* ptr_arr_n = (double*)realloc(ptr_arr, size_n * sizeof(double));
    if (ptr_arr_n == NULL) return ptr_arr;
    ptr_arr = ptr_arr_n;
    for (int i = size_n - 1; i > index; i--)
        ptr_arr[i] = ptr_arr[i - 1];
    ptr_arr[index] = num;
    *size = size_n;
    return ptr_arr;
}

// Вставка -999 перед первым отрицательным числом
double* insert_before_first_negative(double* ptr_arr, int* size) {
    if (ptr_arr == NULL || size == NULL || *size <= 0) {
        return ptr_arr;
    }

    int first_negative_index = -1;
    for (int i = 0; i < *size; i++) {
        if (ptr_arr[i] < 0) {
            first_negative_index = i;
            break;
        }
    }

    if (first_negative_index != -1) {
        ptr_arr = insert(ptr_arr, size, first_negative_index, -999.0);
        printf("Вставлено -999 перед первым отрицательным элементом (индекс %d)\n", first_negative_index);
    }
    else {
        printf("Отрицательные элементы не найдены в массиве\n");
    }

    return ptr_arr;
}

// Поиск минимального элемента в массиве
double find_min_value(const double* arr, int size) {
    if (arr == NULL || size <= 0) return 0.0;

    double min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Подсчет элементов в массиве, исключая заданное значение
int count_elements_excluding(const double* arr, int size, double exclude_value) {
    if (arr == NULL || size <= 0) return 0;

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (fabs(arr[i] - exclude_value) > 1e-6) { 
            count++;
        }
    }
    return count;
}

// Копирование элементов из исходного массива в целевой, исключая заданное значение
int copy_excluding_value(const double* src, int src_size, double* dest, int dest_index, double exclude_value) {
    if (src == NULL || dest == NULL) return dest_index;

    for (int i = 0; i < src_size; i++) {
        if (fabs(src[i] - exclude_value) > 1e-6) {
            dest[dest_index++] = src[i];
        }
    }
    return dest_index;
}

// Объединение массивов A, B, C в массив D с исключением минимальных значений
double* arrays_D_without_min(const double* a, int size_a, const double* b, int size_b, const double* c, int size_c, int* result_size) {
    if (a == NULL || b == NULL || c == NULL || result_size == NULL) {
        return NULL;
    }

    double min_a = find_min_value(a, size_a);
    double min_b = find_min_value(b, size_b);
    double min_c = find_min_value(c, size_c);

    int total_size = count_elements_excluding(a, size_a, min_a) +
        count_elements_excluding(b, size_b, min_b) +
        count_elements_excluding(c, size_c, min_c);

    if (total_size == 0) {
        *result_size = 0;
        return NULL;
    }

    double* array_d = (double*)malloc(total_size * sizeof(double));
    if (array_d == NULL) {
        *result_size = 0;
        return NULL;
    }

    int current_index = 0;
    current_index = copy_excluding_value(a, size_a, array_d, current_index, min_a);
    current_index = copy_excluding_value(b, size_b, array_d, current_index, min_b);
    current_index = copy_excluding_value(c, size_c, array_d, current_index, min_c);

    *result_size = total_size;

    return array_d;
}