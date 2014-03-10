#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int a,b,n;
	while (scanf("%d %d",&b,&n))
	{
		if (b == 0 && n == 0)
		{
			break;
		}
		a = int (pow(double(b),1.0 / n));
		if (abs(pow(double(a),n) - b) > abs(pow(double(a + 1),n) - b))
		{
			a += 1;
		}
		printf("%d\n",a);
	}
}