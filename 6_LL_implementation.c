#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* CreateNode(int val) {
	struct node* NewNode = (struct node*)malloc(sizeof(struct node));
	NewNode->data = val;
	NewNode->next = NULL;
	return NewNode;
}

void InsertAtEnd(struct node** headref, int val) {
	struct node* NewNode = CreateNode(val);
	if (*headref == NULL) {
		*headref = NewNode;
		return;
	}
	struct node* current = *headref;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = NewNode;
}

void InsertAtBeginning(struct node** headref, int val) {
	struct node* NewNode = CreateNode(val);
	NewNode->next = *headref;
	*headref = NewNode;
}

void InsertAtIndex(struct node** headref, int val, int index) {
	if (index < 0) {
		printf("ENTER A VALID INDEX");
		return;
	}
	if (index == 0) {
		InsertAtBeginning(headref, val);
		return;
	}
	struct node* NewNode = CreateNode(val);
	struct node* current = *headref;
	int count = 0;
	while (current != NULL && count < index - 1) {
		current = current->next;
		count++;
	}
	if (current == NULL) {
		printf("INDEX OUT OF RANGE");
		return;
	}
	NewNode->next = current->next;
	current->next = NewNode;
}

void printll(struct node* head) {
	struct node* current = head;
	while (current != NULL) {
		printf("%d->", current->data);
		current = current->next;
	}
}

int main() {
	struct node* head = NULL;
	InsertAtBeginning(&head, 10);
	InsertAtBeginning(&head, 20);
	InsertAtBeginning(&head, 30);
	InsertAtIndex(&head, 5, 1);
	InsertAtEnd(&head, 30);
	printll(head);
	struct node* current = head;
	while (current != NULL) {
		struct node* temp = current;
		current = current->next;
		free(temp);
	}

	return 0;
}