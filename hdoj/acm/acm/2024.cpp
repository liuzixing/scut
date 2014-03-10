#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;

int main()
{
	int i,t;
	char  c[50];
	scanf("%d%*c",&t);
	while (t)
	{
		t--;
		gets(c);
		if (c[0] != '_' && !isalpha(c[0]))
		{
			puts("no");
			continue;
		}
		bool flag = true;
		for (i = 1; c[i] ;i++)
		{
			if ( (!isalnum(c[i])) && c[i] != '_')
			{
				flag = 0;
				break;
			}
		}
		puts(flag ? "yes" : "no");
	}
}