#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int a,b;
int ansa[10010],ansb[10010],ans[10010],aa[10010],bb[10010];;

void ab()
{
	int i,j;
	for (i = 1 ;i < b;i++)
	{
		for (j = 0;j <= ansa[0] + 10;j++)
			aa[j] = 0;
		for (j = 1;j <= ansa[0];j++)
		{
			aa[j] += ansa[j] * a;
			aa[j + 1] += aa[j] / 10;
			aa[j] %= 10;
		}
		aa[0] = ansa[0];
		while (aa[aa[0] + 1] > 0)
		{
			aa[0]++;
			aa[aa[0] + 1] += aa[aa[0]] / 10;
			aa[aa[0]] %= 10;
		}
		for (j = 0;j <= aa[0];j++)
			ansa[j] = aa[j];
	}
}
void ba()
{
	int i,j;
	for (i = 1 ;i < a;i++)
	{
		for (j = 0;j <= ansb[0] + 10;j++)
			bb[j] = 0;
		for (j = 1;j <= ansb[0];j++)
		{
			bb[j] += ansb[j] * b;
			bb[j + 1] += bb[j] / 10;
			bb[j] %= 10;
		}
		bb[0] = ansb[0];
		while (bb[bb[0] + 1] > 0)
		{
			bb[0]++;
			bb[bb[0] + 1] += bb[bb[0]] / 10;
			bb[bb[0]] %= 10;
		}
		for (j = 0;j <= bb[0];j++)
			ansb[j] = bb[j];
	}
}
bool cmp()
{
	int i;
	if (ansa[0] > ansb[0])
		return 1;
	if (ansa[0] < ansb[0])
		return 0;
	for (i = ansa[0];i > 0;i--)
	{
		if (ansa[i] > ansb[i])
			return 1;
		if (ansa[i] < ansb[i])
			return 0;
	}
	return 1;
}
void jian(int a[],int b[])
{
	int i,rem = 0;
	for (i = 1;i <= a[0];i++)
	{
		a[i] -= b[i];
		if (a[i] < 0)
		{
			a[i + 1]--;
			a[i] += 10;
		}
	}
	while (a[a[0]] == 0 && a[0] > 1)
		a[0]--;
	for (i = 0;i <= a[0];i++)
		ans[i] = a[i];;
}
void out()
{
	int i;
	for (i = ans[0];i > 0;i--)
		printf("%d",ans[i]);
	printf("\n");
}
int main()
{
	scanf("%d %d",&a,&b);
	ansa[0] = ansb[0] = 1;
	ansa[1] = a;
	ansb[1] = b;
	//a^b
	ab();
	//b^a;
	ba();
	if (cmp())
	{
		jian(ansa,ansb);
		out();
	}
	else
	{
		jian(ansb,ansa);
		printf("-");
		out();
	}
}