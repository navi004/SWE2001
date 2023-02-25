// c program for stack implementataion

#include <stdio.h>
#include <stdlib.h>

# define MAX 10  //macro

int stack[MAX];
int top = -1;

void push(int item);
int pop() ;
int peek() ;
int isEmpty();
int isFull();
void display();

int main() {
    int option,value;
    while(1) {                 // to take input until user choose exit

         printf("Menu : \n");
         printf("1.Push \n");
         printf("2.Pop \n");
         printf("3.Peek\n");
         printf("4.Display all stack elements\n");
         printf("5.Exit the program\n");

 
         printf("Choose an option:");
         if(scanf("%d",&option) != 1) {                              //to check whether input is integer 
             printf("Invalid Input.Please Enter an integer :\n");    //printf invalid if input is not integer
             while(getchar() != '\n');                               //to clear input buffer
             continue;
         }
         if(option < 1 || option > 5) {                             // to check whether input is in between in 1 and 5
             printf("Invalid option.Enter the valid option:\n");    //print invalid if input crosses the parameters
             continue;                                              //continue skips the remaining loop
         }


  
switch(option) {                                                     
    case 1:
          printf("Enter the value to be pushed :");
         if(scanf("%d",&value) != 1) {                             //to check whether input is integer 
             printf("Invalid input.Enter an integer:\n");
             while(getchar() != '\n');                             //to clear input buffer
             continue;
         }
         push(value);
         break;
     case 2: 
         value = pop();
         if(value != -1) {                                        //checking the top is not empty
         printf("Popped value is %d \n",value);
         }
         break;
    case 3:
         value = peek();
         if(value != -1) {                                          //checking the top is not empty
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
    top++;                                  // increasing the size for new element
    stack[top] = value;                    //assinging input value to top most element 
}

int pop() {
    int value;
    if(isEmpty()) {
        printf("Stack Underflow\n");
        return -1;                        //indicates the error in the function
    }
    value = stack[top];                   //top element is assigned to value
    top--;
    return value;                          // value is returned to print
}

int peek() {
    if(isEmpty()) {
        printf("Stack is empty\n"); 
        return -1;                         //indicates the error in the function
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
    if(top==MAX-1) {                    ///checking the top is equal to size 
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
         printf("%d\n",stack[i]);
    }
}
