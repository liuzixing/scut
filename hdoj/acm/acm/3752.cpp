#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t,m,n;
	cin >> t;
	while (t--)
	{
		scanf("%d %d",&m,&n);
		if (m % 2 == 0 && m >= n * 2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}