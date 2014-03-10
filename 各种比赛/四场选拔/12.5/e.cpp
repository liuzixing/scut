#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
using namespace std;
const int N=2001;
int prime[2001];
void makeprime()
{
	int i,j;
	for (i = 3;i <= N;i+=2)
	{
		bool flag = true;
		for (j = int(sqrt(double (i)));j > 2;j--)
		{
			if (i % j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			prime[i] = 1;
		}
	}
}
int main()
{
	int i,t,n;
	memset(prime,0,sizeof(prime));
	makeprime();
	cin >> t;
	while (t)
	{
		t--;
		scanf("%d",&n);
		if (n < 6 || n % 2 == 1)
		{
			cout << "INPUTERROR!" << endl;
			continue;
		}
		for (i = 3;i <= n / 2;i++)
		{
			if (prime[i])
			{
				if (prime[n - i])
				{
					printf("%d=%d+%d\n",n,i,n-i);
				}
			}
		}
	}

}
