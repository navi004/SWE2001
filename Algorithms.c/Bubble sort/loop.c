#include <stdio.h>

int bubbleSort(int arr[],int n) {
	int i,j,temp;

	for(int i=0;i<n-1;i++) {
		for(int j=0;j<n-i-1;j++) {
			if(arr[j]>arr[j+1]) {
				temp=arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void display(int arr[],int size){
	for(int i=0;i<size;i++) {
		printf("%d",arr[i]);
		printf("\n");
	}
} 
int main() {
	int arr[100],n;
	printf("Enter the number of elements to be sorted");
	scanf("%d",&n);
	printf("Enter the elements to be sorted :\n");
    for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		}
	bubbleSort(arr,n);
	printf("The sorted elements are");
	display(arr,n);
	return 0;
}
