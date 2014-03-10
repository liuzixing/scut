#include <iostream>
using namespace std;

int main()
{
	int t,i;
	cin >> t;
	while (t > 0)
	{
		int a[100] = {0};
		int ans = 0;
		a[t] = 1;
		cin >> t;
		while (t)
		{
			a[t] = 1;
			cin >> t;
		}
		for (i = 1;i < 100;i++)
		{
			if (a[i] == 1 && i * 2 < 100 && a[i * 2] == 1 )
			{
				ans++;
			}
		}
		cout <<  ans << endl;
		cin >> t;
	}
}
