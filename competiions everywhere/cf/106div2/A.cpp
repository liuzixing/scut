#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string.h>
using namespace std;

int k,a[12],tot,ans;
int main()
{
	scanf("%d",&k);
	for (int i = 0;i < 12;i++)
		scanf("%d",&a[i]);
	sort(a,a + 12);
	if (k)
		for (int i = 11;i >= 0 ;i--){
			tot += a[i];
			ans++;
			if (tot >= k)
				break;
		}
	if (tot >= k)
		printf("%d\n",ans);
	else 
		printf("-1\n");
	return 0;
}