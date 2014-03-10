#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int i,c;
	double ans;
	char a[1000];
	while (cin.getline(a,1000,'\n'))
	{
		ans = 0;
		c = 0;
		bool flag = 1;
		for (i = 0;i < strlen(a) && flag;i++)
		{
			switch (a[i])
			{
			case 'A':ans += 4;c++;break;
			case 'B':ans += 3;c++;break;
			case 'C':ans += 2;c++;break;
			case 'D':ans += 1;c++;break;
			case 'F':c++;break;
			case ' ':break;
			default:printf("Unknown letter grade in input\n");flag = 0;break;
			}
		}
		if (flag)
		{
			printf("%.2lf\n",ans / c);
		}
	}
}