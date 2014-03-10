#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t,c,f[101],h,n,m,p,i,j,k;
	cin >> t;
	while (t--)
	{
		scanf("%d %d",&n,&m);
		memset(f,0,sizeof(f));
		for (i = 0;i < m;i++)
		{
			scanf("%d %d %d",&p,&h,&c);
			for (j = c;j > 0;j--)
			{
				for (k = n;k >= p;k--)
				{
					if (f[k] < f[k - p] + h)
					{
						f[k] = f[k - p] + h;
					}
				}
			}
		}
		printf("%d\n",f[n]);
	}
}