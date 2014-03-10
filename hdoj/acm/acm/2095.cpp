#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int i,n,ans,a;
	while (cin >> n && n)
	{
		ans = 0;
		for (i = 0 ;i < n;i++)
		{
			scanf("%d",&a);
			ans = ans ^ a;
		}
		printf("%d\n",ans);
	}
}
