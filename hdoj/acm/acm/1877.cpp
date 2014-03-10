#include <iostream>
#include <stdio.h>

using namespace std;

void transfrom(__int64 sum, int m)
{
	if (sum / m > 0)
	{
		transfrom(sum / m,m);
	}
	printf("%d",sum % m);
}
int main()
{
	__int64 a,b;
	int m;
	while (scanf("%d %I64d %I64d",&m,&a,&b) && m)
	{
		transfrom(a + b,m);
		printf("\n");
	}
}