#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int m1,m2,h1,h2,t,ans;
	char c1,c2;
	cin >> t;
	while (t--)
	{
		ans = 0;
		scanf("%d:%d%cm %d:%d%cm",&h1,&m1,&c1,&h2,&m2,&c2);
		ans += (abs(h2 - h1) > 12 - abs(h2 - h1)) ? 12 - abs(h2 - h1) :abs(h2 - h1);
		ans += (abs(m1 /10 - m2/ 10) > 5 - abs(m1 /10 - m2 / 10)) ? 6 - abs(m1 /10 - m2 / 10) : abs(m1 /10 - m2 / 10);
		ans += (c1 == c2) ? 0 : 1;
		ans += (abs(m1 %10 - m2% 10) > 9 - abs(m1 %10 - m2 % 10)) ? 10 - abs(m1 %10 - m2 % 10) : abs(m1 %10 - m2 % 10);
		if (ans == 1)
		{
			printf("Going from %d:%d%cm to %d:%d%cm requires %d push.\n",h1,m1,c1,h2,m2,c2,ans);
		}
		else
		{
			printf("Going from %d:%d%cm to %d:%d%cm requires %d pushes.\n",h1,m1,c1,h2,m2,c2,ans);
		}
	}
}