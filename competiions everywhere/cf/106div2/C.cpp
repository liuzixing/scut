#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string.h>
using namespace std;


int n,m;
int a[100005],b[100005];
bool cmp(int x,int y){
	return a[x] > a[y];
}
int main()
{
	scanf("%d",&n);
	for (int i = 0;i < n;i++){
		scanf("%d",a + (b[i] = i));
	}
	sort(b,b + n,cmp);
	printf("%d\n",n - n/2);
	for (int i = 0;i < n;i += 2)
		printf("%d ",b[i] + 1);
	printf("\n");
	printf("%d\n",n / 2);
	for (int i = 1;i < n;i += 2)
		printf("%d ",b[i] + 1);
	printf("\n");
	return 0;
}