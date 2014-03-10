#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;

#define mod 1000000007
char a[101][101];
bool b[30];
__int64 ans = 1,k;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 0;i < n;i++)
		scanf("%s",&a[i]);
	for (int i = 0;i < m;i++){
		memset(b,0,sizeof b);
		k = 0;
		for (int j = 0;j < n;j++)
			if (!b[a[j][i] - 'A']){
				b[a[j][i] - 'A'] = true;
				k++;
			}
		ans = ans * k % mod;
	}
	printf("%I64d\n",ans);
}