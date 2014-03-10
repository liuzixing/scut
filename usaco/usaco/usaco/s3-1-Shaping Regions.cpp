/*
ID: benbenq1
PROG: rect1
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int limc;
int x1[1001],x2[1001],y11[1001],y2[1001],color[2501],area[2501];
void cover(int dx,int ux,int dy,int uy,int floor,int c)
{
	while ((floor <= limc) && ((dx >= x2[floor]) || (ux <= x1[floor]) || (dy >= y2[floor]) || (uy <= y11[floor])))
	{
		floor++;
	}
	if (floor > limc)
	{
		area[c] += (ux - dx) * (uy - dy);
		return;
	}
	if (dx < x1[floor])
	{
		cover(dx,x1[floor],dy,uy,floor + 1,c);
		dx = x1[floor];
	}
	if (ux > x2[floor])
	{
		cover(x2[floor],ux,dy,uy,floor + 1,c);
		ux = x2[floor];
	}
	if (dy < y11[floor])
	{
		cover(dx,ux,dy,y11[floor],floor + 1,c);
		dy = y11[floor];
	}
	if (uy > y2[floor])
	{
		cover(dx,ux,y2[floor],uy,floor + 1,c);
		uy = y2[floor];
	}
}
int main()
{
	freopen("rect1.in","r",stdin);
	freopen("rect1.out","w",stdout);
	scanf("%d %d %d",&x2[0],&y2[0],&limc);
	x1[0] = y11[0] = 0;
	color[0] = 1;
	for (int i = 1;i <= limc;i++)
	{
		scanf("%d %d %d %d %d",&x1[i],&y11[i],&x2[i],&y2[i],&color[i]);
	}
	for (int i = limc;i >= 0;i--)
	{
		cover(x1[i],x2[i],y11[i],y2[i],i + 1,color[i]);
	}
	for (int i = 1;i <= 2500;i++)
	{
		if (area[i])
			printf("%d %d\n",i,area[i]);
	}
}