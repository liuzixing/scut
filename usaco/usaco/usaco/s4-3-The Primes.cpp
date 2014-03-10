/*
ID: benbenq1
PROG: prime3
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

typedef char str[32];
bool prime[100001];
int e,g[6][6],k,s = 0;
str ans[10000];

bool Deal (int a,int b,int c,int d)
{
	e = k - a - b - c - d;
	if (e < 0) return 0;
	if (prime[a * 10000 + b * 1000 + e * 100 + c * 10 + d]) return 0;
	return 1;
}

int cmp(const void *a, const void *b)
{
	return strcmp(*(str*)a,*(str*)b);
}
void print()
{
	int i,j;
	s++;
	for (i = 1;i <= 5;i++)
		for (j = 1;j <= 5;j++)
			ans[s][strlen(ans[s])] = (char)(g[i][j] + '0');
}
void Search()
{
	int i1,i2,i3,i4,i5,i6,i7,i8;
	for (i1 = 1;i1 < 10;i1++)
	for (i2 = 1;i2 < 10;i2++)
	{
		if (!Deal(g[1][1],i1,i2,g[1][5])) continue;
		g[1][3] = e;
		if (e <= 0 || e > 9) continue;
		for (i3 = 1;i3 < 10;i3 += 2)
		for (i4 = 1;i4 < 10;i4 += 2)
		{
			if (!Deal(g[1][5],i3,i4,g[5][5])) continue;
			g[3][5] = e;
			if (e <= 0 || e > 9) continue;
			for (i5 = 1;i5 < 10;i5 += 2)
			for (i6 = 1;i6 < 10;i6 += 2)
			{
				if (!Deal(g[5][1],i6,i5,g[5][5])) continue;
				g[5][3] = e;
				if (e < 0 || e > 9) continue;
				if (!Deal(i1,g[2][2],g[4][2],i6)) continue;
				g[3][2] = e;
				if (e < 0 || e > 9) continue;
				if (!Deal(i2,g[2][4],g[4][4],i5)) continue;
				g[3][4] = e;
				if (e < 0 || e > 9) continue;
				for (i7 = 1;i7 < 10;i7++)
				for (i8 = 1;i8 < 10;i8++)
				{
					if (!Deal(g[1][1],i8,i7,g[5][1])) continue;
					g[3][1] = e;
					if (e <= 0 || e > 9) continue;
					if (!Deal(i8,g[2][2],g[2][4],i3)) continue;
					g[2][3] = e;
					if (e < 0 || e > 9) continue;
					if (!Deal(i7,g[4][2],g[4][4],i4)) continue;
					g[4][3] = e;
					if (e < 0 || e > 9) continue;
					if (!Deal(g[3][1],g[3][2],g[3][4],g[3][5])) continue;
					if (e != g[3][3]) continue;
					if (!Deal(g[1][3],g[2][3],g[4][3],g[5][3])) continue;
					if (e != g[3][3]) continue;
					g[1][2] = i1;
					g[1][4] = i2;
					g[2][5] = i3;
					g[4][5] = i4;
					g[5][2] = i6;
					g[5][4] = i5;
					g[2][1] = i8;
					g[4][1] = i7;
					print();
				}
			}
		}
	}
}
FILE *fin = fopen("prime3.in","r");
FILE *fout = fopen("prime3.out","w");
int main()
{
	int i,j;
	prime[2] = 0;
	for (i = 2;i < sqrt(100000.0);i++)
	{
		if (!prime[i])
		{
			for (j = i + i ;j <= 100000;j += i)
				prime[j] = 1;
		}
	}

	int i1,i2,i3,i4,i5,i6,i7,x1,x2,s1,s2;
    fscanf(fin,"%d%d\n",&k,&i1);
	//先枚举2对角线
    g[1][1] = i1;
    for (i2 = 0;i2 < 10;++i2)
    for (i3 = 0;i3 < 10;++i3)
    for (i4 = 0;i4 < 10;++i4)
    {
        x1 = k - i1 - i2 - i3 - i4;
        if (x1 <= 0 || x1 > 9) continue;
        s1 = i1 * 10000 + i2 * 1000 + i3 * 100 + i4 * 10 + x1;
        if (prime[s1]) continue;
        for (i5 = 1;i5 < 10;i5 += 2)
        for (i6 = 0;i6 < 10;++i6)
        for (i7 = 0;i7 < 10;++i7)
        {
            x2 = k - i5 - i6 - i3 - i7;
            if (x2 <= 0 || x2 > 9) continue;
            s2 = x2 * 10000 + i7 * 1000 + i3 * 100 + i6 * 10 + i5;
            if (!prime[s2])
			{
                g[2][2] = i2;
                g[3][3] = i3;
                g[4][4] = i4;
                g[5][5] = x1;
                g[1][5] = i5;
                g[2][4] = i6;
                g[4][2] = i7;
                g[5][1] = x2;
                Search();
            }
        }
    }
    qsort(ans + 1,s,sizeof(ans[0]),cmp);
    for (i = 1;i <= s;++i)
	{
		if (i != 1) 
			fprintf(fout,"\n");
        for (j = 0;j < 25;++j)
		{
            if (j && j % 5 == 0 ) fprintf(fout,"\n");
            fprintf(fout,"%c",ans[i][j]);
        }
		fprintf(fout,"\n");
     }
	if (!s)
		fprintf(fout,"NONE\n");
    fclose(fin);
    fclose(fout);
    return 0;
}