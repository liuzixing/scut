#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
short f[30001][2],ans;
int w[26][30001];
int main()
{
	char a[30001],b[30001];
	short i,j,la,lb,k;
	while (scanf("%s %s",&a,&b) != EOF)
	{
		ans = 0;
		la = strlen(a);
		lb = strlen(b);
		k = 0;
		for (i = 0;i < lb;i++){
			w[b[i] - 'A'][0]++;
			w[b[i] - 'A'][w[b[i] - 'A'][0]] = i;
		}
		for (i = 1;i <= la;i++)
		{
			int tk = (k + 1) % 2;
			for (j = 1;j <= w[a[i - 1] - 'A'][0];j++)
			{
				int tem = w[a[i - 1] - 'A'][j];
					f[tem + 1][tk] = f[tem][k] + 1;
				ans = max(ans,f[tem + 1][tk]);
			}
			k = tk;
		}
		printf("%d\n",ans);
	}
}
