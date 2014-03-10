#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n,k,i;
	double ans,c[2],s[2];
	bool flag = 0;
	cin >> n;
	while (n--)
	{
		cin >> k;
		for (flag = s[1] = c[1] = i = 0;i < k ;i++)
		{
			scanf("%*s %lf %lf",&c[0],&s[0]);
			if (s[0] < 60 && s[0] >= 0)
			{
				flag = 1;
			}
			if (flag)
			{
				continue;
			}
			s[1] +=  s[0] * c[0];
			c[1] += c[0]; 
		}
		ans = s[1] / c[1];
		if (flag)
		{
			printf("Sorry!\n");
		}
		else
		{
			printf("%.2f\n",s[1] / c[1]);
		}
		if (n) 
		{
			putchar('\n');
		}
	}
}