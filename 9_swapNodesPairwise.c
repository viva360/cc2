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

void InsertAtBeginning(struct node** headref, int val) {
	struct node* NewNode = CreateNode(val);
	NewNode->next = *headref;
	*headref = NewNode;
}
//function to swap the nodes pairwise
void swapnodesPairwise(struct node** headref)
{
	struct node* current = *headref;
	while(current != NULL && current->next != NULL)
	{
		int temp = current->data;
		current->data = current->next->data;
		current->next->data = temp;
		current = current->next->next;
	}
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
	InsertAtBeginning(&head, 50);
	InsertAtBeginning(&head, 40);
	InsertAtBeginning(&head, 30);
	InsertAtBeginning(&head, 20);
	InsertAtBeginning(&head, 10);
	printll(head);
	swapnodesPairwise(&head);
    printf("\n");
	printll(head);
	struct node* current = head;
	while (current != NULL) {
		struct node* temp = current;
		current = current->next;
		free(temp);
	}

	return 0;
}