#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
	int len,j = 0,x;
	char c[101];
	while (1)
	{
		int i;
		cin >> c;
		j++;
		if (!strcmp(c,"STOP"))
		{
			break;
		}
		len = strlen(c);
		bool flag = true;
		x = len / 2 - 1;
		for (i = 0;i < len / 2;i++)
		{
			if (c[i] != c[len - i - 1])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			printf("#%d: YES\n",j);
		}
		else
		{
			printf("#%d: NO\n",j);
		}
	}
}