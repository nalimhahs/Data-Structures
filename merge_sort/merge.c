#include<stdio.h>

int get_data(int *arr){
	int i = 0, n=0;
	printf("Enter the number of numbers you want to enter: ");
	scanf("%d", &n);
	printf("Enter the numbers:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	return n;
}

int binary_recursive(int *arr, int front, int rear, int e){
	int m;
	m = (front +rear) / 2;
		
	if(front==rear && arr[m] != e){
		return 0;
	}
	else if(arr[m] == e){
		return 1;
	}
	else if(e > arr[m]){
		binary_recursive(arr,  m + 1, rear, e);
	}
	else if(e < arr[m]){
		binary_recursive(arr, front, m - 1, e);
	}
}

int merge_2_sort(int *result, int *arr1, int *arr2, int m, int n){
	int p1 = 0, p2 = 0, p3 = 0, t;
	t = m + n;
	while(p3 < t){
		
		if(p1 > m-1){
			if(!binary_recursive(result, 0, p3, arr1[p1])){
				t--;
			}
			else{
				result[p3] = arr2[p2];
				p3++;
				p2++;
			}
				
		} else if(p2 > n-1){
			if(!binary_recursive(result, 0, p3, arr2[p2])){
				t--;
			}
			else{
				result[p3] = arr1[p1];
				p3++;
				p1++;
			}
				
		} else if(arr1[p1] < arr2[p2]){
			if(!binary_recursive(result, 0, p3, arr1[p1])){
				t--;
			}
			else{
				result[p3] = arr1[p1];
				p3++;
				p1++;
			}
		} else if(arr2[p2] < arr1[p1]){
			if(!binary_recursive(result, 0, p3, arr2[p2])){
				t--;
			}
			else{
				result[p3] = arr2[p2];
				p3++;
				p2++;
			}
		} else {
			printf("here\n");
		}
	}
	return t;
}

int merge_sort(int *result, int *arr1, int *arr2, int m, int n){
	int p1 = 0, p2 = 0, p3 = 0, t;
	t = m + n;
	while(p3 < t){
		if(p1 > m-1){
			result[p3] = arr2[p2];
			p3++;
			p2++;

		} else if(p2 > n-1){
			result[p3] = arr1[p1];
			p3++;
			p1++;
			
		} else if(arr1[p1] < arr2[p2]){
			result[p3] = arr1[p1];
			p3++;
			p1++;
		} else if(arr2[p2] < arr1[p1]){
			result[p3] = arr2[p2];
			p3++;
			p2++;
		} else {
			printf("here\n");
		}
	}
	return t;
}

void main(){
	int arr1[50], arr2[50], arr3[100], m, n, i, t;
	m = get_data(arr1);
	n = get_data(arr2);
	t = merge_sort(arr3, arr1, arr2, m, n);
	//printf("%d", arr3[i]);
	for(i = 0; i < m+n; i++){
		printf("\n%d\n", arr3[i]);
	}
}


