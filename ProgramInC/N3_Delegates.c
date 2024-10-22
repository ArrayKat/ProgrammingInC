#include "task.h"

typedef int (*fun)(int, int);
typedef fun* del;


int Razn(int a, int b) {
    return a - b;
}
int Summ(int a, int b) {
    return a + b;
}
int Sqare(int a, int b) {
    return a * b;
}
int Div(int a, int b) {
    if (b == 0) return 0;
    else return a / b;
}

del AddDelegate(del deleg, fun operation) {
    size_t size = _msize(deleg) / sizeof(fun);
    deleg = realloc(deleg, (size + 1) * sizeof(fun));
    deleg[size] = operation;
    return deleg;
}

void PrintAllFunctions(del deleg, int a, int b) {
    int size = _msize(deleg)/sizeof(fun);
    for (int i = 0; i < size; i++) {
        printf("%d. функция c переданными аргумкентами %d и %d = %d\n",i,a,b, deleg[i](a,b));
    }
    printf("\n");
}

del DeleteFunctionsFromIndex(del deleg, int index) {
    int size = _msize(deleg) / sizeof(fun);
    for (int i = 0; i < size; i++) {
        if (i >= index) {
            deleg[i] = deleg[i + 1];
        }
    }
    deleg = realloc(deleg,(size-1)* sizeof(fun));
}

del DeleteDuplicate(del deleg) {
    int size = _msize(deleg) / sizeof(fun);
    del newDeleg = malloc(1 * sizeof(fun));
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (deleg[i] == deleg[j]) {
                for (int k = j; k < size - 1; k++) {
                    deleg[k] = deleg[k + 1];
                }
                size--;
                j--;
            }
        }
    }
    deleg = realloc(deleg, size * sizeof(fun));
}

void mainDelegates() {
    fun function;

    printf("Начальные функции: \n");
    del delegate = malloc(3 * sizeof(fun));
    delegate[0] = Razn;
    delegate[1] = Summ;
    delegate[2] = Div;
    PrintAllFunctions(delegate, 10,5);

    printf("Добавление умножения чисел: \n");
    delegate = AddDelegate(delegate, Sqare);
    PrintAllFunctions(delegate, 10, 5);

    printf("Удаление делегата с индексом 2: \n");
    delegate = DeleteFunctionsFromIndex(delegate,2);
    PrintAllFunctions(delegate, 10, 5);

    printf("Добавление дубликатов функций в делегат: \n");
    delegate = AddDelegate(delegate, Sqare);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Sqare);
    delegate = AddDelegate(delegate, Sqare);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Sqare);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Summ);
    delegate = AddDelegate(delegate, Razn);

    PrintAllFunctions(delegate, 10, 5);

    printf("Удаление дубликатов функций из делегата: \n");
    delegate = DeleteDuplicate(delegate);
    PrintAllFunctions(delegate, 10, 5);
}