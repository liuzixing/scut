/*
ID: benbenq1
LANG: C++
TASK: clocks
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;
const int skip[10] = {0, 18911232, 19136512, 2363904, 16810048, 2134536, 262657, 36936, 73, 4617};
const int clean = 57521883;
int change[10] = {0};
int clocks = 0;
bool flag  =0;
void init()
{
	int bit = 16777216,time,tem;
	while (scanf("%d",&time) != EOF)
	{
		switch(time)
		{
		case 12:tem = 0;break;
		case 9:tem = 3;break;
		case 6:tem = 2;break;
		case 3:tem = 1;break;
		}
		clocks = clocks | (tem * bit);
		bit /= 8;
	}
}
void output()
{
	int i;
	vector <int> a;
	for (i = 1;i <= 9;i++)
	{
		while (change[i]--)
		{
			a.push_back (i);
		}
	}
	for (vector<int>::iterator it = a.begin();it != a.end();it++)
	{
		printf("%d",*it);
		if (it + 1 != a.end())
		{
			printf(" ");
		}
	}
	
	printf("\n");
}
int getans(int tclock)
{
	int i,t;
	for (i = 1;i < 10;i++)
	{
		t = change[i];
		while (t--)
		{
			tclock += skip[i];
			tclock = tclock & clean;
		}
	}
	return tclock;
}
void make(int k)
{
	if (k == 10)
	{
		if (!getans(clocks))
		{
			flag = 1;
			output();
		}
		return;
	}
	int i;
	for (i = 0;i <= 3 && !flag;i++)
	{
		change[k] = i;
		make(k + 1);
	}
}
void solve()
{
	int i;
	make(1);
}
int main()
{

	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);
	init();
	solve();
	return 0;
}