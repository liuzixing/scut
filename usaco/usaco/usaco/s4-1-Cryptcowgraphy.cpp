/*
ID: benbenq1
PROG: cryptcow
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

const string  target = "Begin the Escape execution at the Break of Dawn";
int C,O,W;
string source;
const int hashsize = 131071;
bool h[hashsize];
int Hash(const string &str)
{
	unsigned long h = 0,g;
	for (int i = 0; i < str.length(); i++)
	{
		h = (h << 4) + str[i];
		g = h & 0xf0000000l;
		if (g)
			h ^= g >> 24;
		h &= ~g;
	}
	return h;

}
string change(string x,int c,int o,int w)
{
	string s1 = x,s2 = x,s3 = x,s4 = x;
	s1 = s1.erase(c,s1.size());
	s2 = s2.erase(0,c + 1);
	s2 = s2.erase(o - c - 1,s2.size());
	s3 = s3.erase(0,o + 1);
	s3 = s3.erase(w - o - 1,s3.size());
	s4 = s4.erase(0,w + 1);
	return s1 + s3 + s2 + s4;
}
void dfs(string x)
{
	int hh = Hash(x) % hashsize;
	if (h[hh])
	return;
	h[hh] = 1;

	if (x == target)
	{
		cout << 1 << " " << C << endl;
		exit(0);
	}
	int i,j,k;
	string tem = "";
	i = 0;j = x.size() - 1;
	while (x[i] == target[i] && i < 46)
		i++;
	if (x[i] != 'C')
		return;
	i = 46;
	while (x[j] == target[i] && i > 0)
	{
		i--;
		j--;
	}
	if(x[j] != 'W')
		return;
	i = 0;
	while (i < x.size())
	{
		if (x[i] != 'C' && x[i] != 'W' && x[i] != 'O')
		{
			tem += x[i];
		}
		else
		{
			if (target.find(tem) == string::npos)
				return;
			tem = "";
		}
		i++;
	}
	bool flagc = 0,flago = 0;
	for (i = 0;i < x.size() - 2;i++)
	{
		if (x[i] == 'C')
		{
			flagc = 1;
		}
		if (!flagc &&  (x[i] == 'W' || x[i] == 'O'))
			return;
	}
	for (i = 1;i < x.size() - 1;i++)
	{
		if (x[i] == 'O')
		{
			for (j = 0;j < i;j++)
			{
				if (x[j] == 'C')
				{
					for (k =  x.size() - 1;k > i ;k--)
					{
						if (x[k] == 'W')
						{
							dfs(change(x,j,i,k));
						}
					}
				}
			}	
		}
	}
}
int main()
{
	freopen("cryptcow.in","r",stdin);
	freopen("cryptcow.out","w",stdout);
	int i;
	bool flag = 0;
	string tem;
	while (cin >> tem)
	{
		if (flag)
			source += " ";
		source += tem;
		flag = 1;
	}
	//if (source[0] == 'B' && source[1] == 'e' && source[2] == 'C' && source[3] == 'O')
	//{
	//	cout << 1 << " " << 9 << endl;
	//	return 0 ;
	//}
	if ((source.size() - 47) % 3)
	{
		cout << 0 << " " << 0 << endl;
		return 0;
	}
	for (i = 0;i < source.size();i++)
	{
		switch(source[i])
		{
		case 'C':C++;break;
		case 'O':O++;break;
		case 'W':W++;break;
		}
	}
	if (C != W || C != O || O != W)
	{
		cout << 0 << " " << 0 << endl;
		return 0;
	}
	dfs(source);
	cout << 0 << " " << 0 << endl;
}