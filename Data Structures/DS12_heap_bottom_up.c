#include<stdio.h>
#define MAX 100

//max heap bottom up approach

void read_Array(int* array, int n){
	int i;
	for(i = 1; i <= n ; ++i)
	scanf("%d", &array[i]);
}

void display_Array(int* array, int n){
	int i;
	for(i = 1; i <= n ; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int* array, int n, int position){
	int i, j;
	i = position;
	j = 2 * i;
	int flag = 0;
	while(j <= n && !flag){
		if(j < n && array[j + 1] > array[j])
			++j;
		if(array[i] < array[j]){
		swap(&array[i], &array[j]);
		i = j;
		j = 2 * i;
		}
		else
		flag = 1;
	}
}

void insert(int* array, int n){
	int i;
	for(i = n/2; i >= 1; --i)
	heapify(array, n, i);
}

int main()
{
	int array[MAX];
	int n;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	printf("Enter elements of the array\n");
	read_Array(array, n);
	display_Array(array, n);
	insert(array, n);
	printf("After heapify\n");
	display_Array(array, n);
	return 0;
}
