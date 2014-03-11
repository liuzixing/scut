/*
ID: benbenq1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct node
{
	int s,t;
} a[5001];
int cmp(const node &x,const node &y)
{
	if (x.s == y.s)
	{
		return x.t < y.t;  
	}
	else
	{
		return x.s < y.s;
	}
}
int main()
{
    FILE* fout = fopen ("milk2.out","w");
    FILE* fin = fopen ("milk2.in","r");
    int n,i,ans1,ans2,begin,end;
    fscanf(fin,"%d",&n);

	for (i = 0;i < n;i++)
	{
		fscanf(fin,"%d %d",&a[i].s,&a[i].t);
	}
	sort(a,a + n,cmp);
	begin = a[0].s;
	end = a[0].t;
	ans1 = end - begin;
	ans2 = 0;
	for (i = 1;i < n;i++)
	{
		if (end >= a[i].s)
		{
			end = (end > a[i].t)? end : a[i].t;
		}
		else
		{
			ans1 = (ans1 < end - begin) ? end - begin : ans1;
			ans2 = (ans2 < a[i].s - end) ? a[i].s - end: ans2;
			begin = a[i].s;
			end = a[i].t;
		}
	}
	fprintf(fout,"%d %d\n",ans1,ans2);
    return 0;
}

