#include <iostream>
#include <cstdio>
using namespace std;

int T,cas,la,lb,lc;
bool f[205][205][2],ans;
char a[205],b[205],c[505];

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
		/*for (int i = 1;i <= la;i++)
			f[i][0][0] = true;
		for (int j = 1;j <= lb;j++)
			f[0][j][1] = true;*/
		if (la + lb != lc)
			ans = false;
		else
			for (int i = 1;i <= la;i++){
				for (int j = 1;j <= lb;j++){
					if (a[i - 1] == c[i+j-2]){
						f[i][j][0] = f[i-1][j][0] || f[i][j-1][1] || f[i-1][j][1] || (i == 1);
					}
					if (b[j - 1] == c[i+j-2]){
						f[i][j][1] = f[i-1][j][0] || f[i][j-1][0] || f[i][j-1][1] || (j == 1);
					}
				}
			}
		ans = f[la][lb][0] || f[la][lb][1];
		if (ans)
			printf("Data set %d: yes\n",cas);
		else
			printf("Data set %d: no\n",cas);
	}
}