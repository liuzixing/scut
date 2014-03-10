#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int f[50],a,b,n,i;
	f[1] = 1;
	f[2] = 1;
	while (scanf("%d%d%d",&a,&b,&n) && n !=0)
	{
		for (i = 3;i < 50;i++)
	    {
		    f[i] = (f[i -1 ] * a + f[i - 2] * b) % 7;
	    }
		n = n % 49;
		if (!n)
		{
			n = 49;
		}
		printf("%d\n",f[n]);
	}
}