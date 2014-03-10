#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <set>
using namespace std;

int main()
{
	__int64 count[20]={0,9,18,108,198,1098,1998,10998,19998,109998,199998,1099998,1999998,10999998,19999998,109999998,199999998,1099999998,1999999998,10999999998};
	__int64 ith,n;
	int i,j,k;
	while (scanf("%I64d",&ith) != EOF && ith)
	{
		for (i = 19;i > 0;i--)
		{
			if (ith > count[i])
				break;
		}
		n = ith - count[i] - 1;
		n += (int)pow(10.0,i / 2);//n就是回文的前半部分
		

		i++;
		printf("%I64d",n);
		if (i % 2)
		{
			n /= 10;
			while (n)
			{
				printf("%I64d",n % 10);
				n /= 10;
			}
		}
		else
		{
			while (n)
			{
				printf("%I64d",n % 10);
				n /= 10;
			}
		}
		printf("\n");
	}
}