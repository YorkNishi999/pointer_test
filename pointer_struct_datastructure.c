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
void deleteNode(LinkedList*, Node*);
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

void deleteNode(LinkedList* list, Node* node) {
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

typedef LinkedList Queue;

void initializeQueue (Queue* queue) {
	initializeList(queue);
}

void enqueue(Queue *queue, void *node) {
	addHead(queue, node);
}

void* dequeue(Queue *queue) {
	Node* tmp = queue->head;
	void* data;
	if (queue->head == NULL) {
		data = NULL;
	} else if (queue->head == queue->tail) {
		queue->head = queue->tail = NULL;
		data = tmp->data;
		free(tmp);
	} else {
		while(tmp->next != queue->tail){
			tmp = tmp->next;
		}
		queue->tail = tmp;
		tmp = tmp->next;
		queue->tail->next = NULL;
		data = tmp->data;
		free(data);
	}
	return data;
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

	Employee* samuel2 = (Employee*)malloc(sizeof(Employee));
	strcpy(samuel2->name, "Samuel");
	samuel2->age = 22;
	
	Employee* sally2 = (Employee*)malloc(sizeof(Employee));
	strcpy(sally2->name, "Sally");
	sally2->age = 24;
	
	Employee* susan2 = (Employee*)malloc(sizeof(Employee));
	strcpy(susan2->name, "Susan");
	susan2->age = 44;
	
	Node* node = getNode(linkedlist, (int (*)(void*, void*))compareEmployee, susan);
	deleteNode(linkedlist, node);

	displayLinkedList(linkedlist, (DISPLAY)displayEmployee);

	Queue *queue = (Queue*)malloc(sizeof(Queue));
	initializeQueue(queue);

	enqueue(queue, samuel2);
	enqueue(queue, sally2);
	enqueue(queue, susan2);


	void* data = dequeue(queue);
	printf("Dequeued %s\n", ((Employee*)data)->name);
	data = dequeue(queue);
	printf("Dequeued %s\n", ((Employee*)data)->name);
	data = dequeue(queue);
	printf("Dequeued %s\n", ((Employee*)data)->name);	

	return 0;
}