/*
ID: benbenq1
PROG: shuttle
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

int i,j,k,n,m,t;
int f[200];
int main()
{
	FILE *fin = fopen("shuttle.in","r");
	FILE *fout = fopen("shuttle.out","w");
	fscanf(fin,"%d",&n);
	m = n - 2;
	t = -1;
	k = 0;
	for (i = 2;i <= n + 1;i++)
	{
		for (j = 1;j <= i ;j++)
		{
			if (t < 0)
				m += 2;
			else 
				m -= 2;
			f[k] = m;
			k++;
			
		}
		if (t < 0)
			t = 1;
		else
			t = -1;
		m = m + t * 3;
	}
	m -= t * 2;
	for (i = n;i > 1;i--)
	{
		for (j = 1;j <= i ;j++)
		{
			if (t < 0)
				m += 2;
			else 
				m -= 2;
			f[k] = m;
			k++;

		}

		if (t < 0)
			t = 1;
		else
			t = -1;
		m = m + t;
	}
	f[k] = n + 1;
	for (i = 0;i <= k;i++)
		if (i % 20)
			fprintf(fout," %d",f[i]);
		else
		{
			if (i != 0)
			fprintf(fout,"\n");
			fprintf(fout,"%d",f[i]);
		}
	if (k % 20 != 0)
		fprintf(fout,"\n");
	fclose(fin);
	fclose(fout);
}