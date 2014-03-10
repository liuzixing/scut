#include <iostream>
#include <stdio.h>

using namespace std;

bool judge(__int64 y)
{
	if ((y % 400 ==0) || (y % 100 != 0 && y % 4 ==0))
	{
		return true;
	}
	return false;
}
int main()
{
	int t,n;
	__int64 y,i;
	cin >> t;
	while (t--)
	{
		scanf("%I64d %d",&y,&n);

		for (i = y;n > 0;i++)
		{
			if (judge(i))
			{
				n--;
			}
		}
		printf("%I64d\n",i - 1);
	}
}
