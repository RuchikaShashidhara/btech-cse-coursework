//Header file for session7_sort.c

#include <stdio.h>
#include "session5_sort.h"


//Insertion Sort
//Sorts the array of Records on the serialnumber field using the Insertion Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int InsertionSort(Record* A, int n)
{
        int i, j;
        Record temp;
        long int count = 0;
        for(i = 1; i < n; i++)
        {
                temp = A[i];
                j = i-1;
                while(j >= 0 && A[j].serialnumber > temp.serialnumber)
                {
                        A[j+1] = A[j];
                        j -= 1;
                        count++;
                }
                A[j+1] = temp;
        }
        return count;
}

//Bubble Sort
//Sorts the array of Records on the serialnumber field using the Bubble Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int BubbleSort(Record* A, int n)
{
        int i, j, noSwaps;
        Record temp;
        long int count = 0;      
        for(i = 0; i < n-1; i++)
        {
                noSwaps = 1;
                for(j = 0; j < n-1; j++)
                {
                        //count++;
                        if(A[j].serialnumber > A[j+1].serialnumber)
                        {
                                
                                temp = A[j];
                                A[j] = A[j+1];
                                A[j+1] = temp;
                                noSwaps = 0;
                                //printf("%ld ", count);
                                count--;
                        }
                        else
                        	count += 1;
                        
                }
                if(noSwaps == 1)
                        return count;
                //count++;
        }
        return count;
        
}

//Selection Sort
//Sorts the array of Records on the serialnumber field using the Selection Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int SelectionSort(Record* A, int n)
{
        int i, j, min;
        Record temp;
        long int count = 0; 
        for(i = 0; i < n-1; i++)
        {
                min = i;
                for(j = i+1; j < n; j++)
                {
                        if(A[j].serialnumber < A[min].serialnumber)
                        {
                                min = j;
                        }
                        temp = A[i];
                        A[i] = A[min];
                        A[min] = temp;
                        count++;
                }
        }
        return count;
}



//Merge sort will be for next lab sessions
//Merge Sort
//Sorts the array of Records on the serialnumber field using the Merge Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
//long int MergeSort(Record* A, int n);

// Quick sort will be for next lab sessions
//Quick Sort
//Sorts the array of Records on the serialnumber field using the Quick Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
//long int QuickSort(Record* A, int n);
