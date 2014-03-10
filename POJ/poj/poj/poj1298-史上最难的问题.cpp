#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <set>
using namespace std;


int main()
{
	int i,len;
	string s1,s2,s;
	
	while (getline(cin,s1) && getline(cin,s) && getline(cin,s2))
	{
		if (s1 == "ENDOFINPUT")
			break;
		len = s.size();
		for (i = 0;i < len;i++)
		{
			if (isalpha(s[i]))
				putchar(char((s[i] - 'A' + 21) % 26 + 'A'));
			else
				putchar(s[i]);
		}
		putchar('\n');
	}
}