#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int f[10001],i,j,t,a[10001],num1,num2,x;
	memset(f,0,sizeof(f));
	memset(a,0,sizeof(a));
	for (i = 1;i <= 10001 / 2;i++)
	{
		for (j = i * 2;j < 10001;j += i)
		{
			a[j] += i;
		}
	}
	for (i = 2;i < 10001;i++)
	{
		if (a[i] == i)
		{
			f[i] = f[i - 1] + 1;
		}
		else
		{
			f[i] = f[i - 1];
		}
	}
	cin >> t;
	while (t--)
	{
		scanf("%d %d",&num1,&num2);
		if (num1 > num2)
		{
			num1 ^= num2 ^= num1 ^= num2; 
		}
		printf("%d\n",f[num2] - f[num1 - 1]);
	}
}