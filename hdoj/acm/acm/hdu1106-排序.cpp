#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

char a[10005];
int b[10005];
int main(){
	while (gets(a)){
		int tot = 0;
		int l = 0,r = 0;
		while (l < strlen(a) && a[l] == '5')
			l++;
		r = l;
		while (1){
			while (r < strlen(a) && a[r] != '5')
				r++;
			int t = 0;
			for (int i = l ;i < r;i++)
				t = t * 10 + a[i] - '0';
			b[tot++] = t;
			while (a[r] == '5' && r < strlen(a))
				r++;
			l = r;
			if (r >= strlen(a) - 1)
				break;
		}
		sort(b,b + tot);
		printf("%d",b[0]);
		for (int i = 1;i < tot;i++)
			printf(" %d",b[i]);
		printf("\n");
	}
}