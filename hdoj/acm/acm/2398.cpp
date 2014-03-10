#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	double a,b,c;
	int ans;
	while(scanf("%lf %lf %lf",&a,&b,&c) !=EOF )
	{
		b = b / 100 + 1; 
		ans = 0;
		while (a < c)
		{
			a *= b;
			ans++;
		}
		printf("%d\n",ans);
	}
}