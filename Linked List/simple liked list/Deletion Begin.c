#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* head = NULL;


void deleteBegin() {
    if(head == NULL) {
        printf("List is empty\n");
    }
    struct Node* temp = head;
    head = temp->next;
    free(temp);

}
void printList(struct Node* head_ref) {
    struct Node* temp = head_ref;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}



int main() {
    struct Node* n1 = malloc(sizeof(struct Node));
    struct Node* n2 = malloc(sizeof(struct Node));
    struct Node* n3 = malloc(sizeof(struct Node));
    head = malloc(sizeof(struct Node));

    head->data = 1;
    head->next = n1;

    n1->data = 2;
    n1->next = n2;

    n2->data = 3;
    n2->next = n3;

    n3->data = 4;
    n3->next = NULL;

    deleteBegin();
    printList(head);

    free(n1);
    free(n2);
    free(n3);
    free(head);

    return 0;
}
