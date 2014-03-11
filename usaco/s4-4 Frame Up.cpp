/*
ID: benbenq1
PROG: frameup
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;
FILE *fin = fopen("frameup.in","r");
FILE *fout = fopen("frameup.out","w");

typedef char str[32];
int w,h,n;
char g[32][32];
bool b[27];
int maxx[27],maxy[27],minx[27],miny[27];
int indegree[27];
bool a[27][27],v[27];
char ans[10000][27],tem[27];
int len;
stack<int>s;
void init()
{
	int i,j,k;
	fscanf(fin,"%d%d",&h,&w);
	for (i = 0;i < h;i++)
		fscanf(fin,"%s",&g[i]);
	for (i = 0;i < 26;i++)
	{
		maxx[i] = maxy[i] = -1; 
		minx[i] = miny[i] = 50;
	}
	for (i = 0 ;i < h;i++)
	{
		for (j = 0;j < w;j++)
		{
			if (g[i][j] == '.') continue;
			maxx[g[i][j] - 'A'] = (maxx[g[i][j] - 'A' ] > i)?maxx[g[i][j] - 'A' ] : i;
			maxy[g[i][j] - 'A'] = (maxy[g[i][j] - 'A' ] > j)?maxy[g[i][j] - 'A' ] : j;
			minx[g[i][j] - 'A'] = (minx[g[i][j] - 'A' ] < i)?minx[g[i][j] - 'A' ] : i;
			miny[g[i][j] - 'A'] = (miny[g[i][j] - 'A' ] < j)?miny[g[i][j] - 'A' ] : j;
		}
	}

	for (k = 0;k < 26;k++)
	{

		if (maxx[k] == -1) continue;
		len++;
		for (i = minx[k]; i <= maxx[k];i++)
		{
			if (g[i][miny[k]] - 'A' != k)
				a[g[i][miny[k]] - 'A'][k] = 1;
			if (g[i][maxy[k]] - 'A' != k)
				a[g[i][maxy[k]] - 'A'][k] = 1;
		}
		for (j = miny[k] + 1;j <= maxy[k] - 1;j++)
		{
			if (g[minx[k]][j] - 'A' != k)
				a[g[minx[k]][j] - 'A'][k] = 1;
			if (g[maxx[k]][j] - 'A' != k)
				a[g[maxx[k]][j] - 'A'][k] = 1;
		}
	}
	for (k = 0;k < 27;k++)
		for (i = 0;i < 27;i++)
			for (j = 0;j < 27;j++)
				if (a[i][k] && a[k][j])
					a[i][j] = 1;
	for (i = 0;i < 26;i++)
		for (j = 0;j < 26;j++)
			if (a[i][j])
				indegree[j]++;
}
void topoo(int k)
{
	int i,j;
	if (k == len)
	{
		n++;
		for (i = 0;i < len;i++)
			ans[n][i] = tem[len - 1 - i]; 
		return;
	}
	for (i = 0;i < 26;i++)
	{
		if (indegree[i] == 0 && maxx[i] != -1 && !v[i])
		{
			v[i] = 1;
			tem[k] = char('A' + i);
			for (j = 0;j < 26;j++)
				if (a[i][j] && !v[j])
					indegree[j]--;

			topoo(k + 1);
			for (j = 0;j < 26;j++)
				if (a[i][j] && !v[j])
					indegree[j]++;
			v[i] = 0;
			tem[k] = 0;
		}
	}
}
int cmp(const void *a,const void *b)
{
	return strcmp(*(str*)a,*(str*)b);
}
int main()
{
	int i;
	init();
	topoo(0);
	qsort(ans + 1,n ,sizeof(ans[0]),cmp);
	for (i = 1;i <= n;i++)
		fprintf(fout,"%s\n",ans[i]);
	fclose(fin);
	fclose(fout);
}
