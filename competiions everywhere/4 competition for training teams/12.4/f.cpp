#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	char c[30];
	int x;
}a[10000];

bool cmp(node t,node s)
{
	if (t.x == s.x)
	{
		if (strcmp(t.c,s.c) > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return t.x > s.x;
}
int main()
{
	int n,m,i,j,total;
	char ch[30];
	int x;
	cin >>n;
	total = 0;
	while (n)
	{
		n--;
		cin >> m;
		for (i = 0;i < m;i++)
		{
		     scanf("%s %d",&ch,&x);
			 bool flag =false;
		     for (j = total;j >= 0;j--)
		     {
				 if (!strcmp(ch,a[j].c))
				 {
					 a[j].x = a[j].x + x;
					 flag = true;
				 }
		     }
			 if (!flag)
			 {
				 strcpy(a[total].c,ch);
				 a[total].x = x;
				 total++;
			 }
		}
		sort(a,a + total,cmp);
	}	
	cout  << a[0].c << " " << a[0].x << endl;	
	cout  << a[1].c << " " << a[1].x << endl;
	cout  << a[2].c << " " << a[2].x << endl;
}