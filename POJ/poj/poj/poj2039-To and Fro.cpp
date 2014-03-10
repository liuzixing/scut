#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int n,i,j,start,k;
	char s[210],c;
	while (cin >> n && n)
	{
		cin >> s;
		i = 0;
		j = 0;
		start = 0;
		k = 1;
		while (i < strlen(s))
		{
			i++;
			putchar(s[j]);
			if (k % 2)
				j += (n - start) * 2 - 1;
			else
				j += start * 2 + 1;
			k++;
			if(j > strlen(s) - 1)
			{
				j = start + 1;
				start++;
				k = 1;
			}
		}
		putchar('\n');
	}
}