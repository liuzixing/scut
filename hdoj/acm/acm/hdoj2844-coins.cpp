#include <iostream>
#include <stdio.h>

using namespace std;
const int b[17] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
int main()
{
	int n,m,a[101],c[101],i,j,k,ans,t;
	bool f[100001];
	while (scanf("%d %d",&n,&m) != EOF && (n + m))
	{
		memset(f,0,sizeof(f));
		f[0] = 1;
		for (i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		for (i = 0;i < n;i++)
		{
			scanf("%d",&c[i]);
		}

		while (n--)
		{
			for (k = 0;k  < 17 && c[n];k++)
			{
				if (c[n] - b[k] >= 0)
				{
					t = b[k];
					c[n] -= b[k];
				}
				else
				{
					t = c[n];
					c[n] = 0;
				}
				for (j = m;j >= t * a[n];j--)
				{
					if (f[j - t * a[n]])
					{
						f[j] = 1;
					}
				}
			}
		}
		ans = 0;
		for (i = 1;i <= m;i++)
		{
			if (f[i])
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}