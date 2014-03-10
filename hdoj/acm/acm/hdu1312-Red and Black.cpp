#include <iostream>
#include <cstdio>
using namespace std;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
int w,h,ans;
bool v[21][21];
char a[21][21];
void dfs(int x,int y){
	for (int i = 0;i < 4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 0 && tx < w && ty >= 0 && ty < h && !v[tx][ty] && a[tx][ty] == '.'){
			v[tx][ty] = 1;
			ans++;
			dfs(tx,ty);
		}
	}
}
int main(){
	int x,y;
	while (scanf("%d %d",&h,&w) != EOF && (h + w)){
		for (int i = 0;i < w;i++)
			scanf("%s",&a[i]);
		for (x = 0;x < w;x++)
			for (y = 0;y < h;y++)
				if (a[x][y] == '@')
					goto here;
here:
		ans = 1;
		memset(v,0,sizeof v);
		v[x][y] = 1;
		dfs(x,y);
		printf("%d\n",ans);
	}
}