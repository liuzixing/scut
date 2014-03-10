#include <iostream>
using namespace std;
const int N = 1000001;
int dp[N],pre[N],a[N];

int main()
{
	int m,n,MAX,i,j;
	while (scanf("%d %d",&m,&n) != EOF)
	{

		for (i = 1;i <= n;i++)
		{
			dp[i] = 0;
			pre[i] = 0;
			scanf("%d",&a[i]);
		}
		dp[0] = 0;
		pre[0] = 0;
		for (int i = 1;i <= m;i++)
		{
			MAX = -100000000;
			for (j = i;j <= n;j++)
			{
				dp[j] = max(dp[j - 1] ,pre[j - 1])+ a[j];
				pre[j - 1] = MAX;
				MAX = max(dp[j],MAX);
			}
		}
		printf("%d\n",MAX);
	}
	
}