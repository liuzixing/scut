/*
ID: benbenq1
PROG: cowtour
LANG: C++
*/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin ("cowtour.in");
ofstream fout ("cowtour.out");
int n;
char g[160][160];
double x[160],y[160],d[160][160],maxd[160],ans = 100000000;
double dist(int i,int j)
{
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
int main()
{
	int i,j,k;
	fin >> n;
	for (i = 0;i < n;i++)
	{
		fin >> x[i] >> y[i];
	}
	fin.getline(g[159],150,'\n');
	for (i = 0;i < n;i++)
	{
		fin.getline(g[i],160,'\n');
	}

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			if (g[i][j] == '1')
			{
				d[i][j] = dist(i,j);
			}
		}
	}
	for (k = 0;k < n;k++)
	{
		for (i = 0;i < n;i++)
		{
			for (j = 0;j < n;j++)
			{
				if (g[i][k] == '1' && g[k][j] == '1')
				{
					if (d[i][j] > d[i][k] + d[k][j] || d[i][j] == 0)
					{
						d[i][j] = d[i][k] + d[k][j];
					}
					g[i][j] = '1';
				}
			}
		}
	}
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			if (i != j && d[i][j] > maxd[i])
			{
				maxd[i] = d[i][j];
			}
		}
	}

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			if (i != j && d[i][j] == 0 && ans > maxd[i] + maxd[j] + dist(i,j))
			{
				ans =  maxd[i] + maxd[j] + dist(i,j);
			}
		}
	}
	for (i = 0;i < n;i++)
	{
		if (ans < maxd[i])
		{
			ans = maxd[i];
		}
	}
	fout << setprecision(6) << setiosflags(ios::fixed) << ans << endl;
}
