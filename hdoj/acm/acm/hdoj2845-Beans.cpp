#include <iostream> 
#include <cstdlib> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;
const int N = 200001;
int a[N],v[N][2],u[N],f[N][2];

int init(int b[][2],int c[],int n)
{
	int maxnum = 0;
	for (int i = 1;i <= n;i++)
	{
		b[i][0] = max(b[i - 1][0],b[i - 1][1]);
		b[i][1] = b[i - 1][0] + c[i];
		int temp = max(b[i][0],b[i][1]);
		maxnum = maxnum > temp ? maxnum : temp;
	}
	return maxnum;
}
int main()
{
	int n, m;
	while (scanf("%d%d",&m,&n) != EOF)
	{
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));
		for (int i = 1;i <= m;i++)
		{
			for (int j = 1;j <= n;j++)
				scanf("%d",&a[j]);
			u[i] = init(v,a,n);
		}
		printf("%d\n",init(f,u,m));
	}
}