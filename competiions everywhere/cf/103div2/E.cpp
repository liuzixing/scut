#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct node{
	int x,y,num;
}f[100005];
int n,m;
bool cmp(node a,node b){
	return a.x + a.y < b.x + b.y;
}
int main(){
	while (~scanf("%d %d",&n,&m)){
		for (int i = 0;i < m;i++){
			scanf("%d%d",&f[i].x,&f[i].y);
			f[i].num = i;
		}
		sort(f,f + m,cmp);
		int ans = min(m,n);
		printf("%d\n",ans);
		for (int i = 0;i < ans - 1;i++)
			printf("%d ",f[i].num + 1);
		printf("%d\n",f[ans - 1].num + 1);
	}
}