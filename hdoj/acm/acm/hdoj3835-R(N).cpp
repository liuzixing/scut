#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
int n,ans;
int main()
{
	int a,b;
	while (scanf("%d",&n) != EOF)
	{
		for (a = ans = 0;a * a < n;a++)
		{
			double tt = sqrt(double(n - a * a));
			if (fabs(int (tt) - tt) < 0.000000001)
				ans += 4;
		}
		printf("%d\n",ans);
	}
}