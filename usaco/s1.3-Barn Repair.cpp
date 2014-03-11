/*
ID: benbenq1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <numeric>
using namespace std;
FILE* fin = fopen("barn1.in","r");
FILE* fout = fopen("barn1.out","w");

bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	int m,s,c,cow[201],i,gap[201],ans;
	fscanf(fin,"%d %d %d",&m,&s,&c);
	for (i = 0;i < c;i++)
	{
		fscanf(fin,"%d",&cow[i]);
	}
	sort(cow,cow + c);
	ans = cow[c - 1] - cow[0] + 1;
	for (i = 0;i < c - 1;i++)
	{
		gap[i] = cow[i + 1] - cow[i] - 1;
	}

	sort(gap,gap + c - 1,cmp);

	for (i = 0;i < m - 1 && i < c - 1;i++)
	{
		ans -= gap[i];
	}
	fprintf(fout,"%d\n",ans);
	fclose(fin);
	fclose(fout);
	return 0;
}
