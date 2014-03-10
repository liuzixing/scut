#include <iostream>
#include <stdio.h>

using namespace std;
const int MAX = 0x7fffffff;
int main()
{
	int f[50001],p,w,t,n,E,F,m,i,j;

	scanf("%d",&t);

	while (t--)
	{
		scanf("%d %d",&E,&F);
		m = F - E;
		f[0] = 0;
		for (i = 1;i <= m;i++)
		{
			f[i] = MAX;
		}
		scanf("%d",&n);
		for (i = 0;i < n;i++)
		{
			scanf("%d %d",&p,&w);
			for (j = w;j <= m;j++)
			{
				if (f[j - w] != MAX && f[j] > f[j - w] + p )
				{
					f[j] = f[j - w] + p;
				}
			}
		}
		if (f[m] != MAX)
		{
			printf("The minimum amount of money in the piggy-bank is %d.\n",f[m]);
		}
		else
		{
			printf("This is impossible.\n");
		}

	}

}