#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

__int64 target;
char quotation[13],ans[6];
int len;
bool flag;
int power(int a,int b)
{
	int i,x = 1;
	for (i = 0;i < b;i++)
		x *= a;
	return x;
}
bool judge(int i,int len)
{
	int j;
	for (j = 0;j <= len;j++)
		if (ans[j] == quotation[i])
			return false;
	return true ;
}
void dfs(int x,int sum)
{
	if (x == 6)
	{
		if (target == sum)
		flag = true;
		return;
	}
	int i;
	for (i = len - 1;i >= 0 && !flag;i--)
	{
		if (!judge(i,x - 1))
			continue;
		ans[x - 1] = quotation[i];
		if (x % 2)
			dfs(x + 1,sum + power(quotation[i] - 'A' + 1,x));
		else
			dfs(x + 1,sum - power(quotation[i] - 'A' + 1,x));
	}
	return;
}
int main()
{
	while (1)
	{
		scanf("%I64d %s",&target,&quotation);
		if (target == 0 && !strcmp(quotation,"END"))
			break;
		len = strlen(quotation);
		sort(quotation,quotation + len);
		memset(ans,0,sizeof(ans));
		flag = false;
		dfs(1,0);
		if (!flag)
			printf("no solution\n");
		else
			printf("%s\n",ans);
	}
}
