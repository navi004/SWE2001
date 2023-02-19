//Create an array and delete an element at kth position using c program
#include <stdio.h>
int main(){
    int arr[]={1,2,5,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i,j,k;
    printf("The original array elements are:\n");
    for(i = 0;i<n;i++) {
      printf("arr[%d] = %d \n",i,arr[i]);
    }
    k=3;   //new element at 3rd position(2nd index)
    j=k;
    while(j<n){
        arr[j-1]=arr[j];
        j = j+1;
    }
    n = n - 1;
    printf("After deletion the array elements are: \n");
    for(i=0;i<n;i++){
        printf("arr[%d]=%d\n",i,arr[i]);
    }
}
