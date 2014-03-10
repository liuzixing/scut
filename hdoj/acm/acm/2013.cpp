#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
	int n,i,ans;
	while (cin  >> n)
	{
		ans = 1;
		for (i = 1;i < n;i++)
		{
			ans = (ans + 1) * 2;
		}
		printf("%d\n",ans);
	}
}