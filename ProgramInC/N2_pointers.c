#include "task.h"
#include <stdio.h>

// ������� ��� �������������� �������� ����������

int* createArr(int n)
{
    if (n <= 0) return 0;
    //��������� ������
    int* array = calloc(n, sizeof(int));
    //���������� ��������� �������
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
    printf("\n������� 1\n");
    int a;
    printf("������� �������� ��������� � (int): ");
    scanf_s("%d", &a);
    int* b = &a;
    printf("a = %d\n������� ����� �������� � ", *b);
    scanf_s("%d", &a);
    printf("����� �������� a = %d", *b);
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
    printf("\n������� 3\n");
    printf("������� ����������� ����������� �������: ");
    int n;
    scanf_s("%d", &n);
    int* arr = createArr(n);//�������� �������
    outputArr(n, arr); //����� ������� �� �����
}
void N2_Zadanie4() {
    int n = 0;
    printf("\n������� 4\n");
    printf("������� ����������� ����������� �������, ������� ������ ��������: ");
    scanf_s("%d", &n);

    //�������� ������ ��� 2� ������ ������
    int** arr = calloc(n,sizeof(int*)); 
    for (int i = 0; i < n; i++) {
        //*(arr + 1) = (int*)calloc(i + 1, sizeof(int));
        //*(arr + 1) = calloc(i, sizeof(int));
        arr[i] = calloc(i, sizeof(int));
    }
    int num = 0;
    //����� ����������� �������
    printf("����������� �������:\n");
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
    printf("\n�������� �������:\n");
    printf("1. �������������� � ����� �������� ������������� ���������� ��� ��������� � ��� �� ����������� ����.\n");
    printf("2. ������������ �������� � �������� ������� �� ������ �������� ��������� ���� int.\n");
    printf("3. ������� ��� ������ �� ����� ������� ������� (�����������?) ������������ �����.\n");
    printf("4. ������������ ����������� �������.\n");
    printf("5. ??????? \n");
    printf("������� ����� ������� (0-5): ");
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