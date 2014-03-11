/*
ID: benbenq1
PROG: contact
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
	
struct node
{
	int x,w,l;
}ans[10013];
string s="",temp;
int g[13][4096];
int i,j,a,b,n,total;
bool cmp(node i,node j)
{
	if (i.l == j.l && i.w == j.w)
		return i.x < j.x;
	if (i.l == j.l)
		return i.w < j.w;
	return i.l>j.l;
}
void output(int x,int w)
{
	int i,k;
	k = 1 << (w - 1);
	for (i = 0;i < w;i++)
	{
		if (x & k)
			printf("1");
		else
			printf("0");
		k = k >> 1;
	}
}
int main()
{
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);
	scanf("%d %d %d\n",&a,&b,&n);

	while (cin >> temp)
	{
		s += temp;
	}

	for (i = 0;i < s.size();i++)
	{
		int t = 0;
		for (j = 0;(j < b) && (j + i < s.size());j++)
		{
			t = (t << 1) + s[i + j] - '0';
			if (j >= a - 1)
			{			
				g[j + 1][t]++;
			}
		}
	}
	
	for (i = 0;i < 4096;i++)
	{
		for (j = 1;j <= 12;j++)
			if (g[j][i])
			{
				ans[total].x = i;
				ans[total].w = j;
				ans[total].l = g[j][i];
				total++;
			}
	}
	sort(ans,ans + total,cmp);
	for (i = 0;i < total;i++)
	{
		if (ans[i].l)
			printf("%d\n",ans[i].l);
		else
			break;
		n--;
		
		output(ans[i].x,ans[i].w);
		int c = 1;
		while (ans[i].l == ans[i + 1].l)
		{
			if (c)
			printf(" ");
			output(ans[i + 1].x,ans[i + 1].w);
			i ++;
			c++;
			if (c == 5)
			{
				if (ans[i].l == ans[i + 1].l)
				{
					printf(" ");
					output(ans[i + 1].x,ans[i + 1].w);
					i ++;
				}
				printf("\n");
				c = 0;
			}
		}
		if (c)
			printf("\n");
		if (!n)
			break;
	}
}