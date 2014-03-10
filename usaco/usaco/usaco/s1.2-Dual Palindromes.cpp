/*
ID: benbenq1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
FILE* fin = fopen("dualpal.in","r");
FILE* fout = fopen("dualpal.out","w");

bool check(int a,int base)
{
	int i,c[100];
	c[0] = 0;
	while (a)
	{
		c[0]++;
		c[c[0]] = a % base;
		a /= base;
	}
	for (i = 1;i <= c[0] / 2;i++ )
	{
		if (c[i] != c[c[0] - i + 1])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int i,count,base,n,s;
	fscanf(fin,"%d %d",&n,&s);
	for (i = s + 1;n;i++)
	{
		count = 0;
		for (base = 2;base < 11;base++)
		{
			if (check(i,base))
			{
				count++;
			}
			if (count == 2)
			{
				n--;
				fprintf(fout,"%d\n",i);
				break;
			}
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}