#include <stdio.h>

int minCoins(int coins[], int m, int V) 
{     
    int table[V+1]; 
    table[0] = 0; 
  	int i, j;
    for (i=1; i<=V; i++) 
        table[i] = __INT_MAX__; 
  
    for (i=1; i<=V; i++) 
    { 
        for (j=0; j<m; j++) 
          if (coins[j] <= i) 
          { 
              int sub_res = table[i-coins[j]]; 
              if (sub_res != __INT_MAX__ && sub_res + 1 < table[i]) 
                  table[i] = sub_res + 1; 
          } 
    } 
    return table[V]; 
} 

int main()
{
	int t, i;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		int n, ans;
		int c[3];
		scanf("%d %d %d %d", &c[0], &c[1], &c[2], &n);
		ans = minCoins(c, 3, n);
		if(ans != __INT_MAX__)
			printf("%d\n", ans);
		else
			printf("ERROR\n");
	}
	return 0;

}





