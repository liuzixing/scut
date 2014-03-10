#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int n,b,a1;
	double a;
	while (scanf("%d %d",&b,&n) != EOF && (n && b))
	{
		a = pow(b,1.0 / n);
		if (fabs(a - int (a)) <= 1e-10)
		{
			printf("%d\n",int(a));
			continue;
		}
		a1 = int (a);
		if (abs(pow((double)a1,n) - b) < abs(pow((double)a1 + 1,n) - b))
			printf("%d\n",a1);
		else
			printf("%d\n",a1 + 1);
	}
}