#include <stdio.h>
#include <stdlib.h>
#include "tsp.h"

#define max __INT_MAX__
int* graphPath;
int* finalPath;

/**
 * Starting from node 0 recurisivly compute and return the minimum cost.*
 * graph[i][j] is the cost moving from node i to node j.*
 * At every function call currentCost contains the cost of the path traversed till now,*
 * nodesVisited is the number of visited nodes in the current path.*
 * When a path is completed commpare its cost to mincost, return minimum of both, backtrack*
 * and compute the costs of the other paths, return the minimum of all of them.*
 * If at any stage the currentCost becomes greater than the mincost backtrack from that point.
 */
int tspBacktrackRecursive(int v, int n, int graph[][n], bool *visited, int nodesVisited, int currentCost, int minCost)
{
	if(currentCost < minCost)
    	{        
		int i, j;
		visited[v] = true;
		nodesVisited += 1;
		graphPath[nodesVisited - 1] = v;		
		if(nodesVisited == n)
		{
			visited[v] = false;
			if(graph[v][0] + currentCost < minCost)
			{
				for(i = 0; i < n; i++)
				{
					finalPath[i] = graphPath[i];
				}
				graphPath[nodesVisited - 1] = 0;
				return (graph[v][0] + currentCost);
			}
			return minCost;
		}
		for(j = 0; j < n; j++)
		{
			if(!visited[j])
			{
				minCost = tspBacktrackRecursive(j, n, graph, visited, nodesVisited, currentCost + graph[v][j], minCost);
			}
		}
		graphPath[nodesVisited - 1] = 0;
		visited[v] = false; 
		return minCost;
    	}
	else
    	{
    		return minCost;
    	}
}

/**
 * Compute the minimum cost required to visit all nodes using the tspBacktrackRecursive() function 
 */
int tspBackTrack(int n, int graph[][n])
{
	bool* visited = (bool*)calloc(n, sizeof(bool));
	graphPath = (int*)calloc(n, sizeof(int));	
	finalPath = (int*)calloc(n, sizeof(int));
	return tspBacktrackRecursive(0, n, graph, visited, 0, 0, max);
}

/**
 * Print the minimum cost path
 */
int *printPath(int n, int graph[][n])
{
    	return finalPath;
}
