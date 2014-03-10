#include <iostream>
#include <cstdio>
using namespace std;

int T,cas,la,lb,lc;
bool f[205][205],ans;
char a[205],b[205],c[505];
void dp(int x,int y,int z){
	if (z == lc){
		ans = true;
		return;
	}
	if (f[x][y]) return;
	f[x][y] = 1;
	if (a[x] == c[z])
		dp(x + 1,y,z + 1);
	if (b[y] == c[z])
		dp(x,y + 1,z + 1);
}
int main(){
	scanf("%d",&T);
	while (T--){
		cas++;
		scanf("%s%s%s",a,b,c);
		la = strlen(a);
		lb = strlen(b);
		lc = strlen(c);
		ans = false;
		memset(f,0,sizeof f);
		if (la + lb != lc)
			ans = false;
		else
			dp(0,0,0);
		if (ans)
			printf("Data set %d: yes\n",cas);
		else
			printf("Data set %d: no\n",cas);
	}
}