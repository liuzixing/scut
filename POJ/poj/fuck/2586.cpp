#include <iostream>
using namespace std;

int main()
{
	int s, d, ans;
	while (cin >> s >> d)
	{
		ans = -1;
		if (d > s * 4)
		{
			ans = 10 * s - 2  * d;
		}
		else
			if (d * 2 > s * 3)
			{
				ans = 8 * s - d * 4;
			}
			else
				if (d * 3 > s * 2)
				{
					ans = 6 * s - 6 * d;
				}
				else
					if (d * 4 > s)
					{
						ans = 3 * s - 9 * d;
					}
		if (ans <= 0) 
		{
			cout << "Deficit" << endl;
		}
		else
		{
			cout << ans << endl;
		}
	}
}