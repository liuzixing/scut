#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;

int n,l;
int a[101],b[101],f[10101][17];
int main(){
	while (~scanf("%d%d",&l,&n)){
		for (int i = 0; i < l;i++)
			scanf("%d",&a[i]);
		for (int i = 0; i < l;i++)
			scanf("%d",&b[i]);
		memset(f,0x3f,sizeof f);
		f[0][0] = 0;
		n = n * l;
		for (int i = 1;i <= n;i++)
		{
			f[i][0] = f[i - 1][5] + b[(i - 1) % l];
			for (int j = 1;j <= 9;j++)
				f[i][j] = min(f[i - 1][j - 1] + a[(i - 1) % l],f[i - 1][j + 5] + b[(i - 1) % l]);
			f[i][10] =  min(f[i - 1][14],f[i - 1][9])+ a[(i - 1) % l];//trick
			for (int j = 11;j < 15;j++)
				f[i][j] = f[i - 1][j - 1] + a[(i - 1) % l];
		}
		sort(f[n],f[n] + 15);

		int ans = 0;
		while (f[n][ans] == 0)
			ans++;
		printf("%d\n",f[n][ans]);
	}
}