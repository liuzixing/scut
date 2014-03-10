

#ifndef _GETPOINT
#define _GETPOINT

//返回分数
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include "node.h"

const int n = 50;
int num[n][n];                               //记录第i,j位置的整数个数

const int dx[24] = {-1,-1,-1,0,0,1,1,1,-2,-2,-2,-2,-2,2,2,2,2,2,-1,-1,0,0,1,1};
                   //{-1, 0, 1, 1, 1, 0,-1,-1,-2,-2,-1, 0, 1, 2, 2, 2, 2, 2, 1, 0,-1,-2,-2,-2};
                   //{-1,-1,-1, 0, 1, 1, 1, 0,-1,-2,-2,-2,-2,-2,-1, 0, 1, 2, 2, 2, 2, 2, 1, 0};
const int dy[24] = {-1,0,1,-1,1,-1,0,1,-2,-1,0,1,2,-2,-1,0,1,2,-2,2,-2,2,-2,2};




int getpoint(node b[n][n]){
	int ans = 0;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++){
			int &p = num[i][j];
			node &tem1 = b[i][j];
			for (int k1 = 0;k1 < p - 1;k1++)
				for (int k2 = k1 + 1;k2 < p;k2++){
					if (tem1.a[k1] == tem1.a[k2])
						ans += 100;
					if (abs(tem1.a[k1] - tem1.a[k2]) == 1)
						ans += 50;
				}
				for (int l = 0;l < 8;l++){
					int tx = i + dx[l];
					int ty = j + dy[l];
					int &q =  num[tx][ty];
					node &tem2 = b[tx][ty];
					if ((tx >= 0 && tx < n && ty >= 0 && ty < n)==false)
						continue;
					for (int k1 = 0;k1 < p;k1++)
						for (int k2 = 0 ;k2 < q;k2++){
							if (tem1.a[k1] == tem2.a[k2])
								ans += 20;
							if (abs(tem1.a[k1] - tem2.a[k2]) == 1)
								ans += 10;
						}
				}
				for (int l = 8;l < 24;l++){
					int tx = i + dx[l];
					int ty = j + dy[l];
					int &q =  num[tx][ty];
					node &tem2 = b[tx][ty];
					if ((tx >= 0 && tx < n && ty >= 0 && ty < n)==false)
						continue;
					for (int k1 = 0;k1 < p;k1++)
						for (int k2 = 0;k2 < q;k2++)
							if (tem1.a[k1] == tem2.a[k2])
								ans ++;
				}
		}
		return -ans;
}


int getpoint(node b[n][n],int x1,int x2,int y1,int y2){
	int ans = 0;
	for (int i = x1;i <= x2;i++)
		for (int j = y1;j <= y2;j++){
			int &p = num[i][j];
			node &tem1 = b[i][j];
			for (int k1 = 0;k1 < p - 1;k1++)
				for (int k2 = k1 + 1;k2 < p;k2++){
					if (tem1.a[k1] == tem1.a[k2])
						ans += 100;
					else if (abs(tem1.a[k1] - tem1.a[k2]) == 1)
						ans += 50;
				}
				for (int l = 0;l < 8;l++){
					int tx = i + dx[l];
					int ty = j + dy[l];
					int &q =  num[tx][ty];
					node &tem2 = b[tx][ty];
					if ((tx >= 0 && tx <= 49 && ty >= 0 && ty <= 49)==false)
						continue;
					for (int k1 = 0;k1 < p;k1++)
						for (int k2 = 0 ;k2 < q;k2++){
							if (tem1.a[k1] == tem2.a[k2])
								ans += 20;
							if (abs(tem1.a[k1] - tem2.a[k2]) == 1)
								ans += 10;
						}
				}
				for (int l = 8;l < 24;l++){
					int tx = i + dx[l];
					int ty = j + dy[l];
					int &q =  num[tx][ty];
					node &tem2 = b[tx][ty];
					if ((tx >= 0 && tx <= 49 && ty >= 0 && ty <=49)==false)
						continue;
					for (int k1 = 0;k1 < p;k1++)
						for (int k2 = 0;k2 < q;k2++)
							if (tem1.a[k1] == tem2.a[k2])
								ans ++;
				}
		}
		return -ans;
}

int getpoint(node b[n][n],int x,int y,int n1)
{
	int ans = 0 ;
	node &tem1 = b[x][y];
	int p = num[x][y];
	for(int i = 0 ; i < p; i++)
	{
		if((tem1.a[i] == tem1.a[n1]) && (n1 != i))
			ans += 100;
		else if( abs(tem1.a[i] - tem1.a[n1]) == 1)
			ans += 50;
	}
	for(int i = 0 ; i < 8; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		int q = num[tx][ty];
		if((tx >=0 && tx < n && ty >=0 && ty< n ) == false)
			continue;
		else
		{
			node &tem2 = b[tx][ty];
			for(int j = 0 ; j < q; j++){
				if(tem2.a[j] == tem1.a[n1])
					ans += 40;
				else if(abs(tem2.a[j] - tem1.a[n1]) ==  1)
					ans += 20;
			}
		}
	}
	for(int i = 8 ; i < 24; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		int q = num[tx][ty];
		if((tx >=0 && tx < n && ty >=0 && ty< n ) == false)
			continue;
		else
		{
			node &tem2 =b[tx][ty];
			for(int j = 0 ; j < q; j++)
				if(tem2.a[j] == tem1.a[n1])
					ans += 2;
		}
	}
	return -ans;
}

#endif
