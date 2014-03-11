#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
void gjc()
int main()
{
	int a,b,n,i,j,rest = 0,ans[1001],tem,last[520];
	cin >> n;
	ans[0] = 0;
	if (n % 2)
	{
		scanf("%d",&b);
		ans[0]++;
		ans[1] = int (sqrt(double (b)));
		rest = b - ans[1] * ans[1];
	}
	for (i = 0;i < n / 2 ;i++ )
	{
		scanf("%d",&a);
		scanf("%d",&b);
		tem = rest * 100 +a * 10 + b;
		for (j = 0;j <= 9;j++)
		{
			if (tem < ans[ans[0]] * j * 20 + j * j)
			    break;
		}
		j--;
		rest = tem - (ans[ans[0]] * j * 20 +j * j);
		ans[0]++;
		ans[ans[0]] = j;
	}
    printf("%d\n",ans[0]);
	for (i = 1;i <= ans[0];i++)
	{
		printf("%d\n",ans[i]);
	}
}