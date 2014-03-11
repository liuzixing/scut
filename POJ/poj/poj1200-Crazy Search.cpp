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

char s[16000010];
bool hashnum[12582917];
int b[200];
int main()
{
	int n,nc;
	int i,j,k,tem,ans,len;
	scanf("%d%d",&n,&nc);
	getchar();
	gets(s);
	k = 0;
	len = strlen(s);
	for(i = 0;i < len;i++)
	{
		if(!b[s[i]])
		{
			b[s[i]] = k++;
		}
		if(k >= nc)
		{
			break;
		}
	}
	ans = 0;
	for(i = 0;i <= len - n;i++)
	{
		tem = 0;
		for(j = i;j < i + n;j++)
		{
			tem *= nc;
			tem += 	b[s[j]];
		}
		if(hashnum[tem] == 0)
		{
			ans++;
			hashnum[tem] = 1;
		}
	}
	printf("%d\n",ans);
}