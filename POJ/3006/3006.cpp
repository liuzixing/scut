#include <iostream>
#include <stdio.h>
const int maximum = 100001;
using namespace std;
void createprime (int prime[])
{
	int i,j;
	prime[1] = 1;
	for (i = 2;i < sqrt(double (maximum)) + 1;i++)
	{
		for (j = i * 2;j < maximum;j+=i )
		{
			prime[j] = 1;
		}
	}
}
int main()
{
	int prime[maximum],n,d,a;
	memset(&prime,0,sizeof(prime));
	createprime(prime);
	scanf("%d %d %d",&a,&d,&n);
	while (a + d + n != 0)
	{
		while (n)
		{
			if (!prime[a])
			{
				n--;
			}
			a +=d;
		}
		printf("%d\n",a - d);
		scanf("%d %d %d",&a,&d,&n);
	}
}