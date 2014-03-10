#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int n,v[21],ans[21];
bool prime[38] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};  
void dfs(int x)
{
	int i;
	if (ans[0] == n && prime[ans[ans[0]] + 1])
	{
		for (i = 1;i < n;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
		return;
	}
	if (x % 2 == 1)
		i = 2;
	else
		i = 3;
	for(;i <= n;i += 2)
		if (v[i] == 0 && prime[i + ans[ans[0]]])
		{
			v[i] = 1;
			ans[0]++;
			ans[ans[0]] = i;
			dfs(i);
			v[i] = 0;
			ans[0]--;
		}
	return;
}
int main()
{
	int i = 0;
	while (scanf("%d",&n) != EOF)
	{
		i++;
		printf("Case %d:\n",i);
		memset(v,0,sizeof(v));
		v[1] = ans[1] = ans[0] = 1;
		dfs(1);
		printf("\n");
	}
}