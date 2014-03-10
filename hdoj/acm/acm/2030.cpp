#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;

int main()
{
	int n,ans;
	char c;
	scanf("%d%*c",&n);
	while (n--)
	{
		ans = 0;
		while ((c = getchar()) != '\n')
		{
			if (c < 0)
			{
				ans++;
			}
		}
		printf("%d\n",ans / 2);
	}

}