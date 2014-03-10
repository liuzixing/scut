#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t,n,x,min;
	cin >> t;
	while (t--)
	{
		scanf("%d%*d",&n);
		min = 100000000;
		while (n--)
		{
			scanf("%d",&x);
			if (x < min)
			{
				x ^= min ^= x ^= min;
			}
		}
		printf("%d\n",(100 - min) * (100 - min));
	}

}