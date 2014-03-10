#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t,a,b;
	cin >> t;
	while (t--)
	{
		scanf("%d %d",&a,&b);
		if (a % b == 0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}