#include "task.h"

void main() {
    system("chcp 1251");
	int task;
	double a, b, c, d, e, f;
	printf("Выберите работу, которую хотите протестировать:\n");
	printf("0. Входной констроль.\n");
	printf("1. Указатели.\n");
	printf("2. Создание делегатов.\n");
	printf("3. Односвязные списки.\n");
	printf("4. Заголовочные файлы.\n");
	printf("5. Директивы препроцессора.\n");
	printf("6. Задание на файл. СИ.\n");
	printf("Введите номер задания (0-5): ");
	scanf("%d", &task);
	switch (task)
	{
	case 0: mainEntranceControl(); break;
	case 1: mainPointers(); break;
	case 2: mainDelegates(); break;
	case 3: mainSimplyConnectedLists(); break;
	case 4: mainHeaderFiles(); break;
	case 6: mainWorkFileInC(); break;
	default: printf("Неверный ввод. Попробуйте снова.\n"); break;
	}
	printf("\n");
}


