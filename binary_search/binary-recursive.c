#include<stdio.h>

int binary_recursive(int *arr, int front, int rear, int e);

int main(){
	int arr[50], count = 0, i = 0, n, e, front, rear, m;
	printf("Enter the number of numbers you want to enter: ");
	scanf("%d", &n);
	printf("Enter the numbers:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter the number to search for: ");
	scanf("%d", &e);
	front = 0;
	rear = n-1;	
	/*
	while(1){
		m = (front +rear) / 2;
		
		if(front==rear && arr[m] != e){
			printf("Element not found!\n");
			break;
		}
		else if(arr[m] == e){
			printf("Element found at index %d", m);
			count++;
			break;
		}
		else if(e > arr[m]){
			front = m + 1;
		}
		else if(e < arr[m]){
			rear = m - 1;
		}
		else{
			break;
		}
	}
	*/
	if(!binary_recursive(arr, front, rear, e)){
		printf("Element not found!\n");
	}
}

int binary_recursive(int *arr, int front, int rear, int e){
	int m;
	m = (front +rear) / 2;
		
	if(front==rear && arr[m] != e){
		return 0;
	}
	else if(arr[m] == e){
		printf("Element found at index %d\n", m);
		return 1;

	}
	else if(e > arr[m]){
		binary_recursive(arr,  m + 1, rear, e);
	}
	else if(e < arr[m]){
		binary_recursive(arr, front, m - 1, e);
	}
}

