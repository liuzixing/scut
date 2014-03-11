#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>
using namespace std;

int main()
{
	int color[16][4],a,b,c,i,minnum;
	double d,min;
    ifstream fin("test.in");
	for(i = 0;i < 16;i++)
	{
		cin >> color[i][1] >> color[i][2] >> color[i][3];
		color[i][0] = 0;
	}
	cin >> a >> b >> c;
	while (a+b+c != -3)
	{
		min = 10000000;
		for (i = 0;i < 16; i++)
		{		
			d = sqrt(double((color[i][1]-a)*(color[i][1]-a)+(color[i][2]-b)*(color[i][2]-b)+(color[i][3]-c)*(color[i][3]-c)));
			if (d < min)
			{
				min = d;
				minnum = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",a,b,c,color[minnum][1],color[minnum][2],color[minnum][3]);
		cin >> a >> b >> c;
	}
}