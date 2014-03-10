#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
	map<string,string>mp;
	string a,b;
	int n,i,flag;
	set<string> s;
	set<string>::iterator it;

	while (cin >> n && n)
	{
		s.clear();
		mp.clear();
		for (i = 0;i < n;i++)
		{
			cin >> a >> b;
			s.insert(a);
			s.insert(b);
			mp[b] = a;
		}
		for (flag = 0,it = s.begin();it != s.end();it++)
		{
			if (!mp[*it].length())
			{
				flag++;
			}
		}
		puts((flag ==1) ? "Yes":"No");

	}
}