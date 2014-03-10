#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int ans[101],i,n;
	while (cin >> n)
	{
		memset(ans,0,sizeof(ans));
		while (n)
		{
			ans[0]++;
			ans[ans[0]] = n % 2;
			n /= 2;
		}
		for (i = ans[0];i > 0;i--)
		{
			printf("%d",ans[i]);
		}
		printf("\n");
	}
}