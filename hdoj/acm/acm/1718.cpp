#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
struct node
{
	int num,mark;
}a[1001];

bool cmp (node x,node y)
{
	return (x.mark < y.mark);
}
int main()
{
	int i,j,rank,jackson,mark;
	while (cin >> jackson)
	{
		i = 0;
		while (scanf("%d %d",&a[i].num,&a[i].mark))
		{
			if (a[i].num == 0 && a[i].mark == 0)
			{
				break;
			}
			if (a[i].num == jackson)
			{
				mark = a[i].mark;
			}
			i++;
		}
		rank = 1;
		for  (j = 0;j < i;j++)
		{
			if (a[j].mark > mark)
			{
				rank ++;
			}
		}
		printf("%d\n",rank);
	}

}