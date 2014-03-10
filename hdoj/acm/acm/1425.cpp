#include <iostream>
#include <stdio.h>

using namespace std;

int n,m,positive[500001],negative[500001];
int main()
{
	int i,t;
	while (scanf("%d %d",&n,&m) != EOF)
	{
		while (n--)
		{
			scanf("%d",&t);
			if (t < 0)
			{
				negative[-t] = 1;
			}
			else
			{
				positive[t] = 1;
			}

		}
		i = 500000;
		while (m)
		{
			for (;i >= 0  && m > 0;i--)
			{
				if (positive[i])
				{
					if (m==1)
					{
						printf("%d\n",i);
					}
					else
					{
						printf("%d ",i);
					}		
					m--;
				}
			}
		}
		i = 1;
		while (m)
		{
			for (;i <=500000  && m > 0;i++)
			{
				if (negative[i])
				{
					if (m==1)
					{
						printf("%d\n",-i);
					}
					else
					{
						printf("%d ",-i);
					}		
					m--;
				}
			}
		}
	}
}