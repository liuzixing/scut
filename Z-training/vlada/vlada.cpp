#include <iostream>
#include <cstdio>
using namespace std;

int n,a[20],i,j,m,ans,sum,tem;

int main()
{
	scanf("%d",&n);
	m = 1 << n;
	for (i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	sum /= 2;
	for (i = 1;i < m;i++)
	{
		tem = 0;
		for (j = 0;j < n;j++)
			if (i & (1 << j))
				tem += a[j];
		if (tem > sum)
			ans++;
	}
	printf("%d\n",ans);
}