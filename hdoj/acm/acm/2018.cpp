#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

void init (int ans[],int a[])
{
	int i;
	a[0] = 0;a[1] =0;a[2] =0;a[3] =1;
	for (i = 2;i < 56;i++)
	{
		a[3] += a[2];
		a[2] = a[1];
		a[1] = a[0];
		a[0] = a[3];
		ans[i] = a[0] + a[1] + a[3] + a[2];
	}
	ans[1] = 1;
	/*ans[2] = 2;
	ans[3] = 3;
	ans[4] = 4;
	ans[5] = 6;
	for (i = 5;i < 56;i++)
	{
		ans[i] = ans[i - 3] + ans[i -1];
	}*/
	return;
}
int main()
{
	int n,ans[56],a[4];
	init(ans,a);
	while (cin >> n)
	{
		if (!n)
		{
			break;
		}
		printf("%d\n",ans[n]);
	}
}