
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,a,b,c,t,l,r,ans,x;
int f[20010];
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		memset(f,0xf0,sizeof f);
		l = r = 10000;
		ans = -10000000;
		f[l] = 0;
		while (n--){
			scanf("%d%d%d",&a,&b,&c);
			b += 10000;
			if (a < 0){
				for (int i = b;i <= r;i++)
					if (f[i] != 0xf0f0f0f0)
						if (f[i + a] < f[i] + c)
							f[i + a] = f[i] + c;
				l += a;
			}
			else if (a > 0){
				for (int i = b;i >= l;i--)
					if (f[i] != 0xf0f0f0f0)
						if (f[i + a] < f[i] + c)
							f[i + a] = f[i] + c;
				r += a;
			}
		}
		for (int i = l;i <= r;i++)
			if (f[i] != 0xf0f0f0f0 && f[i] > ans)
				ans = f[i];
		printf("%d\n",ans);
	}
}