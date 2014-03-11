/*
ID: benbenq1
PROG: starry
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
#include <memory>
#include <cstdio>
#include <cctype>
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

FILE *fin = fopen("starry.in","r");
FILE *fout = fopen("starry.out","w");

//x,y颠倒
const int dy[8] = {-1,-1,-1,0,0,1,1,1};
const int dx[8] = {-1,0,1,-1,1,-1,0,1};
int x1,x2,y11,y2,w,h,n,flag,flag2;
char a[105][105];
struct node
{
	int w,h;
	char map[105][105];
}v[26],b;
void floodfill(int y, int x,int c)
{
	int i;
	a[y][x] = char (c);
	x1 = min(x1,x);x2 = max(x2,x);
	y11 = max(y11,y);y2 = min(y2,y);
	for (i = 0;i < 8;i++)
	{
		int ty = y + dy[i],tx = x + dx[i];
		if(ty >= 0 && ty < h && tx >= 0 && tx < w && a[ty][tx] != c && a[ty][tx] != '0')
			floodfill(ty,tx,c);
	}
}
int main()
{
	int i,j,ii,jj,k,l;
	fscanf(fin,"%d%d",&w,&h);
	for (i =0;i < h;i++)
		fscanf(fin,"%s",a[i]);
	for (i = 0;i < h;i++)
		for (j = 0;j < w;j++)
			if (a[i][j] == '1')
			{
				x1 = w;x2 = 0;y11 = 0;y2 = h;
				floodfill(i,j,'2');
				memset(b.map,'0',sizeof(b.map));
				for (ii = y2;ii <= y11;ii++)
					for (jj = x1;jj <= x2;jj++)
						if (a[ii][jj] == '2')
							b.map[ii - y2][jj - x1] = a[ii][jj];
				b.w = x2 - x1 + 1;
				b.h = y11 - y2 + 1;
				flag2 = 0;
				for (k = 0;k < n;k++)
				{
					for (l = 0;l < 4;l++)
					{
						//顺时针转90度
						node tem = b;
						b.w = tem.h;b.h = tem.w;
						for (ii = 0;ii < tem.h;ii++)
							for (jj = 0;jj < tem.w;jj++)
								b.map[jj][b.w - ii - 1] = tem.map[ii][jj];
						//对比
						flag = 1;
						if (b.w != v[k].w || b.h != v[k].h) flag = 0;
						if (flag)
							for (ii = 0;ii < b.h;ii++)
								for (jj = 0;jj < b.w;jj++)
									if (b.map[ii][jj] != v[k].map[ii][jj])
									{
										flag = 0;
										break;
									}
						if (flag)
						{
							floodfill(i,j,(char)('a' + k));
							flag2 = 1;
							break;
						}	
						//对称
						flag=1;
						if(b.w != v[k].w || b.h != v[k].h) flag=0;
						if(flag)
							for(ii = 0;ii < b.h;ii++)
								for(jj = 0;jj < b.w;jj++)
									if(b.map[ii][jj] != v[k].map[b.h - ii - 1][jj])
									{
										flag = 0;
										break;
									}
						if(flag)
						{
							floodfill(i,j,(char)('a' + k));
							flag2 = 1;
							break;
						}	
					}
					if (flag2) break;
				}
				if (!flag2)
				{
					floodfill(i,j,(char)(n + 'a'));
					v[n] = b;
					n++;
				}
			}
		for(i = 0;i < h;i++)
			fprintf(fout,"%s\n",a[i]);
		fclose(fin);
		fclose(fout);
		return 0;
}
