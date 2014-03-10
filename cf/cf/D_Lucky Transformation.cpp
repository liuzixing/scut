#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
using namespace std;
char a[100005];
int n,k;
int main(){
	scanf("%d %d\n",&n,&k);
	gets(a);
	int len = 0,t;
	while (len < n && k > 0){
		if (len > 0 && a[len - 1] == '4' &&  a[len] == '4' && len + 1 < n && a[len + 1] == '7'){
			if ((len + 1) % 2 == 0){
				if (k % 2)
					a[len] = '7';
				else
					a[len] = '4';
				break;
			}
		}
		if (a[len] == '4' && len + 1 < n && a[len + 1] == '7'){
			if ((len + 1) % 2){
				a[len + 1] = '4';
			}else{
				a[len] = '7';
				len-=2;
			}
			k--;
			if (k == 0) break;
		}
		len++;
	}
	puts(a);
}