#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct node
{
	int l,r;
}d[101];

bool cmp(const struct node x,const struct node y)
{
	return x.r < y.r;
}
int main()
{
	int i,j,n;
	while (cin >> n && n != 0)
	{
		int ans = 1;
		for (i = 0;i < n;i++)
		{
			scanf("%d %d",&d[i].l,&d[i].r);
		}
		sort(d,d+n,cmp);
		for (i = 0;i < n - 1;i++)
		{
			for (j = i + 1;j < n;j++)
			{
				if (d[i].r <= d[j].l)
				{
					ans ++ ;
					i = j - 1;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
}