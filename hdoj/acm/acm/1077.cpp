#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int ans,a;
	while (cin >> a && a)
	{
		ans  = 1;
		while (!(a & ans))
		{
			ans = ans << 1;
		}
		printf("%d\n",ans);
	}
}