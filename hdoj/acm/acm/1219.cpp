#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
	char buf[100010],c;
	int ans[27],i,len;
	while (gets(buf))
	{
		memset(ans,0,sizeof(ans));
		len = strlen(buf);
		for (i = 0;i < len;i++)
		{
			if (buf[i] >= 'a' && buf[i] <= 'z')
			{
				ans[buf[i] - 'a']++;
			}
		}
		for (c = 'a';c <= 'z';c++)
		{
			printf("%c:%d\n",c,ans[c - 'a']);
		}
		printf("\n");
	}
	return 0;
}