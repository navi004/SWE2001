#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node after a given node
void insertAfter(struct Node* prev_node, int new_data)
{
    // Check if the previous node is NULL
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }

    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Set the new node's data
    new_node->data = new_data;

    // Set the new node's next pointer to the same as the next pointer of the previous node
    new_node->next = prev_node->next;

    // Set the previous node's next pointer to the new node
    prev_node->next = new_node;
}

// Function to print all nodes in the linked list
void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    // Create the head node and set its data
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;

    // Insert new nodes after the head node
    insertAfter(head, 2);
    insertAfter(head, 3);
    insertAfter(head, 4);

    // Print all nodes in the linked list
    printList(head);

    return 0;
}
