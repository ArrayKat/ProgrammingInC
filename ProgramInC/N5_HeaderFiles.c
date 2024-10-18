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
    char* str = ConvertIntToString(-123);
    printf("%d = %s\n", 123, str);
    char* Int = " -345";
    printf("%s = %d", Int, ConvertStringToInt(Int));
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
char* ConvertIntToString(int n) {
    // �������� �� ����
    if (n == 0) {
        char* str = malloc(2 * sizeof(char)); // ��� "0" � �������� �����������
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    // ���������� ���� �����
    int isNegative = n < 0;
    if (isNegative) n = -n;

    // �������� ������ ��� ������������ ����� �����
    char* str = malloc(12 * sizeof(char)); // 10 ���� - ������������ �������� 32-������� int + ���� "-" + '\0' = 12
    
    // ���������� ���� � �������� �������
    int i = 0;
    while (n != 0) {
        int ost = n % 10; // ��������� ��������� �����
        str[i] = '0' + ost; // ����������� ����� � ������
        n /= 10; // ������� ��������� �����
        i++;
    }

    // ��������� ���� �����, ���� ����� �������������
    if (isNegative) {
        str[i] = '-';
        i++;
    }

    str[i] = '\0';

    // ����������� ������ ��� ����������� �������
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }

    return str;
}
int ConvertStringToInt(const char* s) {
    int result = 0; 
    int sign = 1;

    // ���������� �������
    while (*s == ' ') s++;

    // ��������� �����
    if (*s == '-') {
        sign = -1;
        s++;
    }
    else if (*s == '+') s++;

    // �������������� �������� � �����
    while (*s >= '0' && *s <= '9') {
        result = result * 10 + (*s - '0'); // ��������� ��������
        s++;
    }
    return sign * result;
}