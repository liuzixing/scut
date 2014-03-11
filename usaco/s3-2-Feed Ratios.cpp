/*
ID: benbenq1
PROG: ratios
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int f[4][4],tar[4];
//计算三阶行列式的值
int DD(int (*x)[4])
{
	int ans = x[1][1]*x[2][2]*x[3][3]+x[2][1]*x[3][2]*x[1][3]+x[3][1]*x[1][2]*x[2][3]
			-x[1][3]*x[2][2]*x[3][1]-x[2][3]*x[3][2]*x[1][1]-x[3][3]*x[1][2]*x[2][1];
	return ans;
}
 
void init()
{
	int i,j;
 
	for (i=1;i<=3;++i) 
		scanf("%d",&tar[i]);
 
	for (j = 1;j <= 3;++j)
		for (i = 1;i <= 3;++i) 
			scanf("%d",&f[i][j]);
}
 
void deal()
{
	int i,j,k;
	int x,y,z;
	int D,D1,D2,D3;
	int temp[4];
 
	//交换列向量，求得行列式值
	D=DD(f);
 
	for (i=1;i<=3;++i) temp[i]=f[i][1];
	for (i=1;i<=3;++i) f[i][1]=tar[i];
	D1=DD(f);
	for (i=1;i<=3;++i) f[i][1]=temp[i];
 
	for (i=1;i<=3;++i) temp[i]=f[i][2];
	for (i=1;i<=3;++i) f[i][2]=tar[i];
	D2=DD(f);
	for (i=1;i<=3;++i) f[i][2]=temp[i];
 
	for (i=1;i<=3;++i) temp[i]=f[i][3];
	for (i=1;i<=3;++i) f[i][3]=tar[i];
	D3=DD(f);
	for (i=1;i<=3;++i) f[i][3]=temp[i];
 
	//利用Cramer法则可直接求得解，为了得到整数解，需要枚举系数
	bool found=false;
	for (k = 1;k <= 100;++k) 
	if (k * D1 % D == 0 && k * D2 % D == 0 && k * D3 % D==0)
	{
		x = k * D1 / D;
		y = k * D2 / D;
		z = k * D3 /D;
		if (x < 0 || y < 0 || z < 0) continue;
		found = true;
		printf("%d %d %d %d\n",x,y,z,k);
		break;
	}
	if (!found) 
		cout<<"NONE"<<endl;
}
int main()
{
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	init();
	deal();
	return 0;
}
