#include <iostream>
#include <stdio.h>

using namespace std;
int f[500001] = {0},i,k;
bool check[5000001] = {0};
int main()
{
	f[0] = 0;
	check[0] = 1;
	for (i = 1;i < 500001;i++)
	{
		if (f[i - 1] - i > 0 && (!check[f[i - 1] - i]))
		{
			f[i] = f[i - 1] - i;
		}
		else
		{
			f[i] = f[i - 1] + i;	
		}
		check[f[i]] = 1;
	}

	while (scanf("%d",&k) != EOF)
	{
		if (k == -1)
		{
			break;
		}
		printf("%d\n",f[k]);
	}

}