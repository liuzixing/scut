#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <ctype.h>
using namespace std;

int n,i;
__int64 k,ans,total;
struct node
{
	__int64 x, p;
}a[10010];

bool cmp(node x,node y)
{
	return x.x < y.x;
}

void doit()
{
	int l,r,i;
	__int64 sum,sumk,t;
	ans = 0;
	for (i = 1;i <= n;i++)
	{
		bool flag = 1;
		sum = a[i].p;
		sumk = 0;
		l = i - 1;
		r = i + 1;
		while (flag)
		{
			if (a[i].x - a[l].x < a[r].x - a[i].x )
			{
				if (k - sumk >= (a[i].x - a[l].x) * a[l].p)
				{
					sumk += (a[i].x - a[l].x) * a[l].p;
					sum += a[l].p;
					l--;
					flag = 1;
				}
				else
				{
					sum += (k - sumk) / (a[i].x - a[l].x);
					sumk += sum * (a[i].x - a[l].x);
					l--;
					break;
				}
			}
			else
			{
				if (k - sumk >= (a[r].x - a[i].x) * a[r].p)
				{
					sumk += (a[r].x - a[i].x) * a[r].p;
					sum += a[r].p;
					flag = 1;
					r++;
				}
				else
				{
					sum += (k - sumk) / (a[r].x - a[i].x);
					sumk += sum * (a[r].x - a[i].x);
					r++;
					break;
				}
			}
		}
		if (sum == total)
		{
			ans = total;
			return;
		}
		if (sum > ans)
			ans = sum;
	}
}
__int64 getint()
{
	__int64 ret = 0;
	char tmp;
	while (!isdigit(tmp = getchar()));
	do{
		ret = (ret << 3) + (ret << 1) + tmp - '0';
	}while (isdigit(tmp = getchar()));
	return ret;
}
int main()
{
	while (scanf("%d %I64d",&n,&k) != EOF)
	{
		total = 0;
		for (i = 0;i < n;i++)
		{
			a[i].x = getint();
			a[i].p = getint();
			total += a[i].p;
		}
		a[n].p = 1000000, a[n].x = -100000000000000; 
		a[n + 1].p = 1000000, a[n + 1].x = 100000000000000; 
		sort(a,a + n + 2,cmp);
		doit();
		printf("%I64d\n",ans);
	}
}