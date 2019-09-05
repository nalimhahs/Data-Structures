#include<stdio.h>

main(){
	int arr[50], count = 0, i = 0, n, e;
	printf("Enter the number of numbers you want to enter: ");
	scanf("%d", &n);
	printf("Enter the numbers:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter the number to search for: ");
	scanf("%d", &e);
	for(i = 0; i < n; i++){
		if(arr[i]==e){
			count++;
			printf("Element found at index %d", i);
		}
	}
	if(count==0)
		printf("Element not found!\n");
	else
		printf("Element found %d time(s)\n", count);
}
