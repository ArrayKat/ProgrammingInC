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
	List flip2and5 = malloc(sizeof(list));
	List flip0and3 = malloc(sizeof(list));
	List flip4and5 = malloc(sizeof(list));
	PrintList(item);
	item = AddItemToList(item, 7, 4);
	PrintList(item);
	item = DeleteItemToList(item, 7);
	PrintList(item);
	/*flip2and5 = FlipItemsList(item, 2,5);
	printf("Поменяли 2 и 5\n");
	PrintList(flip2and5);*/
	flip0and3 = FlipItemsList(item, 0, 3);
	printf("Поменяли 0 и 3\n");
	PrintList(flip0and3);
	flip4and5 = FlipItemsList(item, 4, 5);
	printf("Поменяли 4 и 5\n");
	PrintList(flip4and5);
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
	List pr = items;
	List prevItem1 = (List)malloc(sizeof(list));
	List prevItem2 = (List)malloc(sizeof(list));
	List nextItem1 = (List)malloc(sizeof(list));
	List nextItem2 = (List)malloc(sizeof(list));
	List item1 = (List)malloc(sizeof(list));
	List item2 = (List)malloc(sizeof(list));
	int num1 = min(index1, index2);
	int num2 = max(index1, index2);
	while (items) {
		if (items->N == num1) {
			prevItem1 = pr;
			item1 = items;
			nextItem1 = items->nextN;
		}
		if (items->N == num2) {
			prevItem2 = pr; 
			item2 = items;
			nextItem2 = items->nextN;
		}
		pr = items;
		items = items->nextN;
	}
	items = head;
	if (num1 == items->N) {
	//c 0
		
		while (items) {
			if (items->N == num1) {
				items = item2;
				items->nextN = nextItem1;
			}
			if (prevItem2 == items) {
				items->nextN = item1;
				items->nextN->nextN = nextItem2;
			}
			items = items->nextN;
		}
	
	}
	else if (item1 == prevItem2 && item2 == nextItem1) {
	//если стоят близко
		while (items) {

			if (prevItem1 == items) {
				items->nextN = item2;
				items->nextN->nextN = nextItem1;

			}
			if (prevItem2 == items) {
				items->nextN = item1;
				items->nextN->nextN = nextItem2;
			}
			items = items->nextN;
		}
	}
	else {
		while (items) {
		
			if (prevItem1 == items) {
				items->nextN = item2;
				items->nextN->nextN = nextItem1;

			}
			if (prevItem2 == items) {
				items->nextN = item1;
				items->nextN->nextN = nextItem2;
			}
			items = items->nextN;
		}
	}
	
	items = head;
	return items;
}