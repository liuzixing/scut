#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;
 
int main()
{
	int a,b,ans,i;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
		{
			break;
		}
		ans = 1;
		for (i = 0;i < b;i++)
		{
			ans = ans * a % 1000;
		}
		printf("%d\n",ans);
	}
}