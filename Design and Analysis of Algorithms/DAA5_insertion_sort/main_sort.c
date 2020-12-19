#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "session5_sort.h"

/*
typedef struct Record {
	long int serialnumber;
	int score;
} Record;
*/

void printStruct(Record *A, int n);
//void printOP(Record *A, int n, int c);
double time_elapsed(struct timespec start, struct timespec end);

int main()
{
        int i, n;
        
        Record *A;
        scanf("%d", &n);
        A = (Record*)malloc(n * sizeof(Record));   
        for(i = 0; i < n; i++)
        {
                scanf("%ld %d", &A[i].serialnumber, &A[i].score);
        }
        //printStruct(A, n);
        
        long int swaps;
        Record *A1, *A2, *A3;
        double t;
        struct timespec start, end; //timestamps
        
                A1 = (Record*)malloc(n * sizeof(Record));
                for(i = 0; i < n; i++)
        	{
                	A1[i].serialnumber = A[i].serialnumber;
                	A1[i].score = A[i].score;
        	}            
                //printStruct(A1, n);
                clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
                swaps = InsertionSort(A1, n);
                clock_gettime(CLOCK_REALTIME, &end); //end timestamp
                t = time_elapsed(start, end);
		//printStruct(A1, n);
                printf("Insertion sort: %ld %lf\n", swaps, t);
                //free(A1);
        
                A2 = (Record*)malloc(n * sizeof(Record));  
                for(i = 0; i < n; i++)
        	{
                	A2[i].serialnumber = A[i].serialnumber;
                	A2[i].score = A[i].score;
        	} 
                //printStruct(A2, n);
                clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
                swaps = BubbleSort(A2, n);
                clock_gettime(CLOCK_REALTIME, &end); //end timestamp
                t = time_elapsed(start, end);
		//printStruct(A2, n);
                printf("Bubble sort: %ld %lf\n", swaps, t);
                //free(A2);
        
                A3 = (Record*)malloc(n * sizeof(Record));  
                for(i = 0; i < n; i++)
        	{
                	A3[i].serialnumber = A[i].serialnumber;
                	A3[i].score = A[i].score;
        	} 
                //printStruct(A3, n);
                clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
                swaps = SelectionSort(A3, n);
                clock_gettime(CLOCK_REALTIME, &end); //end timestamp
                t = time_elapsed(start, end);
		//printStruct(A3, n);
                printf("Selection sort: %ld %lf\n", swaps, t);
        	//free(A3);                
       
        return 0;
}

void printStruct(Record *A, int n)
{
        printf("\nRecord: \n");
        int i;
        for(i = 0; i < n; i++)
        {
                printf("%ld %d\n", A[i].serialnumber, A[i].score);
        }     
        printf("\n");   
}

double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  //diff of tv_sec
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
    return t;
}
/*
void printOP(Record *A, int n, int c)
{
        printStruct(A, n);
        long int swaps;
        Record *A1, *A2, *A3;
        A1 = (Record*)malloc(n * sizeof(Record));  
        A2 = (Record*)malloc(n * sizeof(Record));  
        A3 = (Record*)malloc(n * sizeof(Record));  
        A1 = A; 
        A2 = A;
        A3 = A;
        double t;
        struct timespec start, end; //timestamps
        
        
        if(c == 0)
        {
                clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
                swaps = InsertionSort(A1, n);
                clock_gettime(CLOCK_REALTIME, &end); //end timestamp
                t = time_elapsed(start, end);
                printf("Insertion sort: %ld %lf\n", swaps, t);
        }
        if(c == 1)
        {
                clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
                swaps = BubbleSort(A2, n);
                clock_gettime(CLOCK_REALTIME, &end); //end timestamp
                t = time_elapsed(start, end);
                printf("Bubble sort: %ld %lf\n", swaps, t);
        }
        if(c == 2)
        {
                clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
                swaps = SelectionSort(A3, n);
                clock_gettime(CLOCK_REALTIME, &end); //end timestamp
                t = time_elapsed(start, end);
                printf("Selection sort: %ld %lf\n", swaps, t);
        }
        
}
*/








