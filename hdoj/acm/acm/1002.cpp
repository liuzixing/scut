#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int ans[1010];
void conversion (char c[],int a[])
{
	int i,len;
	len = strlen(c);
	a[0] = len;
	for (i = 1;i <= len; i++)
	{
		a[i] = c[len - i] - '0';
	}
}
void add(int a[],int b[])
{
	int i;
	memset(ans,0,sizeof(ans));
	if (a[0] > b[0])
	{
		ans[0] = a[0];
	}
	else
	{
		ans[0] = b[0];
	}
	for (i = 1; i <= ans[0];i++)
	{
		ans[i] += a[i] + b[i];
		ans[i + 1] += ans[i] / 10;
		ans[i] = ans[i] % 10;
	}
	if (ans[ans[0] + 1] > 0)
	{
		ans[0]++;
	}
	for (i = ans[0];i > 0;i-- )
	{
		printf("%d",ans[i]);
	}
}
int main()
{
	int t,n;
	char c1[1010],c2[1010];
    int a[1010],b[1010];
	cin >> t;
	n = t;
	while (t)
	{
		t--;
		scanf("%s %s",&c1,&c2);
		printf("Case %d:\n",n - t);
		printf("%s + %s = ",c1,c2);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		conversion(c1,a);
		conversion(c2,b);
		add(a,b);
		if (t)
		{
			printf("\n\n");
		}
		else
		{
			printf("\n");
		}
		
	}
}