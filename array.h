//* arrays.h - Заголовочный файл для работы с массивами
//* Функции для работы с одномерными массивами double

#ifndef ARRAY_H
#define ARRAY_H

/**
 * Вычисление значения математической функции f(x) = |e^x - 2| + x^2
 * @param x аргумент функции
 * @return значение функции в точке x
*/
double func(double x);

/**
 * Заполнение массива значениями
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на заполненный массив
 */
double* full_elements(double* ptr_array, int n);

/**
 * Печать элементов массива
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return 0 в случае успешной обработки
 */
int put_elements(double* ptr_array, int n);

/**
 * Отбросить дробную часть у всех элементов массива
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return 0 в случае успешной обработки, -1 при ошибке
 */
double calc_elements(double* ptr_array, int n);

/**
 * Вычисление суммы элементов массива в диапазоне [begin, end]
 * @param ptr_array указатель на массив
 * @param begin начальный индекс (включительно)
 * @param end конечный индекс (включительно)
 * @return sum - сумма элементов
 */
double sum_elements(double* ptr_array, int begin, int end);

/**
 * Поиск элемента в массиве
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @param value искомый элемент
 * @return индекс найденного элемента или -1 если не найден
 */
int find_element(double* ptr_array, int n, double value);

/**
 * Поиск порядкового номера максимального элемента, который меньше заданного значения A
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @param A заданное значение
 * @return индекс найденного элемента или -1 если нет элементов меньше A
 */
int find_max_below_A(double* ptr_array, int n, double A);

/**
 * Заполнение массива случайными числами в заданном диапазоне
 * @param ptr_array указатель на массив для заполнения
 * @param n размер массива
 * @param min минимальное значение
 * @param max максимальное значение
 * @return указатель на заполненный массив
 */
double* fill_random(double* ptr_array, int n, double min, double max);

/**
 * Удаление элементов меньших среднего арифметического
 * @param ptr_arr указатель на массив
 * @param size размер массива
 * @return новый размер массива после удаления
 */
int remove_below_average(double* ptr_arr, int size);

/**
 * Вставка числа -999 перед первым отрицательным элементом массива
 * @param ptr_arr указатель на массив
 * @param size указатель на размер массива
 * @return указатель на измененный массив
 */
double* insert_before_first_negative(double* ptr_arr, int* size);

/**
 * Поиск минимального элемента в массиве
 * @param arr массив
 * @param size размер массива
 * @return минимальное значение
 */
double find_min_value(const double* arr, int size);

/**
 * Подсчет элементов в массиве, исключая заданное значение
 * @param arr массив
 * @param size размер массива
 * @param exclude_value значение для исключения
 * @return количество элементов, не равных exclude_value
 */
int count_elements_excluding(const double* arr, int size, double exclude_value);

/**
 * Копирование элементов из исходного массива в целевой, исключая заданное значение
 * @param src исходный массив
 * @param src_size размер исходного массива
 * @param dest целевой массив
 * @param dest_index текущий индекс в целевом массиве
 * @param exclude_value значение для исключения
 * @return новый индекс в целевом массиве
 */
int copy_excluding_value(const double* src, int src_size, double* dest, int dest_index, double exclude_value);

/**
 * Объединение массивов A, B, C в массив D с исключением минимальных значений
 * @param a массив A
 * @param size_a размер массива A
 * @param b массив B
 * @param size_b размер массива B
 * @param c массив C
 * @param size_c размер массива C
 * @param result_size указатель на размер массива D
 * @return указатель на полученный массив
 */
double* arrays_D_without_min(const double* a, int size_a, const double* b, int size_b, const double* c, int size_c, int* result_size);

/**
 * Сортировка методом пузырька
 * @param ptarr указатель на массив
 * @param n размер массива
 */
void sort_bubble(double* ptrarr, int n);

/**
 * Сортировка методом шейкера
 * @param ptr_array указатель на массив
 * @param n размер массива
 */
void sort_kokteil(double* ptrarr, int n);

/**
 * Сортировка массива методом выбора
 * @param ptarr указатель на массив
 * @param n размер массива
 */
void sort_select(double* ptrarr, int n);

/**
 * Сортировка методом вставок
 * @param ptr_array указатель на массив
 * @param n размер массива
 */
void sort_insert(double* ptrarr, int n);

#endif