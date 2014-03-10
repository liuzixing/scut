#include <iostream>
#include <string>
#include <cstdio>
#include <map>

using namespace std;

const int dx[4] = {0,0,-1,1};
const int dy[4] = {1,-1,0,0};
const char d[4] = {'r','l','u','d'};
char a[10];
char b[] = "123456780";
string ans;
void dfs(int x,int y){
	if (!strcmp(a,b)){
		cout << ans << endl;
		exit(0);
	}
	for (int k = 0;k < 4;k++){
		int tx = x + dx[k];
		int ty = y + dy[k];
		if (tx < 3 && ty < 3 && tx >= 0 && ty >= 0){
			swap(a[tx * 3 + ty],a[x * 3 + y]);
			ans += d[k];
			dfs(tx,ty);
			swap(a[tx * 3 + ty],a[x * 3 + y]);
			ans.erase(ans.size() - 1,1);
		}
	}
}
int main()
{
	int i,j;
	for (i = 0;i < 8;i++){
		scanf("%c ",&a[i]);
		if (a[i] == 'x')
			j = i;
	}
	scanf("%c",&a[i]);
	dfs(j / 3,j % 3);
}