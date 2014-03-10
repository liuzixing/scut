#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int judge (__int64 p)
{
	int x = (int)sqrt(double(p));
	int i;
	for (i = 2;i <= x;i++)
	{
		if (p % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	__int64 a,p,d[32],ans,tt,pp;
	d[0] = 1;
	while (scanf("%I64d %I64d",&p,&a) && a && p)
	{
		if (judge(p))
		{
			printf("no\n");
			continue;
		}
		d[0] = a;
		pp = p;
		tt = 1;
		int c = 0;
		while (tt <= p)
		{
			d[c + 1] = d[c] * d[c] % p;
			tt *= 2;
			c++;
		}
		ans = 1;

		while (tt > 0 && p)
		{
			if (p - tt >= 0)
			{
				p -= tt;
				ans = ans * d[c] % pp;
			}
			c--;
			tt /= 2;
		}
		if (ans == a)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}

}