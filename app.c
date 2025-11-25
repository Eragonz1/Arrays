#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

#define SIZE 100

int task14(int size);
int task16(int size);
int task16DZ();

int main() {
    puts("Лабораторные работы 11, 14, 16, 19, 25: Работа с массивами ===\n");

    int size;
    puts("Укажите размер массива");
    scanf("%d", &size);

    task14(size); // для всех заданий лаб. 14

    task16(size);// для всех заданий лаб. 16

    task16DZ();// для ДЗ лаб. 16

    return 0;
}


int task14(int size) {

    double array[SIZE];

    printf("\n---- Лаба 14 ----\n");

    // Задание 1. Заполнение массива

    full_elements(array, size);
    printf("\nЭлементы массива:\n");
    put_elements(array, size);

    // Задание 2. Преобразование массива

    calc_elements(array, size);
    printf("\nЭлементы массива после обработки:\n");
    put_elements(array, size);

    // Задание 2.1 вычисление суммы
    int begin, end;
    printf("\n---- Сумма элементов ----\n");
    printf("Введите начальный индекс: ");
    scanf("%d", &begin);
    printf("Введите конечный индекс: ");
    scanf("%d", &end);

    if (begin < 0 || end >= size || begin > end) {
        printf("Ошибка: некорректные индексы. Допустимый диапазон от 0 до %d.\n", size - 1);
    }
    else {
        double sum_result = sum_elements(array, begin, end);
        printf("Сумма элементов от индекса %d до %d включительно: %.2f\n", begin, end, sum_result);
    }

    // Задание 2.2 - поиск
    double search_val;
    printf("\n---- Поиск элемента ----\n");
    printf("Введите значение для поиска: ");
    scanf("%lf", &search_val);
    int index = find_element(array, size, search_val);
    if (index != -1) {
        printf("Элемент %.2f найден на позиции %d (индекс %d)\n", search_val, index + 1, index);
    }
    else {
        printf("Элемент %.2f не найден в массиве.\n", search_val);
    }

    // ДЗ - поиск максимального элемента меньше A
    double A;
    printf("\n---- Поиск максимального элемента меньше A ----\n");
    printf("Введите значение A: ");
    scanf("%lf", &A);
    int max_index = find_max_below_A(array, size, A);
    if (max_index != -1) {
        printf("Максимальный элемент меньше %.2f - %.2f с порядковым номером %d (индекс %d) \n", A, array[max_index], max_index + 1, max_index);
    }
    else {
        printf("Элементов меньше не найдено в массиве.\n", A);
    }

    return 0;
}

int task16(int size) {

    printf("\n---- Лаба 16 ----\n");

    //Задание 1

    double* ptr_array;
    double* ptr_new;

    ptr_array = (double*)malloc(size * sizeof(double));
    ptr_new = (double*)malloc(size * sizeof(double));

 
    if (ptr_array == NULL & ptr_new == NULL) {

        puts("error");

        return -1;

    }

    full_elements(ptr_array, size);

    for (int i = 0; i < size; i++) {
        ptr_new[i] = ptr_array[i];
    }

    calc_elements(ptr_new, size);

    printf("\n---Элементы динамичоского массива---\n");
    put_elements(ptr_array, size);

    printf("\n---Элементы динамического массива после обработки---\n");
    put_elements(ptr_new, size);

    free(ptr_array);
    free(ptr_new);

    //Задание 2
    double* ptr_arr;
    ptr_arr = (double*)malloc(size * sizeof(double));

    if (ptr_arr == NULL) {
        puts("error");
        return -1;
    }

    srand(time(NULL));
    fill_random(ptr_arr, size, -1.0, 1.0);

    printf("\n--- Массив со случайными числами от -1 до 1 ---\n");
    put_elements(ptr_arr, size);

    int new_size = remove_below_average(ptr_arr, size);

    printf("\n--- Массив после удаления элементов меньших среднего ---\n");
    printf("Новый размер массива: %d\n", new_size);
    put_elements(ptr_arr, new_size);

    free(ptr_arr);

    //Задание 3
    double* ptr_arr3;
    ptr_arr3 = (double*)malloc(size * sizeof(double));

    if (ptr_arr3 == NULL) {
        puts("error");
        return -1;
    }

    srand(time(NULL));
    fill_random(ptr_arr3, size, -10.0, 10.0);

    printf("\n--- Массив для вставки -999 ---\n");
    put_elements(ptr_arr3, size);

    ptr_arr3 = insert_before_first_negative(ptr_arr3, &size);

    printf("\n--- Массив после вставки -999 ---\n");
    put_elements(ptr_arr3, size);

    free(ptr_arr3);

    return 0;
}

int task16DZ() {

    printf("\n---- Лаба 16 ДЗ ----\n");

    srand(time(NULL));
    int size_a = rand() % 26 + 5;
    int size_b = rand() % 26 + 5;
    int size_c = rand() % 26 + 5;

    double* ptr_a;
    double* ptr_b;
    double* ptr_c;

    ptr_a = (double*)malloc(size_a * sizeof(double));
    ptr_b = (double*)malloc(size_b * sizeof(double));
    ptr_c = (double*)malloc(size_c * sizeof(double));

    if (ptr_a == NULL || ptr_b == NULL || ptr_c == NULL) {
        puts("error");
        return -1;
    }

    fill_random(ptr_a, size_a, 10.0, 50.0);
    fill_random(ptr_b, size_b, 10.0, 50.0);
    fill_random(ptr_c, size_c, 10.0, 50.0);

    printf("\n--- Массив A (%d элементов) ---\n", size_a);
    put_elements(ptr_a, size_a);
    printf("\n--- Массив B (%d элементов) ---\n", size_b);
    put_elements(ptr_b, size_b);
    printf("\n--- Массив C (%d элементов) ---\n", size_c);
    put_elements(ptr_c, size_c);

    int size_d;
    double* ptr_d = arrays_D_without_min(ptr_a, size_a, ptr_b, size_b, ptr_c, size_c, &size_d);

    if (ptr_d != NULL && size_d > 0) {
        printf("\n--- Массив D (%d элементов) ---\n", size_d);
        put_elements(ptr_d, size_d);
        free(ptr_d);
    }
    else {
        printf("\nerror");
    }

    free(ptr_a);
    free(ptr_b);
    free(ptr_c);

    return 0;
}