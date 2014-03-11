#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct node 
{
	int a,p;
} milk[5001];
bool cmp(node x,node y)
{
	return x.p < y.p;
}
int main()
{
	int n,i,m,ans = 0;
	while (~scanf("%d %d",&n,&m)){
		ans = 0;
		for (i = 0;i < m;i++)
		{
			scanf("%d %d",&milk[i].p,&milk[i].a);
		}
		sort(milk,milk + m,cmp);
		for (i = 0;i < m && n;i++)
		{
			if(milk[i].a <= n)
			{
				n -= milk[i].a;
				ans += milk[i].p * milk[i].a;
			}
			else
			{
				ans += milk[i].p * n;
				n = 0;
			}
		}
	printf("%d\n",ans);
	}
}