#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
//Ì°ÐÄ
struct node
{
	int reduce,day;
}a[1001];
int n,t,ans;
int mark[1001];

bool cmp(node x,node y)
{
	if (x.reduce == y.reduce)
	{
		return x.day < y.day;
	}
	else
		return x.reduce > y.reduce;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans = 0;
		memset(mark,0,sizeof mark);
		scanf("%d",&n);
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i].day);
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i].reduce);
		sort(a,a + n,cmp);
		for (int i = 0;i < n;i++)
		{
			int j;
			for (j = a[i].day; j > 0;j--)
				if (mark[j] == 0)
				{
					mark[j] = 1;
					break;
				}
			if (!j)
				ans += a[i].reduce;
		}
		printf("%d\n",ans);
	}
}