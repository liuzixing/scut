#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,a[10001];
	while (cin >> n)
	{
	i = 0;
	while (i < n )
	{
		scanf("%d",&a[i]);
		i++;
	}
	sort(a,a + n);
	printf("%d\n",a[n / 2]);
	}
}