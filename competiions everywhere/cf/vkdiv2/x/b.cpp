#include <cstdio>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;

char ans[200000][13];
char s[400005];
int main(){
	scanf("%s",&s);
	int l = 0,r = 0,mid = 0,len = strlen(s),tot = 0;
	bool flag = true;
	while (s[mid] != '.' && mid < len)
		mid++;
	r = mid + 1;
	if (r>= len && s[r - 1] == '.' || s[len - 1] == '.') flag = false;
	do {
		if (s[l] == '.'){
			flag = false;

			break;
		}
		while (s[r] != '.' && r < len)
			r++;
		if (mid - l > 8 || r - mid > 12 || (r - mid < 3 && r != len) || (r == len && r - mid > 4)){
			flag = false;

			break;
		}
		int t;
		switch (r - mid){
		case 4:t = mid + 2;break;
		case 3:t = mid + 1;break;
		default:t= mid + 3;break;
		}
		if (r == len) t = r - 1;
		for (int i = l;i <= t;i++){
			ans[tot][i - l] = s[i];
		}
		tot++;
		l = t + 1;
		mid = r;
		r++;
	}while (r < len);
	if (!flag){
		printf("NO\n");
	}else{
		printf("YES\n");
		for (int i = 0;i < tot;i++)
			printf("%s\n",ans[i]);
	}
}