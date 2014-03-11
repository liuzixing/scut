#include <iostream>
using namespace std;

int main()
{
	int n,t,i,a[101],j;
	
	cin >> t;
	while (t)
	{
		cin >>n;
		t--;
		memset(a,0,sizeof(a));
		for(i = 2;i <= n;i++ )
		{
			for (j = i;j <= n;j += i)
			{
				a[j] = (a[j] == 1) ? 0 : 1;
			}
		}
		int ans = 0;
		for (i = 1;i <= n;i++ )
		{
			if (a[i] == 0)
			{
				ans++;
			}
		}
		cout << ans << endl;
	}
}