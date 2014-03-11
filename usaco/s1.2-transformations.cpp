/*
ID: benbenq1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
FILE*  fin = fopen("transform.in","r");
FILE* fout = fopen ("transform.out","w");
char s[11][11],t[11][11],tem[11][11];
int i,j,n;
bool cmp(char x[11][11],char y[11][11])
{
	for (i = 0;i < n;i++)
	{
		if (strcmp (x[i],y[i]))
		{
			return 0;
		}
	}
	return 1;
}
void change1()
{
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			tem[j][n - i - 1] = s[i][j];
		}
	}
}
void change2()
{
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			tem[n - i - 1][n - j - 1] = s[i][j];
		}
	}
}
void change3()
{
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			tem[n - j - 1][i] = s[i][j];
		}
	}
}
void change4()
{
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			tem[i][n - 1 - j] = s[i][j];
		}
	}
}
void change51()
{
	char tt[11][11];
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			tt[i][n - 1 - j] = s[i][j];
		}
	}
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			tem[j][n - i - 1] = tt[i][j];
		}
	}
}
void change52()
{
	char tt[11][11];
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			tt[i][n - 1 - j] = s[i][j];
		}
	}
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			tem[n - i - 1][n - j - 1] = tt[i][j];
		}
	}
}
void change53()
{
	char tt[11][11];
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			tt[i][n - 1 - j] = s[i][j];
		}
	}
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			tem[n - j - 1][i] = tt[i][j];
		}
	}
}
int work()
{
	fscanf(fin,"%d",&n);
	for (i = 0;i < n;i++)
	{
		fscanf(fin,"%s",&s[i]);
	}
	for (i = 0;i < n;i++)
	{
		fscanf(fin,"%s",&t[i]);
	}
	change1();
	if (cmp(tem,t))
	{
		return 1;
	}
	change2();
	if (cmp(tem,t))
	{
		return 2;
	}
	change3();
	if (cmp(tem,t))
	{
		return 3;
	}
	change4();
	if (cmp(tem,t))
	{
		return 4;
	}
	change51();
	if (cmp(tem,t))
	{
		return 5;
	}
	change52();
	if (cmp(tem,t))
	{
		return 5;
	}
	change53();
	if (cmp(tem,t))
	{
		return 5;
	}
	if (cmp(s,t))
	{
		return 6;
	}
	return 7;
}
int main()
{
	fprintf(fout,"%d\n",work());
	fclose(fin);
	fclose(fout);
	return 0;
}