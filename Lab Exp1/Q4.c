#include <stdio.h>
int main() {
  int arr[] = {10,20,30,40,50};
  int n = sizeof(arr)/sizeof(arr[0]);
  int i=0,j=0;
  printf("The original elements are: \n");
  for(i=0;i<n;i++) {
    printf("arr[%d] = %d \n",i,arr[i]);
  }
  int k =2;
  while(j<n) {
    if(arr[j] == k) {
      break;
    }
    j++;
  }
  printf("Found the element %d at %d position",k,j+1);
   }
