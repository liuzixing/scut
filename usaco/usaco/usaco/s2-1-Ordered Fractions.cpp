/*
ID: benbenq1
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct node
{
	int numerator,denominator;
}a[30000];
int gcd(int a,int b)
{
	if (a % b == 0)
	{
		return b;
	}
	return gcd(b,a % b);
}
bool cmp(node x,node y)
{
	return x.numerator * y.denominator < x.denominator * y.numerator;
}
int main()
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	int n,i,j;
	scanf("%d",&n);
	a[0].numerator = 0;
	a[0].denominator = 1;
	a[1].numerator = 1;
	a[1].denominator = 1; 
	int len = 2;
	for (i = 1;i <  n;i++)
	{
		for (j = i + 1;j <= n;j++)
		{
			if (gcd(i,j) == 1)
			{
				a[len].numerator = i;
				a[len++].denominator = j;
			}
		}
	}
	sort(a + 1,a + len,cmp);
	for (i = 0;i < len;i++)
	{
		printf("%d/%d\n",a[i].numerator,a[i].denominator);
	}
}