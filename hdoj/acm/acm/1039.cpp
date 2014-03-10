#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
	int i,vowel[200],len;
	char a[21];
	memset(vowel,0,sizeof(vowel));
	vowel['a'] = 1;vowel['e'] = 1;vowel['i'] = 1;vowel['o'] = 1;vowel['u'] = 1;
	while (cin >> a)
	{
		len = strlen(a);
		if (!strcmp(a,"end"))
		{
			break;
		}
		bool flag1 = false;
		for (i = 0;i < len;i++)
		{
			if (vowel[a[i]])
			{
				flag1 = true;
				break;
			}
		}
		if (!flag1)
		{
			printf("<%s> is not acceptable.\n",a);
			continue;
		}
		bool flag2 = true;
		for (i = 0;i < len - 2;i++)
		{
			if (vowel[a[i]] && vowel[a[i + 1]] && vowel[a[i + 2]])
			{
				flag2 = false;
				break;
			}
			if (!(vowel[a[i]] || vowel[a[i + 1]] || vowel[a[i + 2]]))
			{
				flag2 = false;
				break;
			}
		}
		if (!flag2)
		{
			printf("<%s> is not acceptable.\n",a);
			continue;
		}
		bool flag3 = true;
		for (i = 0;i < len - 1;i++)
		{
			if (a[i] == a[i + 1] && a[i] != 'e' && a[i] != 'o')
			{
				flag3 = false;
				break;
			}
		}
		if (!flag3)
		{
			printf("<%s> is not acceptable.\n",a);
		}
		else
		{
			printf("<%s> is acceptable.\n",a);
		}
	}
}
