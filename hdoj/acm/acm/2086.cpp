#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n,i;
	double ans,c[3001],a0,ax;
	while (cin >> n)
	{
		scanf("%lf",&a0);
		scanf("%lf",&ax);
		ans = n * a0 + ax;
		for (i = 1;i <= n;i++)
		{
			scanf("%lf",&c[i]);
			ans -=2.0 * (n - i + 1.0) * c[i];
		}
		ans /= double(n + 1.0);
		printf("%.2lf\n",ans);
	}
}