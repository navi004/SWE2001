#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertBegin(struct Node** head) {
    int data;
    scanf("%d",&data);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    if (*head == NULL) { // if list is empty
        newNode->next = newNode; // set the next of the new node to itself
    } else { // if list is not empty
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode; // set the next of the last node to the new node
        newNode->next = *head; // set the next of the new node to the current head node
    }
    *head = newNode; // set the new node as the new head of the list
}

void printList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
    } else {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int main() {
    struct Node* head = NULL;

    // insert nodes at the beginning of the list
    insertBegin(&head);
    insertBegin(&head);
    insertBegin(&head);

    // print the list
    printList(head);

    return 0;
}
