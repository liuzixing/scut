#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	__int64 n,a,b,c,i,ans;
	cin >> n;
	while (n--)
	{
		scanf("%I64d %I64d %I64d",&a,&b,&c);
		a = a % c;
		ans = a;
		for (i = 1;i < b;i++)
		{
			ans = ans * a % c;
		}
		printf("%I64d\n",ans);
	}
}