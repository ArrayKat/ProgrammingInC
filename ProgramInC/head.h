#include <stdio.h>

//int N5_Razn(int a, int b);
//int N5_Summ(int a, int b);
//int N5_Sqare(int a, int b);
//int N5_Div(int a, int b);
//

int N5_Razn(int a, int b) {
    return a - b;
}
int N5_Summ(int a, int b) {
    return a + b;
}
int N5_Sqare(int a, int b) {
    return a * b;
}
int N5_Div(int a, int b) {
    if (b == 0) return 0;
    else return a / b;
}