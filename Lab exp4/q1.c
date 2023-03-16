// Online C compiler to run C program online
#include <stdio.h>
#define SIZE 10;

int queue[SIZE];
int front = -1,rear =-1;

void Enqueue(int value) {
    if(rear == SIZE-1) {
        printf("Over flow\n");
    }
    else {
        rear++;
        queue[rear] = value;
        printf("INSERTION SUCCESSFUL\n");
    }
}

void Dequeue() {
    if(front == -1) {
        printf("Under flow\n");
    }
    else{
        front++;
        if(front == rear) {
            front = -1;
            rear = -1;
            printf("DELETION SUCCESSFUL\n");
        }
    }
}
int main() {
    int choice;
    printf("Enter the ")
    return 0;
}
