#include "task.h"

/// <summary>
/// 1. ������� ��� ������� ����������� ���������
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
/// <param name="countX">���������� ������</param>
/// <param name="x1">������ ������</param>
/// <param name="x2">������ ������</param>
void Z1_QuadraticEquation(double a, double b, double c, double* countX, double* x1, double* x2) {

	double discriminant = b * b - 4 * a * c;
	if (discriminant > 0) {
		//*�1 - ������������� ����������: ��� ����, ��� �� ������ �������� ����� �� ���������, �� ������������������� ����������
		*x1 = (-b + sqrt(discriminant)) / (2 * a);
		*x2 = (-b - sqrt(discriminant)) / (2 * a);
		*countX = 2;
	}
	else if (discriminant == 0) {
		*countX = 1;
		*x1 = -b / (2 * a);
	}
	else {
		*countX = 0;
	}
}
/// <summary>
/// 2. ������� ��� ���������� ������� 2� �������� ���������
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
/// <param name="d"></param>
/// <param name="e"></param>
/// <param name="f"></param>
/// <param name="countX"></param>
/// <param name="x1"></param>
/// <param name="x2"></param>
void Z2_SolveLinearEquations(double a, double b, double c, double d, double e, double f, double* countX, double* x1, double* x2) {
	//a = a1, b = b1, c = c1, d = a2, e = b2, f = c2
	double determinant = a * e - d * b; //a1 * b2 - a2 * b1
	if (determinant == 0) {

		*countX = 0;
	}
	else {
		*x1 = (c * e - f * b) / determinant;
		*x2 = (a * f - d * c) / determinant;
		*countX = 2;
	}
}
/// <summary>
/// 3. ������� ��� ���������� ����������
/// </summary>
/// <param name="n">�����</param>
/// <returns>�������� ���������� �����</returns>
unsigned long long Z3_Factorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	unsigned long long result = 1;
	for (int i = 2; i <= n; i++) {
		result *= i;
	}
	return result;
}
/// <summary>
/// ���� �������� ��� 3� �����
/// </summary>
/// <param name="task"></param>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
/// <param name="d"></param>
/// <param name="e"></param>
/// <param name="f"></param>
void inputEC(int task, double* a, double* b, double* c, double* d, double* e, double* f) {

	switch (task)
	{
	case 1: {
		printf("������� ������ ��� ����������� ���������:\n");
		printf("a: ");
		scanf("%lf", a);
		printf("b: ");
		scanf("%lf", b);
		printf("c: ");
		scanf("%lf", c);
	}
		  break;
	case 2: {
		printf("������� ������ ��� ������� ���� �������� ���������:\n");
		printf("a1, b1, c1 (a1*x + b1*y = c1):\n");
		scanf("%lf %lf %lf", a, b, c);
		printf("a2, b2, c2 (a2*x + b2*y = c2):\n");
		scanf("%lf %lf %lf", d, e, f);
	}
		  break;
	case 3: {
		printf("������� ��������������� ����� ����� ��� ���������� ����������:\n");
		scanf("%lf", a);
	}
		  break;
	default:
		break;
	}

}
/// <summary>
/// ����� ������ ��� 3� �����
/// </summary>
/// <param name="task"></param>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
/// <param name="d"></param>
/// <param name="e"></param>
/// <param name="f"></param>
void outputEC(int task, double a, double b, double c, double d, double e, double f) {
	double x1, x2, countX;

	switch (task)
	{
	case 1: {
		Z1_QuadraticEquation(a, b, c, &countX, &x1, &x2);
		printf("������� ����������� ���������:\n");
		if (countX == 2) printf("x1 = %.2lf, x2 = %.2lf\n", x1, x2);
		else if (countX == 1) printf("x = %.2lf\n", x1);
		else printf("������ ���.\n");
	}
		  break;
	case 2: {
		Z2_SolveLinearEquations(a, b, c, d, e, f, &countX, &x1, &x2);
		printf("������� ������� ���������:\n");
		if (countX == 2) printf("x1 = %.2lf, x2 = %.2lf\n", x1, x2);
		else if (countX == 1) printf("x = %.2lf\n", x1);
		else printf("������ ���.\n");
	}
		  break;
	case 3: {
		int n = (int)a;
		unsigned long long result = Z3_Factorial(n);
		printf("��������� %d = %llu\n", n, result);
	}
		  break;
	default:
		break;
	}

}

void mainEntranceControl()
{
	
	int task;
	double a, b, c, d, e, f;
	printf("\n�������� �������:\n");
	printf("1. ���������� ���������.\n");
	printf("2. ������� ���� �������� ���������.\n");
	printf("3. ������������ (���������).\n");
	printf("������� ����� ������� (1-3): ");
	scanf("%d", &task);
	printf("\n");

	inputEC(task, &a, &b, &c, &d, &e, &f);
	outputEC(task, a, b, c, d, e, f);

}