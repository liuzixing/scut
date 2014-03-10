#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
	int n,i,j,k;
	char s[1001];
	scanf("%d%*c",&n);
	while (n--)
	{
		gets(s);
		int len = strlen(s);
		for (i = 0,j = 0;i < len;i++)
		{
			if (s[i] == ' ')
			{
				for (k = i - 1;k >= j;k--)
				{
					printf("%c",s[k]);
				}
				printf(" ");
				j = i + 1;
			}
		}
		for (k = i - 1;k >= j;k--)
		{
			printf("%c",s[k]);
		}
		printf("\n");
	}
}