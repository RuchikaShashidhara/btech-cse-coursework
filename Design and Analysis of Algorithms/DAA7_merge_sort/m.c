#include "m.h"

void mergeSortedHalfs(int *a, int start, int mid, int end){
	// int i,j,k;
		int lower = mid-start+1;
		int upper = end-mid;

		int Lower[lower],Upper[upper];

		for(int i=0;i<lower;i++)
		{
			Lower[i]=a[start+i];
		}

		for(int j=0;j<upper;j++)
		{
			Upper[j]=a[mid+1+j];
		}
		int i=0;
		int j=0;
		int k=start;
		while(i<lower && j<upper){
			if(Lower[i]<=Upper[j])
				{
					a[k]=Lower[i];
					i++;
				}
			else
				{
				a[k]=Upper[j];
				j++;	
				}
				k++;	
		}
		if(i==lower)
		{
			while(j<upper)
			{
				a[k]=Upper[j];
				j++;k++;
			}
		}
		else{
			while(i<lower)
			{
				a[k]=Lower[i];
				i++;
				k++;
			}
		}
}

void mergeSort(int *a, int start, int end){
	if(start<end){
		int mid = (start+end)/2;
		mergeSort(a,start,mid);
		mergeSort(a,mid+1,end);
		mergeSortedHalfs(a,start,mid,end);
	}
}

void insertionSort(int* a,int start,int end){
int j,temp;
int n=(end-start)+1;
for(int i=1;i<n;i++){
	temp = a[i];
	j=i-1;
	while(j>=0 && a[j]>temp){
		a[j+1]=a[j];
		j--;
	}
	a[j+1] = temp;
}
}

void selectiveMergeSort(int *a, int start, int end, int parameter){

	if((end-start)+1>parameter)
		mergeSort(a,start,end);
	else
		insertionSort(a,start,end);
}
