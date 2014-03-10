#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int c1,c5,c10,c25,c50,n,ans,d[251] = {0};
	
		ans = 0;
		for (n = 0;n  < 251;n++)
		{
			for (c5 = 0;c5 * 5 <= n;c5++)
			{
				for (c10 = 0;c5 * 5 + c10 * 10 <= n;c10++)
				{
					for (c25 = 0;c5 * 5 + c10 * 10 + c25 * 25 <= n;c25++)
					{
						for (c50 = 0;c5 * 5 + c10 * 10 + c25 * 25 + c50 * 50 <= n;c50++)
						{
							c1 = n - (c50 * 50 + c25 * 25 + c10 * 10 + c5 * 5);
							if (c1 + c5 + c10 + c25 + c50 <= 100)
							{
								d[n]++;
							}
						}
					}
				}
			}
		}
	while (cin >> n)
	{
		printf("%d\n",d[n]);
	}
}