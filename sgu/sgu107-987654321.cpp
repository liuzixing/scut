#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n,i;
int main()
{
	scanf("%d",&n);
	if (n < 9)
		printf("%d\n",0);
	else if (n == 9)
		printf("%d\n",8);
	else 
	{
		printf("%d",72);
		for (i = 10;i < n;i++)
			printf("0");
		printf("\n");
	}
}