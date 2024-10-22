#include "head.h"

void mainHeaderFiles() {
    printf("hello world\n");
    printf("%d - %d = %d\n", 10, 5, Razn(10, 5));
    printf("%d + %d = %d\n", 10, 5, Summ(10, 5));
    printf("%d * %d = %d\n", 10, 5, Sqare(10, 5));
    printf("%d / %d = %d\n", 10, 5, Div(10, 5));
    char c1[] = "Привет ";
    char c2[] = "мир!";
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
    // Проверка на ноль
    if (num == 0.0) {
        char* str = malloc(2 * sizeof(char)); // Для "0" и нулевого терминатора
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    // Определяем знак числа
    int isNegative = num < 0;
    if (isNegative) num = -num;

    // Отделяем целую и дробную части
    long long intPart = (long long)num; // Целая часть
    double fracPart = num - intPart; // Дробная часть

    // Выделяем память для максимальной длины числа
    char* str = malloc(50 * sizeof(char)); // Достаточно для больших значений и дробной части

    // Индекс для записи в строку
    int i = 0;

    // Обработка целой части
    if (intPart == 0) {
        str[i++] = '0';
    }
    else {
        // Извлечение цифр целой части в обратном порядке
        while (intPart != 0) {
            int ost = intPart % 10; // Извлекаем последнюю цифру
            str[i++] = '0' + ost; // Преобразуем цифру в символ
            intPart /= 10; // Удаляем последнюю цифру
        }
    }

    // Добавляем знак минус, если число отрицательное
    if (isNegative) {
        str[i++] = '-';
    }

    // Инвертируем строку для правильного порядка целой части
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }

    // Добавляем десятичную точку
    str[i++] = '.';

    // Обработка дробной части (до 6 знаков после запятой)
    for (int j = 0; j < 6; j++) {
        fracPart *= 10;
        int digit = (int)fracPart;
        str[i++] = '0' + digit; // Преобразуем цифру в символ
        fracPart -= digit; // Удаляем целую часть из дробной
    }

    str[i] = '\0'; // Завершаем строку

    return str;
}
double ConvertStringToDouble(const char* s) {
    double result = 0.0;
    double fraction = 1.0;
    int sign = 1;

    // Пропускаем пробелы
    while (*s == ' ') s++;

    // Обработка знака
    if (*s == '-') {
        sign = -1;
        s++;
    }
    else if (*s == '+') {
        s++;
    }

    // Преобразование целой части
    while (*s >= '0' && *s <= '9') {
        result = result * 10.0 + (*s - '0'); // Вычисляем значение
        s++;
    }

    // Обработка дробной части
    if (*s == '.') {
        s++; // Пропускаем точку

        while (*s >= '0' && *s <= '9') {
            fraction *= 0.1; // Уменьшаем значение на порядок
            result += (*s - '0') * fraction; // Добавляем к результату
            s++;
        }
    }

    // Обработка экспоненциальной части (e или E)
    if (*s == 'e' || *s == 'E') {
        s++; // Пропускаем 'e' или 'E'
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
            exponent = exponent * 10 + (*s - '0'); // Вычисляем значение экспоненты
            s++;
        }

        exponent *= expSign; // Учитываем знак экспоненты
        result *= pow(10, exponent); // Умножаем на 10 в степени exponent
    }

    return sign * result; // Возвращаем результат с учетом знака
}