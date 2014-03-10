#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	int i,j,t,n;
	cin  >> t;
	while (t--)
	{
		cin >> n;
		for (i = 1;i <= n;i++)
		{
			for (j = 1;j < n;j++)
			{
				printf("%d ",i * j);
			}
			printf("%d\n",i * j);
		}
	}
}