#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

string c,tem1,tem2;
bool g[30][30];
char s[100];
int n,ind[30],a[30];
bool v[30];
void topoo(int k)
{
	if (k == n)
	{
		cout << s << endl;
	}
	int i,j;
	for (i = 0;i < n;i++)
	{
		if (ind[a[i]] == 0 && !v[a[i]])
		{
			v[a[i]] = 1;
			for (j = 0;j < n;j++)
				if (g[a[i]][a[j]])
				{
					ind[a[j]]--;
				}
			s[k] = char (a[i] + 'a');
			topoo(k + 1);
			for (j = 0;j < n;j++)
				if (g[a[i]][a[j]])
				{
					ind[a[j]]++;
				}
			v[a[i]] = 0;
		}
	}

}
int main()
{
	int flag = 0;
	char x,y;
	while (getline(cin,tem1) && getline(cin,tem2))
	{
		if (flag)
			printf("\n");
		flag++;
		memset(s,0,sizeof(s));
		memset(ind,0,sizeof(ind));
		memset(g,0,sizeof(g));
		memset(v,0,sizeof(v));
		istringstream fin(tem1);
		istringstream ffin(tem2);
		while (fin >> x)
			a[n++] = x - 'a';
		sort(a,a + n);
		while (ffin >> x >> y)
		{
			g[x - 'a'][y - 'a'] = 1;
			ind[y - 'a']++;
		}
		topoo(0);
		n = 0;
	}
}