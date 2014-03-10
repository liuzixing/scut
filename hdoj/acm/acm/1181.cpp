#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
	char s[110];
	int i,j,k;
	bool g[27][27];
	while (scanf("%s",&s) != EOF)
	{
		memset(g,0,sizeof(g));
		g[s[0] - 'a'][s[strlen(s) - 1] - 'a'] = 1;
		while (scanf("%s",&s) && strcmp(s,"0"))
		{
			g[s[0] - 'a'][s[strlen(s) - 1] - 'a'] = 1;
		}
		for (k = 0;k < 26;k++)
		{
			for (i = 0;i < 26;i++)
			{
				for (j = 0;j < 26;j++)
				{
					if (g[i][k] && g[k][j])
					{
						g[i][j] = 1;
					}
				}
			}
		}
		if (g[1]['m' - 'a'])
		{
			printf("Yes.\n");
		}
		else
		{
			printf("No.\n");
		}
	}
}