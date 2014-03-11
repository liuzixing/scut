#include <iostream>
#include <cstdio>

using namespace std;

int x,ans;
int k,n;
int main()
{
	scanf("%d",&k);
	while (k--)
	{
		ans = 0;
		int tem = 1;
		scanf("%d",&n);
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&x);
			tem = (tem * (x % 9)) % 9;
			ans = (ans + tem) % 9;
		}
		if (!ans) ans = 9;
		printf("%d\n",ans);
	}
}