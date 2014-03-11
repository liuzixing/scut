#include <stdio.h>
#include <cmath>
#include <algorithm>
int main()
{
	int i,j,n,ii,jj,k;
	while(scanf("%d",&n) &&n!=-1)
	{
		n--;
		for(i=0;i < pow(3.0,n);i++,printf("\n"))
		{
			for(j=0;j < pow(3.0,n);j++)
			{
				for(ii = i,jj = j,k = 0;k < n && (ii % 3 + jj % 3) % 2 == 0;ii /= 3,jj /= 3,k++);
				printf("%c",32 + 56 * (k == n));
			}
		}
		printf("-\n");
	} 
}
