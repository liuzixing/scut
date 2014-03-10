#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int dx[3] = {0,-2,-1};
const int dy[3] = {-2,0,-1};
int n,ans;
int a[21][21];
int f[21][21][2];
int main(){
	while (~scanf("%d",&n)){
		memset(f,0,sizeof f);
		ans = 0;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				scanf("%d",&a[i][j]);
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++){
				f[i][j][0] = max(max(max(f[i - 1][j][0],f[i - 1][j][1]),f[i][j - 1][0]),f[i][j - 1][1]);
				f[i][j][1] = a[i][j] + max(f[i][j - 1][0] ,f[i - 1][j][0]);
				ans = max(max(f[i][j][0],f[i][j][1]),ans);
			}

		printf("%d\n",ans);
	}
}