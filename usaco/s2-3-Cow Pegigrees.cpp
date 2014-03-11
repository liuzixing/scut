/*
ID: benbenq1
PROG: nocows
LANG: C++
*/
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int f[201][100];
//int c(int n,int k)
//{
//	int i,ans = 1;
//	for (i = n;i > n - k;i--)
//	{
//		ans *= i / (n - i + 1);
//	}
//	return ans;
//}
int main()
{
	ofstream fout ("nocows.out");
	ifstream fin ("nocows.in");
	int n,k,i,ans = 0,j,l;
	fin >> n >> k;
	for (i = 1;i <= k;i++ )
	{
		f[1][i] = 1;
	}
	for (i = 3;i <= n;i++)
	{
		for (j = 2;j <= k;j++)
		{
			for (l = 0;l <= i - 2;l++)
			{
				f[i][j] += f[l][j - 1] * f[i - l - 1][j - 1] % 9901;
			}
			f[i][j] %= 9901;
		}
	}
	fout << (f[n][k] - f[n][k - 1] + 9901) % 9901<< endl;
}