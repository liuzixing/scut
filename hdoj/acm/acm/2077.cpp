#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int main()
{
	int t,n;
	cin >> t;
	while (t--)
	{
		scanf("%d",&n);
		printf("%.lf\n",pow(3.0,n - 1) + 1);
	}
}