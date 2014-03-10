#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
struct node 
{
	int p,t,index;
} a[101];
int score[10] = {50,60,65,70,75,80,85,90,95,100};
bool cmp(node x, node y)
{
	if (x.p == y.p)
	{
		return x.t < y.t;
	}
	else
	{
		return x.p > y.p;
	}
}
int main()
{
	int n,i,j,k;
	//c累计做了n题的人有多少个，cc累计对应题数的2半人数。。
	int h,m,s,ans[101],c[6],cc[10];
	while (cin >> n && n > 0)
	{
		memset(c,0,sizeof(c));
		memset(cc,0,sizeof(cc));
		for (i = 0;i < n;i++)
		{
			scanf("%d %d:%d:%d",&a[i].p,&h,&m,&s);
			a[i].t = h * 3600 + m * 60 + s;
			a[i].index = i;
			c[a[i].p]++;
		}
		sort(a,a + n,cmp);
		j = 5;
		cc[9] = c[5];
		cc[0] = c[0];
		for(i = 1,j = 1;i < 8;i+=2,j++)
		{
			cc[i] = c[j] - c[j] / 2;
			cc[i + 1] = c[j] / 2;
		}
		for (i = 0,j = 9;i < n;j--)
		{
			while (!cc[j])
			{
				j--;
			}
			for (k = 1;k <= cc[j];k++,i++)
			{
				ans[a[i].index] = score[j];
			}
		}
		for (i = 0;i < n;i++)
		{
			printf("%d\n",ans[i]);
		}
		printf("\n");
	}
}