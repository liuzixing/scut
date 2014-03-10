#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int t,f[1001],value[1001],volume[1001],n,v,i,j;
	cin >> t;
	while (t--)
	{
		scanf("%d %d",&n,&v);
		for (i = 1;i <= n;i++)
		{
			scanf("%d",&value[i]);
		}
		for (i = 1;i <= n;i++)
		{
			scanf("%d",&volume[i]);
		}
		memset(f,0,sizeof(f));
		for (i = 1;i <= n;i++)
		{
			for (j = v;j >= volume[i];j--)
			{
				f[j] = (f[j] < f[j - volume[i]] + value[i]) ? f[j - volume[i]] + value[i] : f[j];
			}
		}
		printf("%d\n",f[v]);
	}
}