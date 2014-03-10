#include <iostream>
#include <stdio.h>

using namespace std;
double c(int n,int k)
{
	double i,a = 1.0;
	if (k == 0) 
	{
		return 1.0;
	}
	for (i = 1.0;i <= k;i++)
	{
		a = a * (n - i + 1);
	}
	for (i = 1.0;i <= k;i++)
	{
		a = a / i;
	}
	return a;
}
int main()
{
	int n,i,mid;
	double ans,d[26];
	d[1] = 0;
	d[2] = 1;
	d[0] = 1;
	for (i = 3;i < 26;i++)
	{
		d[i] = (i - 1.0) * (d[i - 2] + d[i - 1]);
	}

	while (cin >> n && n)
	{
		mid = n / 2;
		ans = 0;
		for (i = mid;i >= 0;i--)
		{
			ans += c(n,n - i) * d[i];
		}
		printf("%.lf\n",ans);
	}

}