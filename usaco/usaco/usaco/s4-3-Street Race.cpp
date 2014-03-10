/*
ID: benbenq1
PROG: race3
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

int a[51],b[51],c = 0, d = 0;
int n = -1;
bool f[51][51],g[51][51];
bool v[51];
int i = 0,k,j;
void dfs(const int vtx)
{
	int i;
	v[vtx] = 1;
	for (i = 0;i <= n;i++)
		if (i != k && f[vtx][i] && !v[i])
			dfs(i);
}
int main()
{
	FILE* fin = fopen("race3.in","r");
	FILE* fout = fopen("race3.out","w");
	while (i != -1)
		for (++n;;)
		{
			fscanf(fin,"%d",&i);
			if (i < 0) break;
			f[n][i] = true;;
		}
	--n;
	memcpy(g,f,sizeof(g));
	for (k = 0;k <= n;k++)
		for (i = 0;i <= n;i++)
			for (j = 0;j <= n;j++)
				if (g[i][k] && g[k][j]) g[i][j] = true;
	for (k = 1;k < n;++k)
	{
		memset(v,0,sizeof(v));
		dfs(0);
		if (!v[n])
		{
			a[c++] = k;
			for (j = 1,i = 0;i < n;i++)
				if (v[i] && g[k][i])
				{
					j = 0;
					break;
				}
			if (j) b[d++] = k;
		}
	}
	fprintf(fout,"%d",c);
	for (i = 0;i < c;i++)
		fprintf(fout," %d",a[i]);
	fprintf(fout,"\n%d",d);
	for (i = 0;i < d;i++)
		fprintf(fout," %d",b[i]);
	fprintf(fout,"\n");
	fclose(fin);
	fclose(fout);
	return 0;
}
