#include<stdio.h>
#include<stdlib.h>

//top down approach

void restoreUp(int arr[],int i)
{
    int k=arr[i];
    int par=i/2;
    while(arr[par]<k) //for max heap arr[par] < k, for min heap arr[par] > k
    {
        arr[i]=arr[par];
        i=par;
        par=i/2;
    }
    arr[i]=k;
}

void buildheap1(int arr[],int size)
{
    int i;
    for(i=2;i<=size;i++)
       restoreUp(arr,i);
} 

int main(){
    int n, i;
    int array[100];
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for(i=1; i<=n; i++){
        scanf("%d", &array[i]);
        //printf("%d ", array[i]);
    }
    buildheap1(array, n);
    printf("Max heap:\n");
    for(i=1; i<=n; i++){
        printf("%d ", array[i]);
    }
    return 0;
}


//write code properly in the main fuction for this max heap using bottom up approach

void restoreDown(int arr[],int i,int size)
{
    int left=2*i;
    int right=2*i+1;
    int num=arr[i];
    while(right<=size)
    {
        if(num>arr[left] && num>arr[right])
        {
            arr[i]=num;
            return;
        }
        else if(arr[left]>arr[right])
        {
            arr[i]=arr[left];
            i=left;
        }
        else
        {
            arr[i]=arr[right];
            i=right;
        }
        left=2*i;
        right=2*i+1;
    }
    if(left==size && arr[left]>num)
    {
        arr[i]=arr[left];
        i=left;
    }
    arr[i]=num;
}
void buildheap2(int arr[],int size)
{
    int i;
    for(i=size/2;i>=1;i--)
       restoreDown(arr,i,size);
}
