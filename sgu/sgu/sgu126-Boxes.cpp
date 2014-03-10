#include <iostream>
#include <cstdio>
using namespace std;

int a,b,ans;

bool check(int a,int b,int &ans)
{
	if (a == 0 || b == 0)
		return 1;
	if (a < b)
		return 0;
	ans++;
	return check(a - b,b + b,ans);
}
int main()
{
	scanf("%d%d",&a,&b);
	if (a < b)
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
	ans = 0;
	if (check(a,b,ans))
		printf("%d\n",ans);
	else 
		printf("-1\n");
}