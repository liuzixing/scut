#include <iostream> 
#include <cstdlib> 
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n,m,k,s,a[101],b[101],i,j,u;
	int f[101][101],ans;
	while (scanf("%d %d %d %d",&n,&m,&k,&s) != EOF)
	{
		memset(f,0,sizeof(f));
		bool flag = 1;
		for(i = 0;i < k;i++)
			scanf("%d %d",&a[i],&b[i]);
		for (j = 0;j <= m && flag;j++)
		{
			for (i = 0;i < k;i++)
				for (u = 1;u <= s;u++)
					if (j >= b[i] && f[j][u] < f[j - b[i]][u - 1] + a[i])
						f[j][u] = f[j - b[i]][u - 1] + a[i];
			if (f[j][s] >= n)
			{
				ans = m - j;
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",ans);
	}

}