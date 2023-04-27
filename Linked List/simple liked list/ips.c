#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void deleteNode(int position) {
    struct Node* temp = head;
    if(position == 0) {
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    struct Node* temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next = NULL;
    free(temp1);
}

void insertEnd(struct Node**h_ref,int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL) {
        printf("Memory alloction failed\n");
        exit(1);
    }
    struct Node* temp = *h_ref;
    ptr->data = data;
        if(*h_ref == NULL) {
            *h_ref = ptr;
            ptr->next = NULL;
            return;
        }
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
}

void printList() {
    struct Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        printf("%d",temp->data);
    }
}
// void check() {
//     for(int )
// }
int main() {
    insertEnd(&head,1);
    insertEnd(&head,5);
    insertEnd(&head,5);
    insertEnd(&head,8);
    insertEnd(&head,8);
    insertEnd(&head,8);
    insertEnd(&head,11);
    insertEnd(&head,11);
    insertEnd(&head,12);
    insertEnd(&head,12);
    
    return 0;
}
