#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,x,y,tot;
int a[100005],b[100005],k;
struct node{
	int aa,bb;
}ans[100005];
int main(){
	scanf("%d %d %d %d",&n,&m,&x,&y);
	for (int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	for (int i = 0;i < m;i++)
		scanf("%d",&b[i]);
	int j = 0,l = 0;
	for (int i = 0;i < n;i++){
		for (j = l;j < m;j++)
			if (a[i] - x<= b[j] && a[i] + y >= b[j]){
				ans[tot].aa = i + 1;
				ans[tot++].bb = j + 1;
				l = j + 1;
				break;
			}else if (a[i] + y < b[j]){
				l = j;
				break;
			}
		if (a[i] - x > b[m - 1])break;
	}
	cout << tot << endl;
	for (int i = 0;i < tot;i++)
		printf("%d %d\n",ans[i].aa,ans[i].bb);
	return 0;
}