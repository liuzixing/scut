#include <iostream>
#include <cstdio>
#include<cstring>
#include <string>
#include <string.h>
using namespace std;

char a[52];
int f,s;
int main(){
	gets(a);
	for (int i = 0;i < strlen(a);i++){
		if (a[i] == '4') f++;
		if (a[i] == '7') s++;
	}
	if (f == 0 && s == 0)
		printf("-1\n");
	else if (f >= s) printf("4\n");
	else printf("7\n");

}
