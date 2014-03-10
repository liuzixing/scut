/*
ID: benbenq1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
FILE* fin = fopen("palsquare.in","r");
FILE* fout = fopen("palsquare.out","w");
const char p[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
int base;
bool check(int a[])
{
	int i;
	for (i = 1 ;i <= a[0] / 2;i++)
	{
		if (a[i] != a[a[0] - i + 1])
		{
			return 0;
		}
	}
	return 1;
}
void multiply(const int a[],const int b[],int c[])
{
	int i,j;
	for (i = 1;i <= a[0];i++)
	{
		for (j = 1;j <= b[0];j++)
		{
			c[i + j - 1] += a[i] * b[j];
			c[i + j] += c[i + j - 1] / base;
			c[i + j - 1] %= base;
		}
	}
	c[0] = a[0] + b[0] - 1;
	while (c[c[0] + 1] > 0)
	{
		c[0]++;
	}
}
void output(int a[],int b[])
{
	int i;
	for (i = a[0];i > 0;i--)
	{
		fprintf(fout,"%c",p[a[i]]);
	}
	fprintf(fout," ");
	for (i = b[0];i > 0;i--)
	{
		fprintf(fout,"%c",p[b[i]]);
	}
	fprintf(fout,"\n");
}
int main()
{
	int a[20] = {0},b[20] = {0},ans[20] = {0},i,j;
	a[0] = 1;a[1] = 0;
	b[0] = 1;b[1] = 0;
	fscanf(fin,"%d",&base);
	for (i = 1;i < 301;i++)
	{
		a[1]++;
		b[1]++;
		for (j = 1;j <= a[0];j++)
		{
			a[j + 1] += a[j] / base;
			a[j] = a[j] % base;
		}
		if (a[a[0] + 1] > 0)
		{
			a[0]++;
		}
		for (j = 1;j <= b[0];j++)
		{
			b[j + 1] += b[j] / base;
			b[j] = b[j] % base;
		}
		if (b[b[0] + 1] > 0)
		{
			b[0]++;
		}
		memset(ans,0,sizeof(ans));
		multiply(a,b,ans);
		if (check(ans))
		{
			output(a,ans);
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}