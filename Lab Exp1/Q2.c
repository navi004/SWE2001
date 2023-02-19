//Create an array and insert a new element(say 10) at kth position using c program
#include <stdio.h>
int main(){
    int arr[]={1,2,5,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int j=n;
    n=n+1; //for new elemnt size will increase by 1
    int k=3;   //new element at 3rd position(2nd index)
    while(j>=k){
        arr[j+1]=arr[j];
        j--;
    }
    arr[k]=10;
    int i;
    for(i=0;i<n;i++){
        printf("arr[%d]=%d",i,arr[i]);
    }
    
}
