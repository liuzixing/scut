#include <iostream>
#include <cstdio>
using namespace std;

int T,m,n,x,y,ans;
int a[1001][1001];
int sum[1001][1001];

int main()
{
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d%d",&m,&n,&x,&y);
		ans = -10000000;
		memset(sum,0,sizeof sum);
		for (int i = 1;i <= m;i++){
			for (int j = 1;j <= n;j++)
				scanf("%d",&a[i][j]);
		}
		for (int j = 1;j <= n;j++){
			sum[1][j] = a[1][j];
			for (int i = 2;i <= m;i++)
				sum[i][j] = sum[i - 1][j] + a[i][j];
		}
		for (int i = x;i <= m;i++){
			int tem = 0;
			for (int j = 1;j <= y;j++)
				tem += sum[i][j] - sum[i - x][j];
			if (tem > ans) ans = tem;
			for (int j = y + 1;j <= n;j++){
				tem += sum[i][j] - sum[i - x][j] - (sum[i][j - y] - sum[i - x][j - y]);
				ans = max(ans,tem);
			}
		}
		printf("%d\n",ans);
	}
}