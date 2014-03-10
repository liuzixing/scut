#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	double w,j,f;
}a[1001];
bool cmp(node x,node y)
{
	return x.w > y.w;
}
int main()
{
	double ans,m;
	int n,i;
	while (cin >> m >> n)
	{
		if (m == -1 && n == -1)
		{
			break;
		}
		for (i = 0;i < n;i++)
		{
			scanf("%lf %lf",&a[i].j,&a[i].f);
			if (a[i].f != 0)
			{
				a[i].w = a[i].j / a[i].f;
			}
			else
			{
				a[i].w = 10000;
			}
		}
		sort(a,a + n,cmp);
		i = 0;
		ans = 0;
		while (m > 0 && i < n)
		{
			if (m - a[i].f > 0)
			{
				ans += a[i].j;
				m -= a[i].f;
				i++;
			}
			else
			{
				ans += m * a[i].w;
				m = 0;
			}
		}
		printf("%.3lf\n",ans);
	}

}