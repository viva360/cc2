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

void printll(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
}

// Function to find the merge point of two sorted linked lists
struct node* findMergePoint(struct node* list1, struct node* list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->data == list2->data) {
            return list1;
        } else if (list1->data < list2->data) {
            list1 = list1->next;
        } else {
            list2 = list2->next;
        }
    }
    return NULL; // No merge point found
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    // Create two sorted linked lists
    InsertAtEnd(&head1, 5);
    InsertAtEnd(&head1, 10);
    InsertAtEnd(&head1, 15);
    InsertAtEnd(&head1, 25);
    InsertAtEnd(&head1, 30);
    InsertAtEnd(&head1, 35);

    InsertAtEnd(&head2, 7);
    InsertAtEnd(&head2, 14);
    InsertAtEnd(&head2, 21);
    InsertAtEnd(&head2, 28);
    InsertAtEnd(&head2, 35);
    InsertAtEnd(&head2, 42);

    // Merge the two linked lists at a specific point (for demonstration)
    // struct node* mergePoint = CreateNode(20);
    // head1->next->next->next = mergePoint;
    // head2->next->next->next = mergePoint;

    printf("Linked List 1: ");
    printll(head1);
    printf("\nLinked List 2: ");
    printll(head2);
    printf("\n");

    // Find the merge point
    struct node* result = findMergePoint(head1, head2);  

    if (result != NULL) {
        printf("Merge Point: %d\n", result->data);
    } else {
        printf("No merge point found.\n");
    }

    // Free the memory
    struct node* current = head1;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    current = head2;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
