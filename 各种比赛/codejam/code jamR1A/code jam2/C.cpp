#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t,n,m;
struct node
{
	int c,s,t;
}a[100],b[100],desk[100];
bool cmp(node x,node y)
{
	if (x.t == y.t)
	{
		if (x.c == y.c)
			return x.s > y.s;
		return x.c > y.c;
	}
	return x.t > y.t;
}
int main()
{
	int i,j,left,score,cases = 0,k,x,y,z,na,nb;
	cin >> t;
	while (t--)
	{
		scanf("%d",&n);
		for (i = 1,k = 0,j = 0;i <= n;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			if (z > 0)
			{
				b[++k].s = y;b[k].c = x;b[k].t = z;
			}
			else
			{
				a[++j].s = y;a[j].c = x;a[j].t = z;
			}
		}
		na = j;
		nb = k;
		scanf("%d",&m);
		for (i = 1;i <= m;j++)
			scanf("%d %d %d",&desk[i].c,&desk[i].s,&desk[i].t);
		left = 1;
		score = 0;
		j = 1;
		k = 1;
		i = 1;
		while (left)
		{
			while (k <= nb)
			{
				score += b[k].s;
				left += b[j].t;
				while (b[k].c-- && i <= m)
				{
					if (desk[i].t > 0)
					{
						b[++nb].s = desk[i].s;b[nb].c = desk[i].c;b[nb].t = desk[i].t;
					}
					else
					{
						a[++na].s = desk[i].s;a[na].c = desk[i].c;a[na].t = desk[i].t;
					}
					i++;
				}
			}
		}
		
	}
}