#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	int n,m,judge;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		judge = n * n - 4 * m;
		if (judge > 0 && judge - ((int)sqrt(double(judge))) * (int)sqrt(double(judge)) == 0)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
}