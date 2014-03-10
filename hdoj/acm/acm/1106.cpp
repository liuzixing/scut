#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	char s[1010];
	int i,j,n;
	int a[1001];
	while (gets(s))
	{
		memset(a,0,sizeof(a));
		int len = strlen(s);
		for (i = 0,j = 0,n = 0;j < len;j ++)
		{
			if (s[j] == '5')
			{

				for (int k = i;k < j;k++)
				{
					a[n] = a[n] * 10 + s[k] - '0';
					
				}
				if (i < j)
				{
					n++;

				}
				
				while (s[j + 1] == '5')
				{
					j++;
				}
				i = j + 1;
			}
			
		}

		for (int k = i;k < len;k++)
		{
			a[n] = a[n] * 10 + s[k] - '0';
		}
		if (i < len)
		{
			n++;
		}
		sort(a,a + n);
		for (i = 0;i < n - 1;i++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[i]);
	}
}