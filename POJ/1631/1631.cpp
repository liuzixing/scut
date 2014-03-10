#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,p,i,l,r,mid;
	int a[40001],f[40001],b[40001];
	cin >> n;
	while (n)
	{
		n--;
		b[0] = 1;
		scanf("%d",&p);
		scanf("%d",&a[1]);
		b[1] = a[1];
		int max = -4000000;
		for (i = 2;i <= p;i++)
		{
			f[i] = 1;
			scanf("%d",&a[i]);
			l = 1;
			r = b[0];
			while (l < r - 1)
			{
				mid = (l + r) / 2;
				r = (b[mid] > a[i]) ? mid:r;
				l = (b[mid] < a[i]) ? mid :l;
			}
			if (a[i] < b[l] && r > 1)
			{
				r--;
			}
			if (a[i] < b[r])
			{
				b[r] = a[i];
			} 
			else
			{
				b[0]++;
				b[b[0]] = a[i];
				r++;
			}
			f[i] = r;
			max = (max <f[i])? f[i] : max;
		}
		printf("%d\n",max);
	}
}