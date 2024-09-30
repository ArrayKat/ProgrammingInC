#include "task.h"
#include <stdio.h>

// Функция для редактирования значения переменной

int* createArr(int n)
{
    if (n <= 0) return 0;
    //выделение памяти
    int* array = calloc(n, sizeof(int));
    //заполнение элементов массива
    for (int i = 0; i < n; i++)
    {
        *(array + i) = i;
    }
    return array;
}
void output(int n, int* arr)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *arr + i);
    }
}
void Zadanie1() {
    printf("\nЗадание 1\n");
    int a;
    printf("Введите значение пееменной а (int): ");
    scanf_s("%d", &a);
    int* b = &a;
    printf("a = %d\nВведите новое значение а ", *b);
    scanf_s("%d", &a);
    printf("Новое значение a = %d", *b);
}
void Zadanie2() {
    const int size = 1000000;

    int* arr = malloc(1000000 * sizeof(int));
    for (int i = 0; i < size; i++) {
        *(arr + 1) = i;
    }
    free(arr);
}
void Zadanie3() {
    printf("\nЗадание 3\n");
    printf("Введите размерность одномерного массива: ");
    int n;
    scanf_s("%d", &n);
    int* arr = createArr(n);//создание массива
    output(n, arr); //вывод массива на экран
}

void mainPointers() {
    printf("\nВыберите задание:\n");
    printf("1. Редактирование и вывод значения целочисленной переменной при обращении к ней из консольного окна.\n");
    printf("2. Динамическое создание и удаление массива из одного миллиона элементов типа int.\n");
    printf("3. Функция для вывода на экран консоли массива произвольной длины.\n");
    printf("4. Формирование треугольной матрицы.\n");
    printf("5. ??????? \n");
    printf("Введите номер задания (0-5): ");
}