#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int n;
char a[35][35];
__int64 f[35][35];

__int64 dfs(int x,int y){
	if (f[x][y] > 0)
		return f[x][y];
	if (a[x][y] == '0')
		return 0;
	if (x + a[x][y] - '0' < n)
		f[x][y] += dfs(x + a[x][y] - '0',y);
	if (y + a[x][y] - '0' < n)
		f[x][y] += dfs(x,y + a[x][y] - '0');
	return f[x][y];
}
int main(){
	while (scanf("%d",&n) !=  EOF){
		if (n == -1) break;
		for (int i = 0;i < n;i++)
			scanf("%s",&a[i]);
		memset(f,0,sizeof f);
		f[n - 1][n - 1] = 1;
		printf("%I64d\n",dfs(0,0));
	}
	return 0;
}