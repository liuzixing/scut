#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
__int64 c(int n,int k)
{
	if (n - k < k)
	{
		k = n - k;
	}
	int i;
	__int64 tem = 1;
	for (i = n;i > n - k;i--)
	{
		tem *= i;
	}
	for (i = k;i > 1;i--)
	{
		tem /= i;
	}
	return tem;
}
int main()
{
	int t,n,i;
	__int64 ans[21] = {0};
	ans[1] = 1;
	for (i = 2;i < 21;i++)
	{
		for (int j = i - 1;j > 0;j--)
		{
			ans[i] += j * c(i - 1,j);
		}
		ans[i] += int(pow(2.0,double (i - 1)));
	}
	cin >> t;
	while (t--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}

}