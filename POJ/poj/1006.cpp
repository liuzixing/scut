#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int p,e,i,j,d,k = 1;
	scanf("%d %d %d %d",&p,&e,&i,&d);
	while (p+d+e+i != -4)
	{
		p %= 23;
		e %= 28;
		i %= 33;
		for (j = d + 1;j <= 21252 + d;j++)
		{
			if ((j - p) % 23 == 0 &&  (j - e) % 28 == 0 && (j - i) % 33 == 0)
			{
				break;
			}
		}
		printf("Case %d: the next triple peak occurs in %d days.\n",k,j - d);
		scanf("%d %d %d %d",&p,&e,&i,&d);
		k++;
	}
}