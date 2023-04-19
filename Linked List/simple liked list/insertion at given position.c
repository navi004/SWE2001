#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int data) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    printf("Node with data %d inserted at beginning\n", data);
}

void insertAfter(int prev_node_loc) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    int data;
    printf("Enter data for new node: ");
    scanf("%d", &data);
    ptr->data = data;
    struct Node *temp = head;
    for(int i = 0; i < prev_node_loc; i++) {
        temp = temp->next;
        if(temp == NULL) {
            printf("Node not found at position %d\n", prev_node_loc);
            free(ptr);
            return;
        }
    }
    ptr->next = temp->next;
    temp->next = ptr;
    printf("Node with data %d inserted after node at position %d\n", data, prev_node_loc);
}

void delete(int data) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    while(temp != NULL) {
        if(temp->data == data) {
            if(prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Node with data %d deleted from list\n", data);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Node with data %d not found in list\n", data);
}

void printList() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List contents:\n");
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertBeginning(1);
    insertBeginning(2);
    insertBeginning(3);
    insertAfter(1);
    insertAfter(0);
    insertAfter(4);
    // delete(2);
    // delete(4);
    // delete(5);
    printList();
    return 0;
}
