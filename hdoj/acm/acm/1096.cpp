#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int a,ans[1001] = {0},n = 0,b,i,t;
	cin >> t;
	while (t--)
	{
		cin >> b;
		while (b--)
		{
			scanf("%d",&a);
			ans[n] += a;
		}
		n++;
	}
	for (i = 0;i < n - 1;i++)
		printf("%d\n\n",ans[i]);
	printf("%d\n",ans[i]);
}