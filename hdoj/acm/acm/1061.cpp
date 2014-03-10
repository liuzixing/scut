#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int f[10],n,i,t,a;
	cin >> t;
	while (t--)
	{
		scanf("%d",&n);
		a = n;
		n = n % 10;
		f[1] = n;
		i = 2;
		while (1)
		{
			f[i] = f[i - 1] * n % 10;
			if (f[i] == n)
			{
				break;
			}
			i++;
		}
		f[0] = f[i - 1];
		i--;
		printf("%d\n",f[a % i]);
	}
	
}