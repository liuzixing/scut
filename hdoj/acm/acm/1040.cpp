#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	int a[1001],n,i,t;
	cin >> t ;
	while (t--)
	{
		cin >> n;
		for (i = 0;i < n;i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a,a + n);
		for (i = 0;i < n - 1;i++)
		{
			printf("%d ", a[i]);
		}
		printf("%d\n", a[i]);
	}
}