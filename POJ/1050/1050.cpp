#include <iostream>
using namespace std;
int main()
{
	short int g[128][128];
	int sum[128][128],i,j,k,n,a[128],max;
	memset(sum,0,sizeof(sum));
	cin >> n;
	max = -10000000;
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
		{
			cin >> g[i][j];
			sum[i][j] = sum[i][j - 1] + g[i][j];
		}
	}
	for (i = 0;i <= n -1;i++)
	{
		for (j = i + 1;j <= n;j++)
		{
			a[0] = 0;
			for (k = 1;k <= n;k++)
			{
				a[k] =  (sum[k][j] - sum[k][i] > sum[k][j] - sum[k][i] + a[k - 1]) ? sum[k][j] - sum[k][i]:sum[k][j] - sum[k][i] + a[k - 1];
				max = (max < a[k])? a[k]:max;
			}
		}
	}
	cout << max << endl;
}
