#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n,m,i,j,f[10001],a;
	while (scanf("%d %d",&n,&m) != EOF)
	{
		memset(f,0,sizeof(f));
		for (i = 0;i < n;i++ )
		{
			scanf("%d",&a);
			for (j = a;j <= m;j++)
			{
				if (f[j] < f[j - a] + 1)
				{
					f[j] = f[j - a] + 1;
				}
			}
		}
		printf("%d\n",f[m]);
	}
	
}