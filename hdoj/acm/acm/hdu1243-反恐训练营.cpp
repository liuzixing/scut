#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
__int64 score[256][256];
int f[2001][2001];
int n,lx,ly;
char x[2000],y[2000],k[2000];
int main(){
	while (cin >> n){
		scanf("%s",&k);
		for (int i=0;i < n;i++)
			scanf("%I64d",&score[k[i]][k[i]]);
		scanf("%s",&x);
		scanf("%s",&y);
		lx = strlen(x);
		ly = strlen(y);
		for (int i = 1;i <= lx;i++){
			for (int j = 1;j <= ly;j++){
				f[i][j] = 0;
				if (f[i][j] < f[i - 1][j])
					f[i][j] = f[i - 1][j];
				if (f[i][j] < f[i][j - 1])
					f[i][j] = f[i][j - 1];
				if (f[i][j] < f[i - 1][j - 1] + score[x[i-1]][y[j-1]])
					f[i][j] = f[i - 1][j - 1] + score[x[i-1]][y[j-1]];
			}
		}
		printf("%I64d\n",f[lx][ly]);
	}
}