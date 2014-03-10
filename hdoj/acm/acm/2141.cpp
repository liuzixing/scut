#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

void init(int x,int a[])
{
	int i;
	for (i = 0;i < x;i++)
	{
		scanf("%d",&a[i]);
	}
	return;
}

void mixab(int l,int n,int a[],int b[],int ab[])
{
	int i,j,x = 0;
	for (i = 0;i < l;i++)
	{
		for (j = 0;j < n;j++)
		{
			ab[x] = a[i] + b[j];
			x++;
		}
	}
	return;
}
bool find(int x,int l,int r,int ab[])
{
	int mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (ab[mid] == x)
			return true;
		if (x > ab[mid])
			l = mid + 1;
		else
			r = mid - 1;
	}
	return false;
}
int main()
{
	int a[501],b[501],c[501],ab[250001];
	int l,n,m,t,s,i,count = 0;
	while (cin >> l >> n >> m)
	{
		count++;
		
		init(l,a);
		init(n,b);
		init(m,c);
		mixab(l,n,a,b,ab);
		sort(ab,ab + n * l);
		cin >> t;
		printf("Case %d:\n",count);
		while (t--)
		{
			scanf("%d",&s);
			for (i = 0;i < m;i++)
			{
				if (find(s - c[i],0,l * n - 1,ab))
				{
					printf("YES\n");
					break;
				}
			}
			if (i == m)
			{
				printf("NO\n");
			}
		}
	}
}