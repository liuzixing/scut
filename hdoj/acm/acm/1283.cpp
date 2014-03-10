#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
	int r1,r2,r3,m1,m2;
	char s[210];
	while (scanf("%d %d",&m1,&m2) != EOF)
	{
		r1 = 0; r2 = 0;r3 = 0;
		scanf("%s",&s);
		for (int i = 0;i < strlen(s);i++)
		{
			switch (s[i])
			{
			case 'A':r1 = m1;break;
			case 'B':r2 = m2;break;
			case 'C':m1 = r3;break;
			case 'D':m2 = r3;break;
			case 'E':r3 = r1 + r2;break;
			case 'F':r3 = r1 - r2;break;
			default:break;
			}
		}
		printf("%d,%d\n",m1,m2);
	}
}
