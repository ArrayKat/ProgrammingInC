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
void output(int n, int* arr)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *arr + i);
    }
}
void Zadanie1() {
    printf("\n������� 1\n");
    int a;
    printf("������� �������� ��������� � (int): ");
    scanf_s("%d", &a);
    int* b = &a;
    printf("a = %d\n������� ����� �������� � ", *b);
    scanf_s("%d", &a);
    printf("����� �������� a = %d", *b);
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
    printf("\n������� 3\n");
    printf("������� ����������� ����������� �������: ");
    int n;
    scanf_s("%d", &n);
    int* arr = createArr(n);//�������� �������
    output(n, arr); //����� ������� �� �����
}

void mainPointers() {
    printf("\n�������� �������:\n");
    printf("1. �������������� � ����� �������� ������������� ���������� ��� ��������� � ��� �� ����������� ����.\n");
    printf("2. ������������ �������� � �������� ������� �� ������ �������� ��������� ���� int.\n");
    printf("3. ������� ��� ������ �� ����� ������� ������� ������������ �����.\n");
    printf("4. ������������ ����������� �������.\n");
    printf("5. ??????? \n");
    printf("������� ����� ������� (0-5): ");
}