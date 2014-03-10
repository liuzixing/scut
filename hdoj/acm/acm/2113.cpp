#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	char a[100];
	int i,len,sum;
	scanf("%s",&a);
	while (1)
	{
		len = strlen(a);
		sum = 0;
		for (i = 0 ;i < len;i++)
		{
			if ((a[i] - '0') % 2 == 0)
			{
				sum += a[i] - '0';
			}
		}
		if (scanf("%s",&a) != EOF)
		{
			printf("%d\n\n",sum);
		}
		else
		{
			printf("%d\n",sum);
			break;
		}
		
	}
}