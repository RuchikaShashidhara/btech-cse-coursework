#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#if 0
void test(char s[], int n)
{
	for(int i = 0; i < n / 2; ++i)
	{
		char ch = s[i]; s[i] = s[n - 1 - i]; s[n - 1 - i] = ch;
	}
}
#endif
void reverse(char s[], int l, int r)
{
	for(int i = l, j = r; i < j; ++i, --j)
	{
		char ch = s[i]; s[i] = s[j]; s[j] = ch;
	}
}

void what(char s[], int start, int end, int middle)
{
	reverse(s, start, middle  - 1);
	reverse(s, middle, end);
	reverse(s, start, end);
}
int main()
{
	char s[] = "abcdefghij";
	//test(s, 10);
	//reverse(s, 0, 9);
	//printf("what : %s\n", s);
	
	what(s, 0, 9, 6);
	printf("what : %s\n", s);
}
