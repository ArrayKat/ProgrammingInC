#include "task.h"

struct Struct {
	int N;
	struct Struct* nextN;
};
typedef struct Struct list;
typedef list* List;

List CreateList(int countItems) {
	List start = malloc(sizeof(list)), prev = start;
	start->N = 0;
	start->nextN = NULL;


	for (size_t i = 1; i < countItems; i++) {
		List next = malloc(sizeof(list));
		prev->nextN = next;
		next->N = i;
		prev = next;
	}
	prev->nextN = NULL;

	return start;
}
void PrintList(List items) {
	while (items) {
		printf("%d ", items->N);
		items = items->nextN;
	}
	printf("\n");
}
void DeleteList(List item) {
	List byf = item;
	while (byf) {
		byf = item->nextN;
		free(item);
		item = byf;
	}
	printf("Вы успешно удалили ЛОС");
}
List AddItemToList(List items, int number, int indexStart) {
	List head = items; //запоминаем голову
	List item = (List)malloc(sizeof(list));
	List next = (List)malloc(sizeof(list));
	while (items) {
		if (items->N == indexStart) {
			next = items->nextN;
			item->nextN = next;
			item->N = number;
			items->nextN = item;
		}
		items = items->nextN;
	}
	items = head; //возвращаем голову обратно
	return items;
}
List DeleteItemToList(List items, int number) {
	List head = items;
	List prev = items;
	while (items) {

		if (items->N == number) {

			prev->nextN = items->nextN;
			free(items);
			break;
		}
		prev = items;
		items = items->nextN;
	}
	items = head;
	return items;
}
List FlipItemsList(List items, int index1, int index2) {
	List head = items;
	List nxItem2 = items;
	List Item1 = items;
	List Item2 = items;
	List buf = items;
	int Elem1 = min(index1, index2);
	int Elem2 = max(index1, index2);
	while (items) {
		if (items->N == Elem1) {
			Item1 = items;
		}
		if (items->N == Elem2) {
			Item2 = items;
			nxItem2 = items->nextN;
		}
		items = items->nextN;
	}
	items = head;

	int count = 0;

	if (Item1->N == head->N) { //если 1й элемент - голова
		while (items) {
			if (items->N == head->N) {
				items = Item2;
				items->nextN = Item1->nextN;
				break;
			}
			items = items->nextN;
		}
		items = head;
		while (items) {
			if (items->nextN->N == Item2->N) {
				count++;
			}
			if (count == 1) {
				head = items->nextN->nextN;
			}
			if (count > 1) {
				items->nextN = Item1;
				items->nextN->nextN = nxItem2;
				break;
			}
			items = items->nextN;
		}
		items = head;
	}
	else {
		while (items) {
			if (items->nextN = Item1) {
				items->nextN = Item2;
				items->nextN->nextN = Item1->nextN;
				break;
			}
			items = items->nextN;
		}
		items = head;
		while (items) {
			if (items->nextN->N == Item2->N) {
				count++;
			}
			if (count > 1) {
				items->nextN = Item1;
				items->nextN->nextN = nxItem2;
				break;
			}
			items = items->nextN;
		}
		items = head;
	}
}


void mainSimplyConnectedLists() {
	int N =0;
	printf("Введите количество элементов списка для создания: ");
	scanf_s("%d", &N);
	List item = CreateList(N);
	PrintList(item);
	item = AddItemToList(item, 7, 4);
	PrintList(item);
	item = DeleteItemToList(item, 7);
	PrintList(item);
	item = FlipItemsList(item, 0, 7);
	printf("Поменяли 0 и 1\n");
	PrintList(item);
	DeleteList(item);
	
	
}
