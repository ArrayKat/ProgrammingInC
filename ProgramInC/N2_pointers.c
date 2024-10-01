#include "task.h"

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
void outputArr(int n, int* (*f)(int))
{
    int* arr = f(n);
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
    int* array = calloc(size, sizeof(int));
    //���������� ��������� �������
    for (int i = 0; i < size; i++)
    {
        *(array + i) = i;
    }
    free(array);
}
void N2_Zadanie3() {
    printf("\n������� 3\n");
    printf("������� ����������� ����������� �������: ");
    int n;
    scanf_s("%d", &n);
    int* (*c)(int);
    c = createArr;
    outputArr(n, c); //����� ������� �� �����
   
}
void N2_Zadanie4() {
    int n = 0;
    printf("\n������� 4\n");
    printf("������� ����������� ����������� �������, ������� ������ ��������: ");
    scanf_s("%d", &n);
    int num = 0;
    //�������� ������ ��� 2� ������ ������
    int** arr = (int**)malloc(n*sizeof(int*));
    int** head = arr; //������
    int* head2;
    for (int i = 0; i < n; i++) {
        *arr = (int*) malloc((i+1) * sizeof(int));
        head2 = *arr;
        for (int j = 0; j <= i; j++) {
            **arr = num++;
            (*arr)++;
        }
        *arr = head2; //������
        arr++;
    }
    arr = head;
    
    //����� ����������� �������
    printf("����������� �������:\n");
   
    for (int i = 0; i < n; i++)
    {
        head2 = *arr;//������
        for (int j = 0; j <= i; j++)
        {
            printf("%d\t", **arr);
            (*arr)++;
        }
        printf("\n");
        *arr = head2;//������
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

        printf("\n�������� �������:\n");
        printf("1. �������������� � ����� �������� ������������� ���������� ��� ��������� � ��� �� ����������� ����.\n");
        printf("2. ������������ �������� � �������� ������� �� ������ �������� ��������� ���� int.\n");
        printf("3. ������� ��� ������ �� ����� ������� ������� (�����������?) ������������ �����.\n");
        printf("4. ������������ ����������� �������.\n");
       
        printf("������� ����� ������� (1-5) (0-�����): ");
        scanf_s("%d", &task);
        switch (task)
        {
        case 0: flag=0; break;
        case 1: N2_Zadanie1(); break;
        case 2: N2_Zadanie2(); break;
        case 3: N2_Zadanie3(); break;
        case 4: N2_Zadanie4(); break;
        default:  printf("�������� ����. �������� ������� �� 1 �� 5. ����������� 0 ��� ������.\n");
            break;
        }
    }
    
}