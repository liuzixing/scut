#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
	int n,i,count;
	char c[10001];
	cin >> n;
	while (n--)
	{
		scanf("%s",&c);
		int len = strlen(c);
		i = 0;
		c[len] = '1';
		while (i < len)
		{
			count = 0;
			while (c[i] == c[i + 1])
			{
				count++;
				i++;
			}
			
			if (count > 0)
		    {
		    	 printf("%d%c",count + 1,c[i]);
		    }
		    else
		    {
		    	printf("%c",c[i]);
		    }
			i++;
		}
		printf("\n");
	}
}