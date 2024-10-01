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
void outputArr(int n, int* arr)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *arr + i);
    }
}
void N2_Zadanie1() {
    printf("\nЗадание 1\n");
    int a;
    printf("Введите значение пееменной а (int): ");
    scanf_s("%d", &a);
    int* b = &a;
    printf("a = %d\nВведите новое значение а ", *b);
    scanf_s("%d", &a);
    printf("Новое значение a = %d", *b);
}
void N2_Zadanie2() {
    const int size = 1000000;

    int* arr = malloc(1000000 * sizeof(int));
    for (int i = 0; i < size; i++) {
        *(arr + 1) = i;
    }
    free(arr);
}
void N2_Zadanie3() {
    printf("\nЗадание 3\n");
    printf("Введите размерность одномерного массива: ");
    int n;
    scanf_s("%d", &n);
    int* arr = createArr(n);//создание массива
    outputArr(n, arr); //вывод массива на экран
}
void N2_Zadanie4() {
    int n = 0;
    printf("\nЗадание 4\n");
    printf("Введите размерность треугольной матрицы, которую хотите получить: ");
    scanf_s("%d", &n);

    //выделили память под 2х мерный массив
    int** arr = calloc(n,sizeof(int*)); 
    for (int i = 0; i < n; i++) {
        //*(arr + 1) = (int*)calloc(i + 1, sizeof(int));
        //*(arr + 1) = calloc(i, sizeof(int));
        arr[i] = calloc(i, sizeof(int));
    }
    int num = 0;
    //Вывод треугольной матрицы
    printf("Треугольная матрица:\n");
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j <= i; j++) {
            **arr = num++;
            ++*arr;
        }
        *arr -= i;
        arr++;
    }
    arr -= n;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            printf("%d ", **arr);
            ++*arr;
        }
        *arr -= i;
        ++arr;
        printf("\n");
    }
    arr -= n;
}

void mainPointers() {
    int task;
    printf("\nВыберите задание:\n");
    printf("1. Редактирование и вывод значения целочисленной переменной при обращении к ней из консольного окна.\n");
    printf("2. Динамическое создание и удаление массива из одного миллиона элементов типа int.\n");
    printf("3. Функция для вывода на экран консоли массива (одномерного?) произвольной длины.\n");
    printf("4. Формирование треугольной матрицы.\n");
    printf("5. ??????? \n");
    printf("Введите номер задания (0-5): ");
    scanf_s("%d", &task);
    switch (task)
    {
    case 1: N2_Zadanie1(); break;
    case 2: N2_Zadanie2(); break;
    case 3: N2_Zadanie3(); break;
    case 4: N2_Zadanie4(); break;
    default:
        break;
    }
}