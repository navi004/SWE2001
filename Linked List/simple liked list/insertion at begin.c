#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node * head;
void insert(int data) {
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL)
        printf("Over Flow");
    ptr->data = data;
    ptr->next = head;
    head = ptr;
}

void printlink() {
    struct Node *temp = head;
    if(temp == NULL)
        printf("Link is empty\n");
    while(temp != NULL) {
        printf("%d \n",temp->data);
        temp = temp->next;
    }
}

int main() {
    // printf("Enter the number of elements to be inserted:");
    // scanf("%d",&n);
    insert(1);
    insert(2);
    insert(3);
    printlink();
    return 0;
}
