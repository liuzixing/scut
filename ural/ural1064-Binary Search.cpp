#include <cstdio>
#include <cmath>
using namespace std;

int n,l;
int ans[10005],tot;
bool check(int p,int q,int now){
	int m = (p + q) >> 1;

	if (p > q || l < now)
		return false;
	if (m == n && now == l) return 1;
	return  (check(p,m - 1,now + 1) || check(m + 1,q,now + 1));
}
int main(){
	scanf("%d %d",&n,&l);
	for (int i = 1;i < 10001;i++)
		if (check(0,i - 1,1)){
			ans[i] = 1;
			tot++;
			while (i + 1< 10001 && check(0,i,1) == 1){
				i++;
				ans[i] = 1;
			}
		}
	printf("%d\n",tot);
	for (int i = 1;i < 10001 && tot;i++)
		if (ans[i] == 1){
			tot--;
			printf("%d",i);
			int j = i;
			while (ans[j])
				j++;
			if (i == j) j++;
			printf(" %d\n",j - 1);
			i = j;
		}
	return 0;
}