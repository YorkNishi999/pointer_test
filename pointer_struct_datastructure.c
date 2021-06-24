#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _employee {
	char name[32];
	unsigned char age;
} Employee;

typedef int(*COMPARE)(void*, void*); 
// 関数ポインタ。void* の2つの引数を取って、COMPAREへの関数ポインタで、
// int型を返す
typedef void(*DISPLAY)(void*);

int compareEmployee(Employee* e1, Employee* e2) {
	return strcmp(e1->name, e2->name);
}

void displayEmployee(Employee* employee) {
	printf("%s\t%d\n", employee->name, employee->age);
}

typedef struct _node {
	void* data;
	struct _node* next;
} Node;

typedef struct _linkedList {
	Node *head;
	Node *tail;
	Node *current;
} LinkedList;

void initializeList(LinkedList*);
void addHead(LinkedList*, void*);
void addTail(LinkedList*, void*);
void delete(LinkedList*, Node*);
Node* getNode(LinkedList*, COMPARE, void*);
void displayLinkedList(LinkedList*, DISPLAY);

void initializeList(LinkedList* list) {
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}

void addHead(LinkedList* list, void* data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (list->head == NULL) {
		list->tail = node;
		node->next = NULL;
	} else {
		node->next = list->head;
	}
	list->head = node;
}

void addTail(LinkedList* list, void* data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if(list->head == NULL) {
		list->head = node;
	} else {
		list->tail->next = node;
	}
}

Node* getNode(LinkedList* list, COMPARE compare, void* data) {
	Node* node = list->head;
	while(node != NULL) {
		if (compare(node->data, data) == 0) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}

void delete(LinkedList* list, Node* node) {
	if (node == list->head) {
		if (list->head->next == NULL) {
			list->head = list->tail = NULL;
		} else {
			list->head = list->head->next;
		}
	} else {
		Node* tmp = list->head;
		while(tmp != NULL && tmp->next != node) {
			tmp = tmp->next;
		}
		if(tmp != NULL) {
			tmp->next = node->next; // 削除するnodeの直前直後をつなげる
		}
	}
	free(node); // nodeを開放する＝nodeを削除する
}

void displayLinkedList(LinkedList* list, DISPLAY display) {
	printf("\nLinked List\n");
	Node *current = list->head;
	while(current != NULL){
		display(current->data);
		current = current->next;
	}
}


int main() {
	LinkedList* linkedlist = (LinkedList*)malloc(sizeof(LinkedList));

	Employee* samuel = (Employee*)malloc(sizeof(Employee));
	strcpy(samuel->name, "Samuel");
	samuel->age = 22;
	
	Employee* sally = (Employee*)malloc(sizeof(Employee));
	strcpy(sally->name, "Sally");
	sally->age = 24;
	
	Employee* susan = (Employee*)malloc(sizeof(Employee));
	strcpy(susan->name, "Susan");
	susan->age = 44;

	initializeList(linkedlist);

	addHead(linkedlist, samuel);
	addHead(linkedlist, sally);
	addHead(linkedlist, susan);


	displayLinkedList(linkedlist, (DISPLAY)displayEmployee);

	Node* node = getNode(linkedlist, (int (*)(void*, void*))compareEmployee, susan);
	delete(linkedlist, node);

	displayLinkedList(linkedlist, (DISPLAY)displayEmployee);
	
	return 0;
}