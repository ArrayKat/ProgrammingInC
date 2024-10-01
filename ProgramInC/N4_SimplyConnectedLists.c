#include "task.h"

struct Struct {
	int N;
	struct Struct* nextN;

};
typedef struct Struct list;
typedef list* List;


void mainSimplyConnectedLists() {
	int N;
	List start = (List) malloc(sizeof(list)), prev = start;
	start->N = 0;
	start->nextN = NULL;

	printf("Введите количество элементов списка: ");
	scanf_s("%d", &N);
	for (size_t i = 1; i < N; i++) {
		List next = (List)malloc(sizeof(list));
		prev->nextN = next;
		next->N = i;
		prev = next;
	}
	prev->nextN = NULL;
	prev = start;

	while (prev) {
		printf("%d ", prev->N);
		prev = prev->nextN;
	}

}