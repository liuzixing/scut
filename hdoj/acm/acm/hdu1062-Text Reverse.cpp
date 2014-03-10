#include <iostream>
#include <cstdio>
using namespace std;

char a[1005];
int main(){
	int n,l,r;
	cin >> n;
	getchar();
	while (n--){
		
		gets(a);
		l = r = 0;
		while (l == ' ')
			l++;
		while (r == ' ')
			r++;
		while (1){
			while (a[r] != ' ' && r < strlen(a))
				r++;
			for (int i = r - 1;i >= l;i--)
				putchar(a[i]);
			if (r == strlen(a))
				break;
			l = r + 1;
			r++;
			printf(" ");
		}
		printf("\n");
	}
		
}