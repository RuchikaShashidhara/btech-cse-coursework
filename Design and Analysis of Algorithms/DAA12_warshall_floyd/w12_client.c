// Client file for w12_server.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Including the header file
#include "session12_WarshallsFloyds.h"

// Helper functions for displaying input, output and total time elapsed
static void inputGraph(int **graph, int n);
static void displayGraph(int **graph, int n);
static double timeElapsed(struct timespec start, struct timespec end);

// Main function
int main()
{
	// t1 - time elapsed for Warshall's Algorithm
	// t2 - time elapsed for Floyd's Algorithm
	struct timespec start1, end1, start2, end2;
	double t1, t2;

	// n1 - no. of nodes in undirected graph1 - edge adjacency matrix (Warshall's Algorithm) 
	// n2 - no. of nodes in undirected graph2 - weight adjacency matrix (Floyd's Algorithm) 
	int n1, n2, i;
	
	// Taking input for graph1
	scanf("%d", &n1);
	int g1[n1][n1], *aux1[n1], **graph1;
	graph1 = (int**)aux1;
	for(i = 0; i < n1; i++)
	{
		aux1[i] = (int*)g1 + (i * n1);
	}
	inputGraph(graph1, n1);

	// Taking input for graph2
	scanf("%d", &n2);
	int g2[n2][n2], *aux2[n2], **graph2;
	graph2 = (int**)aux2;
	for(i = 0; i < n2; i++)
	{
		aux2[i] = (int*)g2 + (i * n2);
	}
	inputGraph(graph2, n2);
	
	// Applying Warshall's Algorithm
	clock_gettime(CLOCK_REALTIME, &start1);
	transitive_closure_warshalls(graph1, n1);
	clock_gettime(CLOCK_REALTIME, &end1);	
	t1 = timeElapsed(start1, end1);	
	
	// Applying Floyd's Algorithm
	clock_gettime(CLOCK_REALTIME, &start2);
	all_pairs_shortest_path_distances_floyds(graph2, n2);
	clock_gettime(CLOCK_REALTIME, &end2);	
	t2 = timeElapsed(start2, end2);
	
	// Displaying graph1 and graph2 after applying Warshall's and Floyd's Alorithms
	displayGraph(graph1, n1);
	printf("\n");
	displayGraph(graph2, n2);
	
	// Displaying the time elapsed in milliseconds for Warshall's and Floyd's Alorithms
	printf("%lf sec.\n", t1);
	printf("%lf sec.\n", t2);	
}

// Function to input graph[n][n] in adjacency matrix form
static void inputGraph(int **graph, int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
}

// Function to display graph[n][n] in adjacency matrix form
static void displayGraph(int **graph, int n)
{
	int i,j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}

// Function to calculate total time elapsed for a particular function
static double timeElapsed(struct timespec start, struct timespec end)
{
	double tt;
	tt = (end.tv_sec - start.tv_sec);				  
	tt += (end.tv_nsec - start.tv_nsec) * 0.000000001;
	return tt*1000;
}
