#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;

int main()
{
	int i;
	char c[101];
	while (gets(c))
	{
		
		c[0] = c[0] + 'A' - 'a';
		for (i = 1;i < strlen(c);i++)
		{
			if (c[i] == ' ')
			{
				c[i + 1] = c[i + 1]  + 'A' - 'a';
			}
		}
		printf("%s\n",c);
	}
}