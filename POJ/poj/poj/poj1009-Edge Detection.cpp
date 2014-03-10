#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int r,a[3][3],now;
int b[2000][2];
int main()
{
	int i,j,x,y,n;
	while (cin >> r && r)
	{
		memset(b,0,sizeof(b));
		n = 0;
		while (scanf("%d %d",&x,&y) != EOF && (x || y))
		{
			b[n][0] = b[n - 1][0] + y;
			b[++n][1] = x;
		}
		b[0][0] = 0;
		b[0][1] = x;
		b[n + 1][0] = b[n][0] + r;
		b[n + 1][1] = b[n][1];
		now = 1;
		for (i = 0;i < 3;i++)
			for(j = 0;j < 3;j++)
				a[i][j] = b[1][1];
		if (now + 1 <= b[1][0])
			a[1][2] = b[1][1];
		else
			a[1][2] = b[2][1];
		if (now + r <= b[1][0])
			a[2][1] = b[1][1];
		else
		{
			j = 2;
			while (now + r > b[j][0])
				j++;
			a[2][1] = b[j][1];
		}
		if 


	}
}