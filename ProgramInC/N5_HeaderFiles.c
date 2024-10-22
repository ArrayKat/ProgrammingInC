#include "head.h"

void mainHeaderFiles() {
    printf("hello world\n");
    printf("%d - %d = %d\n", 10, 5, Razn(10, 5));
    printf("%d + %d = %d\n", 10, 5, Summ(10, 5));
    printf("%d * %d = %d\n", 10, 5, Sqare(10, 5));
    printf("%d / %d = %d\n", 10, 5, Div(10, 5));
    char c1[] = "������ ";
    char c2[] = "���!";
    char* c3 = ConcatStr(c1, c2);
    printf("%s\n", c3);
    double Double = -123.67;
    printf("%f = %s\n", -123.67, ConvertDoubleToString(Double));
    char* Str = " -345.0980";
    printf("%s = %f", Str, ConvertStringToDouble(Str));
}

char* ConcatStr(char* str1, char* str2) {
    int n1=0, n2=0;
    while (str1[n1] != '\0') n1++;
    while (str2[n2] != '\0') n2++;
    char* str3 = malloc((n1 + n2) * sizeof(char));
    for (int i = 0; i < n1; i++) str3[i] = str1[i];
    for (int i = 0; i < n2; i++) str3[n1 + i] = str2[i];
    str3[n1 + n2] = '\0';
    return str3;
}
char* ConvertDoubleToString(double num) {
    // �������� �� ����
    if (num == 0.0) {
        char* str = malloc(2 * sizeof(char)); // ��� "0" � �������� �����������
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    // ���������� ���� �����
    int isNegative = num < 0;
    if (isNegative) num = -num;

    // �������� ����� � ������� �����
    long long intPart = (long long)num; // ����� �����
    double fracPart = num - intPart; // ������� �����

    // �������� ������ ��� ������������ ����� �����
    char* str = malloc(50 * sizeof(char)); // ���������� ��� ������� �������� � ������� �����

    // ������ ��� ������ � ������
    int i = 0;

    // ��������� ����� �����
    if (intPart == 0) {
        str[i++] = '0';
    }
    else {
        // ���������� ���� ����� ����� � �������� �������
        while (intPart != 0) {
            int ost = intPart % 10; // ��������� ��������� �����
            str[i++] = '0' + ost; // ����������� ����� � ������
            intPart /= 10; // ������� ��������� �����
        }
    }

    // ��������� ���� �����, ���� ����� �������������
    if (isNegative) {
        str[i++] = '-';
    }

    // ����������� ������ ��� ����������� ������� ����� �����
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }

    // ��������� ���������� �����
    str[i++] = '.';

    // ��������� ������� ����� (�� 6 ������ ����� �������)
    for (int j = 0; j < 6; j++) {
        fracPart *= 10;
        int digit = (int)fracPart;
        str[i++] = '0' + digit; // ����������� ����� � ������
        fracPart -= digit; // ������� ����� ����� �� �������
    }

    str[i] = '\0'; // ��������� ������

    return str;
}
double ConvertStringToDouble(const char* s) {
    double result = 0.0;
    double fraction = 1.0;
    int sign = 1;

    // ���������� �������
    while (*s == ' ') s++;

    // ��������� �����
    if (*s == '-') {
        sign = -1;
        s++;
    }
    else if (*s == '+') {
        s++;
    }

    // �������������� ����� �����
    while (*s >= '0' && *s <= '9') {
        result = result * 10.0 + (*s - '0'); // ��������� ��������
        s++;
    }

    // ��������� ������� �����
    if (*s == '.') {
        s++; // ���������� �����

        while (*s >= '0' && *s <= '9') {
            fraction *= 0.1; // ��������� �������� �� �������
            result += (*s - '0') * fraction; // ��������� � ����������
            s++;
        }
    }

    // ��������� ���������������� ����� (e ��� E)
    if (*s == 'e' || *s == 'E') {
        s++; // ���������� 'e' ��� 'E'
        int expSign = 1;

        if (*s == '-') {
            expSign = -1;
            s++;
        }
        else if (*s == '+') {
            s++;
        }

        int exponent = 0;
        while (*s >= '0' && *s <= '9') {
            exponent = exponent * 10 + (*s - '0'); // ��������� �������� ����������
            s++;
        }

        exponent *= expSign; // ��������� ���� ����������
        result *= pow(10, exponent); // �������� �� 10 � ������� exponent
    }

    return sign * result; // ���������� ��������� � ������ �����
}