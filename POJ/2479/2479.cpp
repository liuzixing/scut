#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int lsum[50001],rsum[50001],i,n,t,a[50001],max,b[50001];
	cin >> t;
	while (t)
	{
		t--;
		scanf ("%d",&n);
		for (i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		lsum[0] = a[0];
		rsum[n -1] = a[n - 1];
		b[0] = a[0];
		max = -30000;
		for (i = 1;i < n;i++)
		{
			b[i] = (a[i] > b[i - 1] + a[i] ) ? a[i]:b[i - 1] + a[i];
			max = (max < b[i]) ? b[i] :max;
			lsum[i] =max;
		}
		b[n - 1] = a[n - 1];
		max = -30000;
		for (i = n - 2;i >= 0;i--)
		{
			b[i] = (a[i] > b[i + 1] + a[i] ) ? a[i] : b[i + 1] + a[i];
			max = (b[i] > max)?b[i] : max;
			rsum[i] = max;
		}
		max = -30000;
		for (i = 0;i < n - 1;i++)
		{
			max = (max < lsum[i] + rsum[i + 1]) ? lsum[i] + rsum[i + 1] : max;
		}
		printf("%d\n",max);
	}
}