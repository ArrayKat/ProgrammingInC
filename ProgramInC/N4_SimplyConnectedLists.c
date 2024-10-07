#include "task.h"

struct Struct {
	int N;
	struct Struct* nextN;

};
typedef struct Struct list;
typedef list* List;

List CreateList(int countItems);
void PrintList(List items);
void DeleteList(List item);
List AddItemToList(List items, int number, int indexStart);
List DeleteItemToList(List items, int number);
List FlipItemsList(List items, int index1, int index2);
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
	item = FlipItemsList(item, 1, 4);
	printf("Поменяли 1 и 4\n");
	PrintList(item);
	DeleteList(item);
	
	
}

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
void PrintList(List item) {
	while (item) {
		printf("%d ", item->N);
		item = item->nextN;
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
			item->nextN= next;
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
		
		if (items->N==number) {
			
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
	List prItem = items;
	List prItem1 = items;
	List prItem2 = items;
	List buf = items;
	int Item1 = min(index1, index2);
	int Item2 = max(index1, index2);
	while (items) {
		if (items->N == Item1) {
			prItem1 = prItem;
		}
		if (items->N == Item2) {
			prItem2 = prItem;
		}
		prItem = items;
		items = items->nextN;
	}
	items = head;
	
	while (items) {
		if (prItem1 == items) {
			items->nextN = prItem2->nextN;
			items = items->nextN;
			items->nextN = prItem2->nextN->nextN;
		}
		if (prItem2 == items) {
			items->nextN = prItem1->nextN;
			items = items->nextN;
			items->nextN = prItem1->nextN->nextN;
		}
		items = items->nextN;
	}
	items = head;
	
}