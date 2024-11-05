#include "task.h"

void mainWorkFileInC() {
	double a, b, c;

	FILE* fileInput;
	FILE *fileOutput;
	fileInput = fopen("fileInputOutput/InputC.txt", "r");
	fileOutput = fopen("fileInputOutput/OutputC.txt", "w");
	if (fileInput == NULL) printf("������ ������ �����!!!");
	if (fscanf(fileInput, "%lf %lf %lf", &a, &b, &c) != 3) {
		printf("������ ������ ������ �� �����");
		fprintf(fileOutput,"������ ������ ������. ������� ���������� �������� ����������� ��������� � ���� InputC.txt.");
	}
	else {
		fprintf(fileOutput,"��������� ��������:\n");
		fprintf(fileOutput,"a: %lf\n", a);
		fprintf(fileOutput,"b: %lf\n", b);
		fprintf(fileOutput,"c: %lf\n", c);

		printf("a: %lf\n", a);
		printf("b: %lf\n", b);
		printf("c: %lf\n", c);

		if (a == 0 && b == 0 && c!=0) {
			printf("��������� �� ����� �������.\n");
			fprintf(fileOutput, "��������� �� ����� �������.\n");
		}
		else if (a == 0 && b == 0 && c == 0) {
			printf("����������� ���������� �������\n");
			fprintf(fileOutput, "����������� ���������� �������\n");
		}
		else if (a == 0 && b != 0) {
			double x = -(c / b);
			printf("�������� ���������, ������ � = %lf\n", x);
			fprintf(fileOutput, "�������� ���������, ������ � = %lf\n", x);
		}
		else if (a != 0) {
			float D = (pow(b, 2) )-4 * a * c;
			printf("D: %lf\n", D);
			fprintf(fileOutput, "D: %lf\n", D);

			if (D > 0) {
				double x1, x2;
				x1 = (-b + sqrtf(D)) / (2 * a);
				x2 = (-b - sqrtf(D)) / (2 * a);
				printf("x1: %lf\n", x1);
				printf("x2: %lf\n", x2);
				fprintf(fileOutput, "x1: %lf\n", x1);
				fprintf(fileOutput, "x2: %lf\n", x2);
			}
			else if (D == 0) {
				fprintf(fileOutput, "�.�. D=0 � ��������� ������ 1 ������\n");
				double x = -b / 2 * a;
				printf("x: %lf\n", x);
				fprintf(fileOutput, "x: %lf\n", x);
			}
			else {
				printf("������ ��� (D = %lf)\n", D);
				fprintf(fileOutput, "������ ��� (D = %lf)\n", D);

			}
		}
	}
	fclose(fileInput);
	fclose(fileOutput);
	

}