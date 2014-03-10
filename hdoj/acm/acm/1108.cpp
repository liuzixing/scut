#include <iostream>
#include <stdio.h>

using namespace std;
int gcd(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}
	return gcd(b,a % b);
}
int lcm(int a,int b)
{
	return(a * b / gcd(a,b));
}
int main()
{
	int a,b;
	while (scanf("%d %d",&a,&b)!=EOF)
	{
		printf("%d\n",lcm(a,b));
	}

}