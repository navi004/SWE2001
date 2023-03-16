#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int front = -1,rear =-1;
int queue[SIZE];

void enqueue() {
    int value;
    if(rear == SIZE-1) {
        printf("Overflow\n");
        return ;
    }
    else {
        if(front == -1) {
            front = 0;
        }
        printf("Enter the value: ");
        scanf("%d",&value);  
        rear++;
        queue[rear] = value;
        printf("The enqueued value is %d\n",queue[rear]);
    }
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("Under flow\n");
        return ;
    }
    else {
        printf("The dequeued element is %d\n",queue[front]);
        front++;
    }
}

void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    else {
        printf("The queue is: ");
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek() {
    if(front == -1 || front > rear) {
        printf("Underflow\n");
        return ;
    }
    printf("the first value in the queue is %d",queue[front]);
}
int main() {
    int choice;

    while(1) {
        printf("\nEnter the choice: \n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default :
                printf("INVALID OPTION");
        }
    }
    return 0;
}
