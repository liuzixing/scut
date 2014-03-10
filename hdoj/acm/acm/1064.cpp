#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	double a,ans = 0;
	while (cin >> a)
	{
		ans += a;
	}
	printf("$%.2lf\n",ans/12);
}