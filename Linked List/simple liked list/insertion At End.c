#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* head = NULL;

void insertEnd(struct Node** head_ref) {
    int data;
    scanf("%d",&data);
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    ptr->data = data;
    ptr->next = NULL;
    if(*head_ref == NULL) {
        *head_ref = ptr;
    }
    else {
        struct Node* temp = *head_ref;
        while(temp->next != NULL)  {
            temp = temp->next;
        }
        temp->next = ptr;
    }
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

    insertEnd(&head);
    printList(head);

    free(n1);
    free(n2);
    free(n3);
    free(head);

    return 0;
}
