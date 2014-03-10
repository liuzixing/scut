#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int p,e,i,d,k = 1,ans;
	scanf("%d %d %d %d",&p,&e,&i,&d);
	while (p+d+e+i != -4)
	{
		p %= 23;
		e %= 28;
		i %= 33;
		ans = (5544 * p + 14421 * e + 1288 * i + 21252 - d) % 21252;
		if (ans == 0)
		{
			ans = 21252;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n",k,ans);
		scanf("%d %d %d %d",&p,&e,&i,&d);
		k++;
	}
}