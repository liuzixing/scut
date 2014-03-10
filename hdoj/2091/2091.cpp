#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int i,j,n;
	char c;
	scanf("%c %d",&c,&n);
	while (c !='@')
	{
		for (i = 1;i <= n;i++)
		{
			for(j = 1;j < n - i + 1;j++)
		    {
			    putchar(' ');
		    }
			for (j = 1;j <= 2 * i - 1;j++)
			{
				if (i != n && j != 1 && j != 2 * i - 1)
				{
					putchar(' ');
				}
				else
				{
					putchar(c);
				}
			}
			printf("\n");
		}
		cin >> c;
		if (c != '@')
		{
			cin >> n;
			printf("\n");
		}
	}
}