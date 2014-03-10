#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
	char a[1001],c,num[1001];
	int i,j,n,len;
	while (scanf("%s %s",&a,&num) != EOF)
	{
		n = 0;
		len = strlen(num);
		for (i = len - 3;i < len;i++)
		{
			if (i < 0)
			{
				continue;
			}
			n = n * 10 + (num[i] - '0');
		}
		len = strlen(a);
		n %= 8;
		if (n <= 4 && n > 0)
		{
			for (i = 0;i < len / 2;i++)
			{
				c = a[i];
				a[i] = a[len - i - 1];
				a[len - i - 1] = c;
			}
		}
		switch (n)
		{
		case 0:
		case 4:	puts(a);break;
		case 1:
		case 5:
			{
				for (i = 0;i < len;i++)
				{
					for (j = 0;j < len;j++)
					{
						if (j == len - i - 1)
						{
							printf("%c",a[i]);
							break;
						}
						else
						{
							printf(" ");
						}
					}
					printf("\n");
				}
				break;
			}
		case 2:
		case 6:
			{
				for (i = 0;i < len;i++)
				{
					for (j = 0;j < len;j++)
					{
						if (j == len / 2)
						{
							printf("%c",a[i]);
							break;
						}
						else
						{
							printf(" ");
						}	
					}
					printf("\n");
				}
				break;
			}
		case 3:
		case 7:
			{
				for (i = 0;i < len;i++)
				{
					for (j = 0;j < len;j++)
					{
						if (j == i)
						{
							printf("%c",a[i]);
							break;
						}
						else
						{
							printf(" ");
						}	
					}
					printf("\n");
				}
				break;
			}
		default :break;
		}
	}
}