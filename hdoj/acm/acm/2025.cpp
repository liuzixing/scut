#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;

int main()
{
	int max,i;
	char tem,ch[101];
	while (cin >> ch)
	{
		max = -1;
		for (i = 0;i < strlen(ch);i++)
		{
			if (max < ch[i])
			{
				max = ch[i];
				tem = ch[i];
			}
		}
		for (i = 0;i < strlen(ch);i++)
		{
			if (ch[i] == tem)
			{
				printf("%c(max)",ch[i]);
			}
			else
			{
				printf("%c",ch[i]);
			}
		}
		printf("\n");
	}
}
