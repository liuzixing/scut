/*
ID: benbenq1
PROG: zerosum
LANG: C++
*/
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
char path[20];
int n,i;
void dfs(int len ,int k,int sum,int last)
{
	if (k == n)
	{
		if (sum == 0)
		{
			for (i = 0;i <= len - 1;i++)
			fout << path[i];
			fout << endl;
		}
		return;
	}
	path[len] = ' ';
	path[len + 1] = k + 1 + '0';
	if (last > 0)
	{
		dfs(len + 2,k + 1,sum - last + last * 10 + k + 1,last * 10 + k + 1);
	}
	else
	{
		dfs(len + 2,k + 1,sum - last + last * 10 - k - 1,last * 10 - k - 1);
	}
	path[len] = '+';
	dfs(len + 2,k + 1,sum + k + 1,k + 1);
	path[len] = '-';
	dfs(len + 2,k + 1,sum - k - 1,- k - 1);
}
int main()
{
	fin >> n;
	path[0] = '1';
	dfs(1,1,1,1);
}