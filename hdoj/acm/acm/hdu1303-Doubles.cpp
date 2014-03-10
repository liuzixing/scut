#include <cstdio>
#include <algorithm>
using namespace std;

int a[16],n,ans;
int main(){
	while (~scanf("%d",&a[0])){
		if (a[0] == -1)break;
		n = 1;
		while (~scanf("%d",&a[n])){
			if (a[n] == 0)break;
			n++;
		}
		sort(a, a + n);
		ans = 0;
		for (int i = 0;i < n - 1;i++)
			for (int j = i + 1;j < n;j++)
				if (a[i] * 2 == a[j])
					ans++;
		printf("%d\n",ans);
	}
}