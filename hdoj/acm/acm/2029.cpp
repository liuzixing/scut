#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;

int main()
{
	int i,n,len;
	char a[1000];
	scanf("%d%*c",&n);
	while (n--)
	{
		gets(a);
		len = strlen(a);
		bool flag = true;
		for (i = 0;i < len / 2;i++)
		{
			if (a[i] != a[len - i - 1])
			{
				flag  = false;
				break;
			}
		}
		if (flag)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
}