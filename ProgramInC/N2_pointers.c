#include "task.h"

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
void outputArr(int n, int* (*f)(int))
{
    int* arr = f(n);
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
    int* array = calloc(size, sizeof(int));
    //заполнение элементов массива
    for (int i = 0; i < size; i++)
    {
        *(array + i) = i;
    }
    free(array);
}
void N2_Zadanie3() {
    printf("\nЗадание 3\n");
    printf("Введите размерность одномерного массива: ");
    int n;
    scanf_s("%d", &n);
    int* (*c)(int);
    c = createArr;
    outputArr(n, c); //вывод массива на экран
   
}
void N2_Zadanie4() {
    int n = 0;
    printf("\nЗадание 4\n");
    printf("Введите размерность треугольной матрицы, которую хотите получить: ");
    scanf_s("%d", &n);
    int num = 0;
    //выделили память под 2х мерный массив
    int** arr = (int**)malloc(n*sizeof(int*));
    int** head = arr; //голова
    int* head2;
    for (int i = 0; i < n; i++) {
        *arr = (int*) malloc((i+1) * sizeof(int));
        head2 = *arr;
        for (int j = 0; j <= i; j++) {
            **arr = num++;
            (*arr)++;
        }
        *arr = head2; //голова
        arr++;
    }
    arr = head;
    
    //Вывод треугольной матрицы
    printf("Треугольная матрица:\n");
   
    for (int i = 0; i < n; i++)
    {
        head2 = *arr;//голова
        for (int j = 0; j <= i; j++)
        {
            printf("%d\t", **arr);
            (*arr)++;
        }
        printf("\n");
        *arr = head2;//голова
        arr++;
    }
    arr = head;

    for (int i = 0; i < n; i++) {
        free(**arr);
        (*arr)++;
    }
    free(arr);
}

void mainPointers() {
    int task;
    int flag=1;
    while (flag) {

        printf("\nВыберите задание:\n");
        printf("1. Редактирование и вывод значения целочисленной переменной при обращении к ней из консольного окна.\n");
        printf("2. Динамическое создание и удаление массива из одного миллиона элементов типа int.\n");
        printf("3. Функция для вывода на экран консоли массива (одномерного?) произвольной длины.\n");
        printf("4. Формирование треугольной матрицы.\n");
       
        printf("Введите номер задания (1-5) (0-выйти): ");
        scanf_s("%d", &task);
        switch (task)
        {
        case 0: flag=0; break;
        case 1: N2_Zadanie1(); break;
        case 2: N2_Zadanie2(); break;
        case 3: N2_Zadanie3(); break;
        case 4: N2_Zadanie4(); break;
        default:  printf("Неверный ввод. Выберите задания от 1 до 5. Используйте 0 для выхода.\n");
            break;
        }
    }
    
}