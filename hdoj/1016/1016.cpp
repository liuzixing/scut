#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int n,v[21],ans[21];
bool prime[40];
void dfs(int x)
{
	int i;
	if (ans[0] == n && prime[ans[ans[0]] + 1])
	{
		for (i = 1;i < n;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("%d\n",ans[n]);
		return;
	}
	x = x + 1;
	if (x % 2 == 1)
	{
		i = 3;
	}
	else
	{
		i = 2;
	}
	for(;i <= n;i += 2)
	{
		if (v[i] ==0 && prime[i + ans[ans[0]]])
		{
			v[i] = 1;
			ans[0]++;
			ans[ans[0]] = i;
			dfs(i);
			v[i] = 0;
			ans[0]--;
		}
	}
	return;
}
int main()
{
	int i,j;
	prime[1] = 0;
	prime[2] = 1;
	for (i = 3;i < 40;i += 2)
	{
		bool flag = false;
		for (j = 2;j <= sqrt(double (i)) ;j++)
		{
			if (i % j == 0)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			prime[i] = 1;
		}
	}
	i = 0;

	while (cin >> n)
	{
		i++;
		if (n % 2 == 1)
		{
			continue;
		}
		printf("Case %d:\n",i);
		memset(v,0,sizeof(v));
		memset(ans,0,sizeof(ans));
		v[1] = 1;
		ans[1] = 1;
		ans[0] = 1;
		dfs(1);
		printf("\n");
	}
}