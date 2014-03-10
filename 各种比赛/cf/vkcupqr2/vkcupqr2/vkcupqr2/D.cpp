#include <cstdio>
#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

char a[2005];
__int64 s[2005],e[2005];
__int64 ans;
int main(){
	scanf("%s",&a);
	int len = strlen(a);
	for (int i = 0;i < len;i++){
		for (int j = 0;;j++){
			int tl = i - j ,tr = i + j;
			if (tl < 0 || tr > len) break;
			if (a[tl] != a[tr]) break;
			s[tl]++;
			e[tr]++;
		}
		for (int j = 0;;j++){
			int tl = i - j,tr = i + j + 1;
			if (tl < 0 || tr > len) break;
			if (a[tl] != a[tr]) break;
			s[tl]++;
			e[tr]++;
		}
	}

	for (int i = 0;i < len;i++)
		for (int j = i + 1;j < len;j++)
			ans += e[i] * s[j];
	cout << ans << endl;
}