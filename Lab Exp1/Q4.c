// Create a program to find the position of an element in an array
#include <stdio.h>
int main() {
  int arr[] = {10,20,30,40,50};
  int n = sizeof(arr)/sizeof(arr[0]);
  int i=0,j=0,l;
  printf("The original elements are: \n");
  for(i=0;i<n;i++) {
    printf("arr[%d] = %d \n",i,arr[i]);
  }
  int k =10;
  while(j<n) {
    if(arr[j] == k) {
        l=1;
 printf("Found the element %d at %dth position",k,j+1);
      break;
    }
    j++;
  }
 
  if(l==0)
  printf("Element not found in the array");
   }
