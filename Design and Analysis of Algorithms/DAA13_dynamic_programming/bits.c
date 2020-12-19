#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long int count_strings(long int n)
{
	long int count[n+1];
	for(long int i=3;i<=n;++i)
	   count[i] = 0;
	count[0]=count[1]=count[2]=0;
	for(long int i=3;i<=n;++i)
	{
		count[i]=count[i-1]+count[i-2]+count[i-3]+ (long int)pow(2,i-3);
	}
	if(count[n]==0)
	  return 0;
	return count[n];
}
int main()
{
	long int n;
	scanf("%ld", &n);
	long int ans;
	ans = count_strings(n);
	printf("\n%ld",ans);
	return 0;
}
