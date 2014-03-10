#include<iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int i,j,n;
	double f[201][201] = {0},g2 = sqrt(2.0);

	for (i = 1;i <= 200;i++)
	{
		f[0][i] = f[i - 1][0] + sqrt(double((i - 1) * (i - 1) + i * i));
		for (j = 1;j <= i;j++)
		{
			f[j][i - j] = f[j - 1][i - j + 1] + g2;
		}
	}
	cin >> n;
	while (n--)
	{
		int x1,x2,y1,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("%.3lf\n",fabs(f[x1][y1] - f[x2][y2]));
	}
}