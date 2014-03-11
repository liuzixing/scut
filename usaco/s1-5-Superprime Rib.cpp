/*
ID: benbenq1
LANG: C++
TASK: sprime
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;
const int d1[4] ={2,3,5,7}; 
const int d2[5] = {1,3,5,7,9};
int N;
bool isprime(int x)
{
	int i,m;
	m = (int) sqrt(double (x));
	for (i = 2;i <= m;i++)
	{
		if (x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
void dfs(int k,int num)
{
	int i;
	if (!isprime(num))
	{
		return;
	}
	if (k > N)
	{
		printf("%d\n",num);
		return;
	}
	for (i = 0;i < 5;i++)
	{
		dfs(k + 1,num * 10 + d2[i]);
	}
}
int main()
{
	int i;
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	scanf("%d",&N);
	for (i = 0;i < 4;i++)
	{
		dfs(2,d1[i]);
	}
	return 0;
}