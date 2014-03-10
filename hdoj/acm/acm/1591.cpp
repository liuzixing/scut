#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
	char key1[26],key2[26],key3[26],key4[26];
	char w[26];
	char ans[10000];
	bool f[26] = {0};
	int len,i,j;
	cin.getline(w,27,'\n');
	len = strlen(w);
	for (i = 0;i < len;i++)
	{
		key1[i] = w[i];
		key2[i] = w[i] - 'A' + 'a';
		f[w[i] - 'A'] = 1;
	}
	for (i = len,j = 25;i < 26;i++)
	{
		while (f[j])
		{
			j--;
		}
		key1[i] = 'A' + j;
		key2[i] = j + 'a';
		f[j] = 1;
	}
	for (i = 0;i < 26;i++)
	{
		key3[key1[i] - 'A'] = 'A' + i;
		key4[key2[i] - 'a'] = 'a' + i;
	}
	while (cin.getline(ans,10000,'\n'))
	{
		len = strlen(ans);
		for (i = 0;i < len;i++)
		{
			if (ans[i] >= 'A' && ans[i] <= 'Z')
			{
				ans[i] = key3[ans[i] - 'A'];
			}
			if (ans[i] >= 'a' && ans[i] <= 'z')
			{
				ans[i] = key4[ans[i] - 'a'];
			}
		}
		puts(ans);
	}
}