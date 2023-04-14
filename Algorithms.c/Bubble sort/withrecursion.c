#include <stdio.h>

void rbubbleSort(int arr[],int size) {
	
	int temp, flag = 0;
	for(int i=0;i<size-1;i++) {
		if(arr[i] > arr[i+1]) {
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			flag = 1;
		}
		if(flag == 1) 
			return rbubbleSort(arr,size);
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
	rbubbleSort(arr,n);
	printf("The sorted elements are\n");
	display(arr,n);
	return 0;
}
