#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int gcd(int a,int b)
{
	if (b == 0)
		return a;
	return gcd(b,a % b);
}
int main()
{
	int n,a,b;
	cin >> n;
	while (n--)
	{
		scanf("%d %d",&a,&b);
		for (int c =2 * b;;c += b)
		{
			if (gcd(a,c) == b)
			{
				printf("%d\n",c);
				break;
			}
		}
	}
}