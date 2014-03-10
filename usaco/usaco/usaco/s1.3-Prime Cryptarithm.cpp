/*
ID: benbenq1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <numeric>
using namespace std;
FILE* fin = fopen("crypt1.in","r");
FILE* fout = fopen("crypt1.out","w");
bool check(int a[],int x)
{
	while (x)
	{
		if (!a[x % 10])
		{
			return 0;
		}
		x /= 10;
	}
	return 1;
}
int main()
{
	int n,s,t,i,j,k,l,m,a[10] = {0},num[10],ans = 0;
	fscanf(fin,"%d",&n);
	for (i = 0;i < n;i++)
	{
		fscanf(fin,"%d",&num[i]);
		a[num[i]] = 1; 
	}
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			for (k = 0;k < n;k++)
			{
				for (l = 0;l < n;l++)
				{
					for (m = 0;m < n;m++)
					{
						s = num[i] * 100 + num[j] * 10 + num[k];
						t = num[l] * 10 + num[m];
						if (s * num[l] < 1000 && s * num[m] < 1000 && s * t < 10000 && check(a,s * num[l]) && check(a,s * num[m]) && check(a,s * t))
						{
							ans++;
						}
					}
				}
			}
		}
	}
	fprintf(fout,"%d\n",ans);
	fclose(fin);
	fclose(fout);
}