#include "horspool.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int* buildShiftTable(char *pattern)
{
    int* table = (int*)malloc(sizeof(int)*256);
    int m = strlen(pattern);
    for(int i=0;i<256;++i)
        table[i]=m;
    for(int j=0; j<m-1; ++j)
    {
        table[pattern[j]]=m-1-j;
    }
    return table;
}

Result *horspoolStringMatch(char *pattern, char *text)
{
    //printf("Inside horspool function\n");
    int* table = buildShiftTable(pattern);
    Result* res = (Result*)malloc(sizeof(Result));
    res->charactersCompared=0;
    res->firstOccurrence=-1;
    res->lastOccurrence=-1;
    res->numOccurrences=0;
    int m = strlen(pattern), n = strlen(text);
    int i = m-1, k;
    int found=0;
    while(i<=n-1)
    {
        //printf("Value of i: %d\n", i);
        k=0;
        while(pattern[m-1-k]==text[i-k] && k<m)
        {
            k+=1;
            res->charactersCompared+=1;
        }
        if(k==m)
        {
            res->numOccurrences+=1;
            if(found==0)
            {
                found=1;
                res->firstOccurrence=i-m+1;
                //printf("Found at %d\n", i-m+1);
            }            
            else if(found==1)
            {
                res->lastOccurrence=i-m+1;
                //printf("Found at %d\n", i-m+1);
            }
            i+=table[text[i]];
        }
        else
        {
            i+=table[text[i]];
            res->charactersCompared+=1;
        }
    }
    return res;
}
