#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int n;
int a[41][3],s[3],sm;
bool f[121][121][121];
bool t[121][121][121];
int main(){
	while (~scanf("%d",&n)){
		s[1] = s[2] = s[0] = 0;
		for (int i = 1;i <= n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			s[0] += a[i][0];s[1] += a[i][1];s[2] += a[i][2];
		}
		sm = min(s[0],min(s[1],s[2]));
		memset(f,0,sizeof f);
		memset(t,0,sizeof t);
		t[0][0][0] = 1;
		if (n > 2){
			for (int i = 1;i <= n;i++){
				for (int j = sm;j >= 0;j--)
					for(int k = sm;k >= 0;k--)
						for (int l = sm;l >= 0;l--){
							if (j >= a[i][0] && f[j - a[i][0]][k][l]) f[j][k][l] = 1;
							if (k >= a[i][1] && f[j][k - a[i][1]][l]) f[j][k][l] = 1;
							if (l >= a[i][2] && f[j][k][l - a[i][2]]) f[j][k][l] = 1;
						}
				memcpy(t,f,sizeof f);
			}
		}
		int ans = -1;
		for (int j = 1;j <= sm;j++)
			if (f[j][j][j]){
				ans = j;
				break;
			}
			if (ans == -1)
				printf("NO\n");
			else
				printf("%d\n",ans);
	}
}