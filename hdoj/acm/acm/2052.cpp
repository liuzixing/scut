#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int i,j,n,m;
	while (cin >> m >> n)
	{
		for (i = 1;i < n + 3;i++)
		{
			for (j = 1;j < m + 3;j++)
			{
				if ((i == 1 && j == m + 2) || (i == 1 && j == 1) || (i == n + 2 && j == 1) || (i == n + 2 && j == m + 2))
				{
					printf("+");
					continue;
				}
				else
				{
					if (i == 1 || i == n + 2)
					{
						printf("-");
						continue;
					}
					if (j == 1 || j == m + 2)
					{
						printf("|");
						continue;
					}
				}
				printf(" ");
				
			}
			printf("\n");
		}
		printf("\n");
	}
}