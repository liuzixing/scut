#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;

char a[101][101];
int n,m,ans;
bool student[101];
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 0;i < n;i++)
		scanf("%s",&a[i]);
	for (int i = 0;i < m;i++){
		char max = '0';
		for (int j = 0;j < n;j++)
			if (a[j][i] > max)
				max = a[j][i];
		for (int j = 0;j < n;j++)
			if (a[j][i] == max)
				student[j] = 1;
	}
	for (int i = 0;i < n;i++)
		if (student[i])
			ans++;
	printf("%d\n",ans);
}