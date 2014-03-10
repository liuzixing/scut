#include <iostream>
#include <cstdio>
using namespace std;

int n;
int a[11];
int total,flag;
bool check(int x){
	while (x){
		if (x % 10 != 4 && x % 10 != 7){
			return 0;
		}
		x /= 10;
	}
	return 1;
}
int main()
{
	int i;
	scanf("%d",&n);
	for (int i = n;i >= 4;i--)
	{
		if (check(i)){
			if (n % i == 0){
				flag = 1;
				break;
			}
		}
	}
	if (flag) printf("YES\n");
	else printf("NO\n");
}