#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int money[6] = {100,50,10,5,2,1};
int main()
{
	int i,j,n,t;
	while (cin >> n && n != 0)
	{
		int ans = 0;
		for (i = 0;i < n;i++)
		{
			scanf("%d",&t);
			for (j = 0;j < 6;j++)
			{
				ans += t / money[j];
				t -= t / money[j] * money[j];
			}
		}
		printf("%d\n",ans);
	}
}