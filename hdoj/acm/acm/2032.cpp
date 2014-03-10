#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;
 
int main()
{
	int n,i,j,f[31][31] = {0};
	f[0][0] = 1;
	for (i = 1;i <= 30;i++)
	{
		for (j = 1; j <= i;j++)
		{
			f[i][j]  = f[i - 1][j - 1] + f[i - 1][j];
		}
	}
	
	while (cin >> n)
	{
		for (i = 1;i <= n;i++)
    	{
			printf("%d",f[i][1]);
	    	for (j = 2; j <= i;j++)
	    	{
				printf(" %d",f[i][j]);
	       	}
			printf("\n");
	    }
		putchar('\n');
  	}

}