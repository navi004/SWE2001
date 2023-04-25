#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertAtEnd(int newData) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = newData;

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

    // print the list
    printList(head);

    return 0;
}
