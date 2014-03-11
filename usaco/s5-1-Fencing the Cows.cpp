/*
ID: benbenq1
PROG: fc
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
FILE *fin = fopen("fc.in","r");
FILE *fout = fopen("fc.out","w");

struct node
{
	double x,y;
}p0,p[10000],a[10000],b[10000];
int n,pn,pb;
double ans = 0;
double cross (node o,node a,node b)
{
	return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o .y);
}
int cmp(const void *x ,const void * y)
{
	node a = * (node *)x,b = *(node *)y;
	return cross(p0,a,b) < 0;
}
double dist(node a,node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
	int i,j = -1;;
	fscanf(fin,"%d",&n);
	p0.x = p0.y = 100000000;
	for (i = 0;i < n;i++)
	{
		fscanf(fin,"%lf %lf",&p[i].x,&p[i].y);
		if (p[i].x < p0.x)
		{
			p0 = p[i];
			pn = i;
		}
		else if (p[i].x == p0.x && p[i].y < p0.y)
		{
			p0 = p[i];
			pn = i;
		}
	}
	
	for (i = 0;i < n;i++)
		if (i != pn)
		{
			j++;
			a[j] = p[i];
		}
	qsort(a,n - 1,sizeof(a[0]),cmp);
	//Gramham Scan
	b[0] = p0;b[1] = a[0];pb = 2;
	for (i = 1;i < n - 1;i++)
	{
		b[pb] = a[i];
		while (cross(b[pb - 2],b[pb - 1],b[pb]) <= 0)
		{
			pb--;
			b[pb] = a[i];
		}
		pb++;
	}
	//calculate;
	for (i = 1;i < pb;i++)
		ans += dist(b[i - 1],b[i]);
	ans += (dist(b[0],b[pb - 1]));
	fprintf(fout,"%.2lf\n",ans);
	return 0;
}
