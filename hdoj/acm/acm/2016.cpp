#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,i;
	char a[10001];
	cin  >> n;
	while (n)
	{
		n--;	
		scanf("%s",&a);
		int ans = 0;
		for (i = 0;i < strlen(a);i++)
		{
			if ( '0' <= a[i] && a[i] <= '9')
			{
				ans++;
			}
		}
	
		printf("%d\n",ans);
	}
}