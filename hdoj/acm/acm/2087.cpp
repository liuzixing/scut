#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int p[1001],i,j;
	char a[1001],b[1001];
	while (scanf("%s",&a) && strcmp(a,"#"))
	{
		scanf("%s",&b);
		for (i = 0;i < strlen(b);i++)
		{
			p[i] = -1;
		}
		j = -1;
		for (i = 1;i < strlen(b);i++)
		{
			while (b[i] != b[j + 1] && j >= 0)
			{
				j = p[j];
			}
			if (b[i] == b[j + 1])
			{
				j++;
			}
			p[i] = j;
		}
		j = -1;
		int ans = 0;
		for (i = 0;i < strlen(a);i++)
		{
			while (a[i] != b[j + 1] && j >= 0)
			{
				j = p[j];
			}
			if (a[i] == b[j + 1])
			{
				j++;
			}
			if (j == strlen(b) - 1)
			{
				ans++;
				j = -1;
			}
		}
		printf("%d\n",ans);
	}
}