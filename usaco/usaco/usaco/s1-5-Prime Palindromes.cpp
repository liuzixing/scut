/*
ID: benbenq1
LANG: C++
TASK: pprime
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;
const int N = 9999999;
bool *notprime = new bool[N];
int a,b;
void makeprime()
{
	int i,j,qb;
	for (i = 0;i < N;i++)
	{
		notprime[i] = 0;
	}
	notprime[1] = 1;
	notprime[0] = 1;
	qb =  int(sqrt (double(N)));
	for (i = 2;i <= qb;i++)
	{
		if (!notprime[i])
		{
			for (j = i * 2;j < N;j += i)
			{
				notprime[j] = 1;
			}
		}
	}
}
int makepalindromes(int x)
{
	int t = x;
	x /= 10;
	while (x > 0)
	{
		t = t * 10 + x % 10;
		x /= 10;
	}
	return t;
}
int main()
{
	int i,j,k;
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	scanf("%d %d",&a,&b);
	while (b >= N)
	{
		b--;
	}
	makeprime();
	if(a <= 5 && 5 <= b) printf("5\n");
	if(a <= 7 && 7 <= b) printf("7\n");
	if(a <= 11 && 11 <= b) printf("11\n");
	i = 10;
	while (makepalindromes(i) < a) 
	{
		i++;
	}
	while (makepalindromes(i) <= b)
	{
		k = i;
		j = 1;
		while ( k > 9) 
		{
			k /= 10;
			j *= 10;
		}
		if(k % 2 == 0) 
		{
			i += j;
			continue;
		}
		j = makepalindromes(i);
		if(!notprime[j])
		{
			printf("%d\n",j);
		}
		i++;
	}
}