#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);

    // If the linked list is empty, make the new node as the head
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    // Traverse to the last node
    struct Node* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }

    // Insert the new node at the end
    current->next = newNode;
}
// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    // Create a mergell node to simplify code
    struct Node* mergell = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = mergell;

    // Traverse both lists until one of them becomes empty
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }


    // If one list is not empty, append its remaining elements
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    // Return the merged list starting from the mergell node's next
    return mergell->next;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    // Create two sorted linked lists
    struct Node* list1 = NULL;
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 5);

    struct Node* list2 = NULL;
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);

    printf("List1: ");
    printList(list1);
    printf("\nList2: ");
    printList(list2);
    // Merge and print the sorted linked lists
    struct Node* mergedList = mergeSortedLists(list1, list2);
    printf("\nMerged Sorted List: ");
    printList(mergedList);
    return 0;
}