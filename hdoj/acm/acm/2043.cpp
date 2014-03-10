#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

int judge(char x)
{
	if (x <= 'Z' && x >= 'A')
	{
		return 0;
	}
	if (x <= 'z' && x >= 'a')
	{
		return 1;
	}
	if (x <= '9' && x >= '0')
	{
		return 2;
	}
	switch(x)
	{
	case '~':
	case '!':
	case '@':
	case '#':
	case '$':
	case '%':
	case '^':return 3;
	default:return 4;
	}
}
int main()
{
	int m,i;
	char s[60];
	scanf("%d%*c",&m);
	while (m--)
	{
		int a[5] = {0};
		int count = 0;
		gets(s);
		int len = strlen(s);
		if (len > 16 || len < 8)
		{
			printf("NO\n");
			continue;
		}
		for (i = 0;i < len;i++)
		{
			a[judge(s[i])]++;
		}
		for (i = 0;i < 4;i++)
		{
			if (!a[i])
			 count ++;
		}
		if (count < 2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

}