#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int x,y,t;
	cin >> t;
	while (t--)
	{
		cin >> x>> y;
		int max = 0,ans = 0;
		for (int i = x;i <= y;i++)
		{
			int tem = 0;
			for (int j = 1;j <= i;j++)
				if (i % j == 0)
					tem++;
			if (tem > max)
			{
				max = tem;
				ans = i;
			}
		}
		cout << ans << endl;
	}
}