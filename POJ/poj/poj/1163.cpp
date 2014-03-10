#include <iostream>
using namespace std;

int main()
{
	int n,i,j,t,f[101][101] = {0};
	cin >> n;
	for (i = 1; i <= n;i++)
	{
		for (j = 1;j <= i;j++)
		{
			cin >> t;
			f[i][j] = (f[i][j] < f[i - 1][j] + t ) ? f[i - 1][j] + t : f[i][j];
			f[i][j] = (f[i][j] < f[i - 1][j - 1] + t ) ? f[i - 1][j - 1] + t : f[i][j];
		}
	}
	int max = 0;
	for (i = 1; i <= n;i++)
	{
		max = (f[n][i] > max) ? f[n][i] :max;
	}
	cout << max << endl;
}