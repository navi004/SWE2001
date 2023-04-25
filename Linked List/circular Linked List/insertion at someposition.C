#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

int getSize() {
    int size = 0;
    struct Node* temp = head;
    if (temp == NULL) {
        return size;
    } else {
        do {
            size++;
            temp = temp->next;
        } while (temp != head);
        return size;
    }
}

void insertBegin(struct Node** head,int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL ) {
        printf("Error in malloc\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *head;
    if(head == NULL) {
        *head = newNode;
    }
    else{
        struct Node* temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void insertAtEnd(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;

if (head == NULL) {
	head = newNode;
	newNode->next = head;
} else {
	struct Node* current = head;

	while (current->next != head) {
	current = current->next;
	}

	current->next = newNode;
	newNode->next = head;
    }
}

void insertAtposition(int position,int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(position < 1 || position > getSize() + 1) {
        printf("Invalid insertion");
    }
    newNode->data = data;
    if(position == 1) {
        insertBegin(&head,data);
    }
    if(position == getSize()+1) {
        insertAtEnd(data);
    }
    else {
        struct Node* temp = head;
        for(int i=1;i<position-1;i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
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

    // insert nodes at the end of the list
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);

    insertAtposition(3,6);

    // print the list
    printList(head);

    return 0;
}
