//write a c program for circular queue
#include <stdio.h>
#include <stdlib.h>
# define N 5

int cqueue[N];
int front = -1,rear = -1;

void enQueue() {
    int value;
    if(front == (rear+1)%N) {
        printf("The Queue is full\n");
        return;
    }
    else {
        if(front == -1 && rear == -1) {
            front = 0;
        }
        printf("Enter the value: ");
        scanf("%d",&value);
        rear = (rear+1)%N;
        cqueue[rear] = value;
        printf("The enqueued element is %d\n",cqueue[rear]);
    }
}
void deQueue() {
    if(front == -1 && rear == -1) {
        printf("The Queue is empty\n");
    }
    else if(front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        printf("The DeQueued element is %d\n",cqueue[front]);
        front = (front+1)%N;
    }
}
void peek() {
    if(front == -1 && rear == -1) {
        printf("The Queue is empty\n");
        return;
    }
    else {
        printf("The first element of the queue is %d \n",cqueue[front]);
    }
}
void display() {
    if(front == -1 && rear == -1) {
        printf("The Queue is empty \n");
        return;
    }
    else {
        int i = front;
        printf("The Queue is : ");
        while(i != rear) {
            printf("%d ",cqueue[i]);
            i = (i+1)%N;
        }
        printf("%d\n",cqueue[rear]);
    }
}

int main() {
    int choice;
    while(1) {
        printf("Enter the choice :\n");
        printf("1.Enqueue \n2.Dequeue \n3.Peek \n4.Display \n5.Exit \n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
            enQueue();
            break;
            case 2:
            deQueue();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            exit(0);
            break;
            default :
            printf("INVALID OPTION");
        }
    }
    return 0;
}
