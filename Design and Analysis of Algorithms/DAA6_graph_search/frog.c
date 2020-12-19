#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "graphSearch.h"

#define N 5

bool iscycle(int u,bool visited[],int parent,const int graph[][N])
{
	visited[u]=true;
	for(int v=0;v<N;v++)
	{
		if(graph[u][v])
		{
			if(!visited[v])
			{	
				if(iscycle(v,visited,u,graph))
				{
					return true;
				}	
			}
			else if(v!=parent)
			{
				return true;
			}
		}
	}
	return false;
}



bool isTree(int n, const int graph[][N])
{

	bool visited[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}

	if(iscycle(0,visited,-1,graph))
	{
		return false;
	}

	for(int j=0;j<n;j++)
	{
		if(!visited[j])
		{
			return false;
		}
	}

	return true;
}

void dfs(int *visited, int v, int n, const int arr[][n])
{
	visited[v] = 1;
	for(int i = 0; i < n ; i++)
	{
		if(arr[v][i] && !visited[i])
		{
			dfs(visited, i, n, arr);
		}
	}
}

Result pepesAnswers(int n, const int safeSeq[][n])
{
	int visited[n];
	int cv[n];
	int count = 0;
	int max = -1;
	Result ar;
	for(int i = 0 ; i< n; i++)
	{
		visited[i] = 0;
		cv[i] = 0;
	}
	for(int i = 0 ; i< n; i++)
	{
		if(!visited[i])
		{
			count++;
			int no = 0;
			dfs(visited,i,n,safeSeq);
			for(int j = 0 ; j< n; j++)
			{
				if(visited[j] && !cv[j])
				{
					cv[j] = 1;
					no++;
				}
			}
			if(no>max)
			max = no;
		}
	}
	ar.numDeliveryFrogs = count;
	ar.maxHouses = max;
	return ar;
}



Result pepesAnswersWithK(int n, const int safeSeq[][n], int k)
{
	Result r;
	return r;

}

/*


int main()
{

	int safeSeq[N][N] = {{0, 1, 1, 0, 0},
						 {1, 0, 0, 0, 0},
						 {1, 0, 0, 0, 0},
						 {0, 0, 0, 0, 1},
						 {0, 0, 0, 1, 0}};
	Result ans=pepesAnswers2(N,safeSeq, );
printf("%d %d",ans.numDeliveryFrogs, ans.maxHouses);
	



}

*/



