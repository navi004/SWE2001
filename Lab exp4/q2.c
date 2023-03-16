// Online C compiler to run C program online
#include <stdio.h>
#define SIZE 10
int circularQueue[SIZE];
int front =-1,rear =-1;

void enqueue(int value) {
    if(front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        circularQueue[rear] = value;
    }
    else if((rear+1)%SIZE == front) {
        printf("Over flow\n");
    }
    else {
        rear = (rear+1)%SIZE;
        circularQueue[rear] = value;
    }
}

void dequeue() {
    if(front == -1) {
        printf("Under flow\n");
    }
    else if(front == rear) {
        printf("The dequeue element is %d",circularQueue[front]);
        front = -1;
        rear = -1;
    }
    else{
        printf("The dequeue element is %d",circularQueue[front]);
        front = (front+1)%SIZE;
    }
}


int main() {
    printf("Enter your ch")

    return 0;
}
