#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
bool notprime[40000];
int prime[30000],totalprime;

void init()
{
	int i,j;
	notprime[1] = 1;
	notprime[2] = 0;
	for (i = 2;i <= sqrt(sqrt(1e9));i++)
	{
		if (!notprime[i])
			for (j = i + i;j <= sqrt(1e9);j += i)
				notprime[j] = 1;
	}
	for (j = 1;j < sqrt(1e9);j++)
	{
		if (!notprime[j])
			prime[totalprime++] = j;
	}
	scanf("%d",&n);
}
bool pdprime(int x)
{
	int i;
	if (x == 2)
		return 1;
	for (i = 2;i <= sqrt(x * 1.0);i++)
		if (x % i == 0)
			return 0;
	return 1;
}
void doit()
{
	int i,a;
	while (n--)
	{
		scanf("%d",&a);
		int flag = 0;
		for (i = 0;i < totalprime && prime[i] <= sqrt(a + 1.0);i++)
		{
			if (a % prime[i] == 0 && pdprime(a / prime[i]) )
				flag++;
		}
		if (flag == 1)
			printf("Yes\n");
		else 
			printf("No\n");
	}
}
int main()
{
	init();
	doit();
}