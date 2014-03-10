#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int n,f;
double a[10001];
double l,r,mid;
const double e = 1e-6;
const double pi = 3.1415926535897932;
int cnt,x;
bool flag;
int main()
{
	int t,i;
	scanf("%d",&t);
	while (t--)
	{

		scanf("%d %d",&n,&f);
		f++;
		for (i = 0;i < n;i++)
		{
			scanf("%lf",&a[i]);
			a[i] = a[i] * a[i] * pi;
		}
		sort(a,a + n);
		r = a[n - 1];
		l = a[n - 1] / f;

		
		while (r - l > e)
		{
			mid = (r + l) / 2.0;
			cnt = 0;
			for (i = n - 1;i >= 0;i--)
			{
				x = 0;
				while (a[i] - (x + 1) * mid > e)
				{
					x++;
				}
				if (!x || cnt >= f)
					break;
				cnt += x;
			}
			if (cnt >= f)
				l = mid;
			else
				r = mid;
		}
		printf("%.4lf\n",l);
	}
}