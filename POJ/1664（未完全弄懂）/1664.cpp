#include <iostream>
using namespace std;
int f[11][11];
int dp(int m,int n)
{
	if (m < 0)
	{
		return 0;
	}
	if (m == 0 || n == 1)
	{
		return 1;
	}
	if (f[m][n] > 0)
	{
		return f[m][n];
	}
	f[m][n] = dp(m - n,n) +  dp(m, n - 1);
	return f[m][n];
}
int main()
{
	int t,m,n;
	cin >> t;
	while (t)
	{
		t--;
		cin >> m >> n;
		cout << dp(m,n) << endl;
	}
}