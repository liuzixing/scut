#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,sum,i;

int judge(int x)
{
	switch(x)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:return 31;
	case 4:
	case 6:
	case 9:
	case 11:return 30;
	case 2:return 28;
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	if (m < 1 || m > 12 || n < 1 || n > judge(m))
		printf("Impossible\n");
	else
	{
		sum = n;
		for (i = 1;i < m;i++)
			sum += judge(i);
		sum %= 7;
		if (!sum) sum = 7;
		printf("%d\n",sum);
	}
}

