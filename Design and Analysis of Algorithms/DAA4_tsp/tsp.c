#include<stdlib.h>
#include<stdio.h>
#include "tsp.h"
// Given a permutation of path - P[], 
// Return the cost from the starting city through the path and back
// P[0] -> P[1] -> ... -> P[n-1] -> P[0]
int getCost(int n, int graph[][n], int *P)
{
    int cost = 0,start,end;
    for(int i=0;i<n-1;++i)
    {
        start = P[i], end=P[i+1];
        cost+=graph[start][end];
    }
    return cost+graph[P[n-1]][P[0]];
}

//Finds a solution for the traveling salesman problem
//Returns the cost of a min-cost Hamiltonian circuit of the given
//directed complete graph with n vertices in the form a cost matrix.
int tsp(int n, int graph[][n])
{
    int minCost,c;
    int* p =(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;++i)
    {
        p[i]=i;
    }
    minCost=getCost(n,graph,p);
    do{
        c = getCost(n, graph, p);
        if(minCost > c)
            minCost = c;
        printf("cost = %d perm = ", c);
        for(int i=0;i<n;++i)
        {
            printf("%d ", p[i]);
        }
        printf("\n");
    }while(get_next_permutation(p,n));
    return minCost;
}

// Returns an array of size n, 
// starting at city_0 (that is the first node) 
// traversing the path with min-cost
// Note: Return the path which is lexicographically smaller in case two paths have the same cost
int* printPath(int n, int graph[][n])
{
    int minCost=tsp(n,graph);
    int* p =(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;++i)
    {
        p[i]=i;
    }
    do{
        int cost = getCost(n,graph,p);
        if(cost==minCost)
            return p;
    }while(get_next_permutation(p,n));
    return NULL;
}