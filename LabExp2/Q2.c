//Write a C program to implement Stack using arrays

#include <stdio.h>
#include <stdlib.h>

# define MAX 10      //size of stack

int stack[MAX];
int top = -1;             //indicates stack is empty at initial

//defining the fuctions
void push(int item);
int pop() ;
int peek() ;
int isEmpty();
int isFull();
void display();

int main() {
    int option,n,value;
    while(1) {

         printf("Menu : \n");
         printf("1.Push \n");
         printf("2.Pop \n");
         printf("3.Peek\n");
         printf("4.Display all stack elements\n");
         printf("5.Exit the program\n");

 
         printf("Choose an option:");
         if(scanf("%d",&option) != 1) {                             //checking whether input is an integer
             printf("Invalid Input.Please Enter an integer :\n");   // print invalid if input is not an integer
             while(getchar() != '\n');                              //to clear input buffer  
             continue;
         }
         if(option < 1 || option > 5) {                             //checking input is in between 1 to 5 options
             printf("Invalid option.Enter the valid option:\n");
             continue;
         }


  
switch(option) {
    case 1:
         printf("Enter the number of elements to be pushed :");
         scanf("%d",&n) ;                                         
         if(n<=MAX) {
            for(int i=0; i<n; i++) {
                 printf("Enter the value to be pushed :");       //checking whether input is an integer
                 if(scanf("%d",&value) != 1) {
                 printf("Invalid input.Enter an integer:\n");
                 while(getchar() != '\n');                       //to clear input buffer
                 continue;
                }
             push(value);
            }
        }
         else {
            printf("Size of stack is %d.Please enter <= %d",MAX,MAX);
        }
         break;
     case 2: 
         value = pop();
         if(value != -1) {                           //checking stack is not empty
         printf("Popped value is %d \n",value);
         }
         break;
    case 3:
         value = peek();
         if(value != -1) {                           //checking stack is not empty
         printf("The top most value is %d\n",value);
         }
         break;
    case 4: 
         display();
         break;
    case 5:
         exit(0);
    default:
         printf("Invalid input value");
         break;
        }
     }
     return 0;
   
 }

void push(int value) {
    if(isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

int pop() {
    int value;
    if(isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    value = stack[top];
    top--;
    return value;
}

int peek() {
    if(isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int isEmpty() {
    if(top==-1) {
        return 1;
    }
    else
        return 0;
}

int isFull() {
    if(top==MAX-1) {
        return 1;
    }
    else
    return 0;
}
void display() {
    if(isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Displaying all values of stack:\n");

    for(int i=top; i>=0; i--) {
         printf("stack[%d] = %d \n",i,stack[i]);
    }
}
