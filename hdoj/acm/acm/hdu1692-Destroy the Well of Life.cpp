#include <cstdio>
#include <iostream>
using namespace std;
int T,n,w[100000],l[100000],p[100000],cas,ma,mi,sum,i,j;
inline int geti()
{
	int r, neg;
	char buf;
	while (buf=getchar(), !isdigit(buf) && buf!='-');
	if (buf == '-') neg = 1, r = 0;
	else neg = 0, r = buf-'0';
	while (buf=getchar(), isdigit(buf)) r = r*10 + buf-'0';
	return neg? -r:r;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (i = 0;i < n;i++)
			w[i] = geti(),l[i] = geti(),p[i] = geti();
		mi= p[n - 1];
		for (i = 0;i < n - 1;i++){
			ma = sum = 0;
			for (j = i;j < n;j++){
				ma += w[j];
				if (ma <= l[j]) sum += p[j];
				if (sum > mi) break;
			}
			if (sum < mi) mi = sum;
		}
		printf("Case %d: Need to use %d mana points.\n",++cas,mi);
	}
}