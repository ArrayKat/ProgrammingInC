#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>
#include "task.h"

void main() {
    system("chcp 1251");
	int task;
	double a, b, c, d, e, f;
	printf("�������� ������, ������� ������ ��������������:\n");
	printf("0. ������� ���������.\n");
	printf("1. ���������.\n");
	printf("2. �������� ���������.\n");
	printf("3. ����������� ������.\n");
	printf("4. ������������ �����.\n");
	printf("5. ��������� �������������.\n");
	printf("������� ����� ������� (0-5): ");
	scanf("%d", &task);
	switch (task)
	{
	case 0: mainEntranceControl(); break;
	case 1: mainPointers(); break;
	default:
		break;
	}
	printf("\n");
}


