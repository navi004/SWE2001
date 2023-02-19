//create an array find its length traverse through it and print it using c program
 
#include <stdio.h>

int main(){
    int arr[]={4,3,2,4,3,6,3,6,4};
    int arr_size=sizeof(arr)/sizeof(arr[0]); //getting length of the array
    printf("The size of array: %d\n",arr_size);
    int i;
    for(i=0;i<arr_size;i++){
        printf("arr[%d] = %d\n",i,arr[i]);
    }
    return 0;
}
