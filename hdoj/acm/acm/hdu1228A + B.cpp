#include <iostream>
#include <cstdio>
using namespace std;

char dig[10][10] = {"zeor","one","two","three","four","five","six","seven","eight","nine"};
char a[10],b[10];
int aa,bb;
int getdigit(char x[]){
	for (int i = 0;i < 10;i++)
		if (!strcmp(x,dig[i]))
			return i;
	return 0;
}
int main(){
	while (~scanf("%s",&a)){
		aa = getdigit(a);
		while (~scanf("%s",a)){
			if (a[0] == '+') break;
			aa = aa * 10 + getdigit(a);
		}
		bb = 0;
		while (~scanf("%s",b)){
			if (b[0] == '=') break;
			bb = bb * 10 + getdigit(b);
		}
		if (aa == 0 && bb == 0) break;
		cout << aa + bb << endl;
	}
}