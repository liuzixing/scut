#include <iostream>
using namespace std;

int main()
{
	int t,n,l,r,tem;
	int i;
	cin >>t;
	while (t)
	{
		t--;
        int a[401] = {0},ans = 0;
		cin >> n;
		while (n)
		{
			n--;
			cin >> l >> r;
			if (l > r)
			{
				tem = l;
				l = r;
				r = tem;
			}
			for (i = l; i <= r;i++)
			{
				a[i]++;
			}
			if (l % 2 == 0 )
			{
				a[l - 1]++;
			}
			if (r % 2 != 0 )
			{
				a[r + 1]++;
			}
		}
		for (i = 1; i < 401 ; i++)
		{
			if (ans < a[i]) 
			{
				ans = a[i];
			}
		}
		cout << ans * 10<< endl;
	}
}