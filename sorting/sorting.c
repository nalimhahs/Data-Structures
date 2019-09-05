#include<stdio.h>

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void printArr(int a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(){
	int choice, n, arr[20], pos, k, i, j;
	printf("Menu\n1. Bubble Sort\n2. Selection sort\n3. Insertion Sort\nEnter choice: ");
	scanf("%d", &choice);
	
	switch(choice){
	
		case 1:
			printf("Enter n: ");
			scanf("%d", &n);
			printf("Enter the numbers:\n");
			for(i = 0; i < n; i++){
				scanf("%d", &arr[i]);
			}
			for(i = 0; i < n; i++){
				for(j = 0; j < n-1; j++){
					if(arr[j] > arr[j+1]){
						swap(&arr[j], &arr[j+1]);
					}
				}
				printf("Pass %d: \n", i+1);
				printArr(arr, n);
			}
			printf("Sorted Array is:\n");
			printArr(arr, n);
			break;
			
		case 2:
			printf("Enter n: ");
			scanf("%d", &n);
			printf("Enter the numbers:\n");
			for(i = 0; i < n; i++){
				scanf("%d", &arr[i]);
			}
			for(i = 0; i < n-1; i++){
				pos = i;
				for(j = i+1; j < n; j++){
					if(arr[j] < arr[pos]){
						pos = j;
					}
				}
				swap(&arr[i], &arr[pos]);
				printf("Pass %d: \n", i+1);
				printArr(arr, n);
			}
			printf("Sorted Array is:\n");
			printArr(arr, n);
			break;
			
		case 3:
			printf("Enter n: ");
			scanf("%d", &n);
			printf("Enter the numbers:\n");
			for(i = 0; i < n; i++){
				scanf("%d", &arr[i]);
			}
			for(i = 0; i < n; i++){
				k = i;
				while(k > 0){
					if(arr[k-1] <= arr[k]){
						break;
					}
					swap(&arr[k], &arr[k-1]);
					k--;
				}
				printf("Pass %d: \n", i+1);
				printArr(arr, n);
			}
			printf("Sorted Array is:\n");
			printArr(arr, n);
			break;
			
		default: 
			printf("Invalid Input!\n");
	}
}

