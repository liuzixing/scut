/*
ID: benbenq1
PROG: comehome
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

ifstream fin ("comehome.in");
ofstream fout ("comehome.out");
int p,g[53][53];
int transform(char c)
{
	if ((c >= 'a') && (c <= 'z')) return (c - 'a' + 27);
	if ((c >= 'A') && (c <= 'Z')) return (c - 'A' + 1);
}
int main()
{
	int i,j,k,x,y,d,ans = 2147483647;
	char c;
	fin >> p;
	for (i = 1;i <= 52;i++)
		for (j = 1;j <= 52;j++)
		{
			g[i][j] = 100000000;
		}
	for (i = 1;i <= p;i++)
	{	
		fin >> c;
		x = transform(c);
		fin >> c;
		y = transform(c);
		fin >> d;
		if(d < g[x][y])
		{
			g[x][y] = d;
			g[y][x] = d;
		}
	}
	for (k = 1;k <= 52;k++)
		for (i = 1;i <= 52;i++)
			for (j = 1;j <= 52;j++)
				if (g[i][k] + g[k][j] < g[i][j])
					g[i][j] = g[i][k] + g[k][j];
	for (i = 1;i <= 25;i++)
		if (g[i][26] < ans)
		{
			ans = g[i][26];
			k = i;
		}
	fout << char (k + 'A' - 1) << " " << ans << endl;
}