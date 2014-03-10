#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int f[1001][1001];
int main()
{
	char a[1001],b[1001];
	int i,j,la,lb;
	while (scanf("%s %s",&a,&b) != EOF)
	{
		la = strlen(a);
		lb = strlen(b);
		for (i = 1;i <= la;i++)
		{
			for (j = 1;j <= lb;j++)
			{
				if (a[i - 1] == b[j - 1])
				{
					f[i][j] = f[i - 1][j - 1] + 1;
				}
				else
				{
					f[i][j] = max(f[i - 1][j],f[i][j - 1]);
				}
			}
		}
		printf("%d\n",f[la][lb]);
	}
}