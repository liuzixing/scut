#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;
unsigned long  allgcd;
unsigned long  gcd(int a,int b)
{
	if (a % b == 0)
	{
		return b;
	}
	return gcd(b,a % b);
}
unsigned long  lcm (int a,int b)
{
	return a * b / gcd(a,b);
}
int main()
{
	unsigned long  i,n,ans,t;
	while (cin >> n)
	{
		scanf("%lu",&t);
		ans = t;
		for (i = 1;i < n;i++)
		{
			scanf("%lu",&t);
			ans = lcm(ans,t);
		}
		printf("%lu\n",ans);
	}
}