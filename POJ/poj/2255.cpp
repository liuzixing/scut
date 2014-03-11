#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char preord[30],inord[30];
int pre;
void buildandoutput(int l,int r)
{
	if (l > r)
	{
		return;
	}
	int i,tem;
	pre++;
	tem = pre;
	if (l == r)
	{
		printf("%c",preord[pre]);
		return;
	}
	for (i = l;i <= r;i++)
		{
			if (inord[i] == preord[pre])
			{
				buildandoutput(l,i-1);
				buildandoutput(i + 1,r);
				break;
			}
		}
	printf("%c",preord[tem]);
}
int main()
{
	int i,len;
	while (scanf("%s %s",&preord,&inord) == 2)
	{
		pre = 0;
		len = strlen(preord);
		for (i = 0;i < len;i++)
		{
			if (inord[i] == preord[pre])
			{
				buildandoutput(0,i-1);
				buildandoutput(i + 1,len - 1);
				break;
			}
		}
		printf("%c\n",preord[0]);
	}
}