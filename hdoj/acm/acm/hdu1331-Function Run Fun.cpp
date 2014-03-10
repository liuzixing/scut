#include <iostream>
#include <cstdio>
using namespace std;

__int64 w[21][21][21];

__int64 dfs(int a,int b,int c){
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (w[a][b][c] > 0)
		return w[a][b][c];
	if (a < b && b < c)
		w[a][b][c] = dfs(a,b,c - 1) + dfs(a,b - 1,c - 1) - dfs(a,b - 1,c);
	else
		w[a][b][c] = dfs(a-1, b, c) + dfs(a-1, b-1, c) + dfs(a-1, b, c-1) - dfs(a-1, b-1, c-1);
	return w[a][b][c];
}
int main(){
	int a,b,c;
	while (~scanf("%d %d %d",&a,&b,&c)){
		if (a == -1 && b == -1 && c == -1)break;
		printf("w(%d, %d, %d) = ",a,b,c);
		if (a <= 0 || b <= 0 || c <= 0)
			a = b = c = 0;
		if (a > 20 || b > 20 || c > 20)
			a = b = c = 20;
		printf("%I64d\n",dfs(a,b,c));
	}
}