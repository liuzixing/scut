#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct node
{
	char name[10];
	int sum,total;
} a[1001] = {0};
bool cmp(node x,node y)
{
	if (x.total == y.total)
	{
		if (x.sum == y.sum)
		{
			return strcmp(x.name,y.name) > 0;
		}
		return x.sum > y.sum;
	}
	return x.total < y.total;
}
int main()
{
	int t,f,m,n,i,j,judge;
	char c[10];
	cin >> n >> m;
	for (i = 0;scanf("%s",&a[i].name) != EOF;i++)
	{
		for (j = 0;j < n;j++)
		{
			scanf("%s",&c);
			judge = sscanf(c,"%d(%d)",&t,&f);
			if ( judge == 2)
			{
				a[i].total++;
				a[i].sum += t + f * m;
			}
			else
			{
				if (judge == 1 && t > 0)
				{
					a[i].total++;
					a[i].sum += t;
				}
			}
		}
	}
	sort(a,a+i,cmp);
	for (i--;i >= 0;i--)
	{
		printf("%-10s %2d %4d\n",a[i].name,a[i].total,a[i].sum);
	}
}