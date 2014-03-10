#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char ctp[26] = {'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'};
int main()
{
	char start[20],end[4],s[10001];
	int i;
	
	while (gets(start))
	{
		if (!strcmp(start,"ENDOFINPUT"))
		{
			break;
		}
		gets(s);
		gets(end);
		int len = strlen(s);
		for (i = 0;i < len;i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] = ctp[s[i] - 'A'];
			}
		}
		puts(s);
	}
}