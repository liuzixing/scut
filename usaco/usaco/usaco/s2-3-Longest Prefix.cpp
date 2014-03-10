/*
ID: benbenq1
PROG: prefix
LANG: C++
*/
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
ofstream fout("prefix.out");
ifstream fin ("prefix.in");
char a[201][11];
string tem,s = "";
int n,maxn = 0,ls,d[201];
bool f = 0;
int main()
{

	for (n = 0;;n++)
	{
		fin >> a[n];
		if(a[n][0] == '.')
		{
			break;
		}
		d[n] = strlen(a[n]);
	}
	n--;	
	while (fin >> tem)
	{
		s += tem;
	}
	ls = s.length();

	for (int i = 0;i < ls;i++)
	{
		for (int j = 0;j <= n;j++)
		{
			if (i + d[j] > ls)
			{
				continue;
			}
			else
			{
				f = 0;
				for (int k = 0;k < d[j];k++)
				{
					if (s[i + k] != a[j][k])
					{
						f = 1;
						break;
					}
				}
				if (!f)
				{
					maxn = (d[j] + i > maxn ? d[j] + i: maxn);
				}
			}
		}
		if (i + 1 > maxn)
		{
			break;
		}
	}
	fout << maxn << endl;
}