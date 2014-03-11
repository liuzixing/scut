#include <iostream>
#include <cstdio>
#include <cmath>
#include <memory.h>
#include <ctime>
#include <algorithm>
using namespace std;
clock_t start,finish;
const int maxn = 65535;
double f[maxn];
struct node
{
	int x,u,v;
	double y;
}a[256];
int b[32];

int n,t,k,i,j,x;
double g[32][32];

bool cmp(node i,node j)
{
	return i.x < j.x;
}
int main()
{
	//start = clock();
	b[1] = 1;
	for (i = 2;i <= 17;i++)
		b[i] = b[i - 1] * 2;
	cin >> t;
	f[0] = 0;
	while (t--)
	{
		scanf("%d",&n);
		for (i = 1;i <= b[n + 1] - 1;i++)
			f[i] = -1000000000;
		for (i = 1;i <= n;i++)
			for (j = 1;j <= n;j++)
				scanf("%lf",&g[i][j]);
		k = 0;
		for (i = 1;i < n;i++)
			for (j =  i + 1;j <= n;j++)
			{
				a[++k].x = b[i] + b[j];
				a[k].u = b[i];
				a[k].v = b[j];
				a[k].y = g[i][j];
			}
		sort(a + 1,a + k + 1,cmp);
		for (i = 3;i <= b[n + 1] - 1;i++)
		{
			x = i;
			x = (x & 0x55555555) + ((x >> 1) & 0x55555555); 
			x = (x & 0x33333333) + ((x >> 2) & 0x33333333); 
			x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F); 
			x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF); 
			x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);
			if (x % 2) continue;
			for (j = 1;j <= k && a[j].x <= i;j++)
				if ((a[j].u & i) && (a[j].v & i) && (f[i] < f[i - a[j].x] + a[j].y))
						f[i] = f[i - a[j].x] + a[j].y;
		}
		printf("%.2lf\n",f[b[n + 1] - 1]);
	}
	//finish = clock();
	//printf("%lf\n",double(finish - start) /CLOCKS_PER_SEC);
}