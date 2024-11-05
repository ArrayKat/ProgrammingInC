#include "task.h"

void mainWorkFileInC() {
	double a, b, c;

	FILE* fileInput;
	FILE *fileOutput;
	fileInput = fopen("fileInputOutput/InputC.txt", "r");
	fileOutput = fopen("fileInputOutput/OutputC.txt", "w");
	if (fileInput == NULL) printf("ОШИБКА чтения файла!!!");
	if (fscanf(fileInput, "%lf %lf %lf", &a, &b, &c) != 3) {
		printf("ОШИБКА чтения данных из файла");
		fprintf(fileOutput,"ОШИБКА чтения данных. Введите корректные значения квадратного уравнения в файл InputC.txt.");
	}
	else {
		fprintf(fileOutput,"Считанные значения:\n");
		fprintf(fileOutput,"a: %lf\n", a);
		fprintf(fileOutput,"b: %lf\n", b);
		fprintf(fileOutput,"c: %lf\n", c);

		printf("a: %lf\n", a);
		printf("b: %lf\n", b);
		printf("c: %lf\n", c);

		if (a == 0 && b == 0 && c!=0) {
			printf("Уравнение не имеет решений.\n");
			fprintf(fileOutput, "Уравнение не имеет решений.\n");
		}
		else if (a == 0 && b == 0 && c == 0) {
			printf("Бесконечное количество решений\n");
			fprintf(fileOutput, "Бесконечное количество решений\n");
		}
		else if (a == 0 && b != 0) {
			double x = -(c / b);
			printf("Линейное уравнение, корень х = %lf\n", x);
			fprintf(fileOutput, "Линейное уравнение, корень х = %lf\n", x);
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
				fprintf(fileOutput, "Т.к. D=0 в уравнении только 1 корень\n");
				double x = -b / 2 * a;
				printf("x: %lf\n", x);
				fprintf(fileOutput, "x: %lf\n", x);
			}
			else {
				printf("Корней нет (D = %lf)\n", D);
				fprintf(fileOutput, "Корней нет (D = %lf)\n", D);

			}
		}
	}
	fclose(fileInput);
	fclose(fileOutput);
	

}