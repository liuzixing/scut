#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t,a,b,n,k,c[9],d[9];
	cin >> t;
	while (t--)
	{
		scanf("%d %d",&n,&k);
		int ans = 0;
		memset(d,0,sizeof(d));
		for (int i = 0;i < k;i++)
		{
			scanf("%d %d",&a,&b);
			d[a] = b;
		}
		for (c[8] = 0; c[8] <= d[8] && c[8] * 8 <= n; c[8]++)
        for (c[7] = 0; c[7] <= d[7] && c[8] * 8 + c[7] * 7 <= n; c[7]++)
        for (c[6] = 0; c[6] <= d[6] && c[8] * 8 + c[7] * 7 + c[6] * 6 <= n; c[6]++)
        for (c[5] = 0; c[5] <= d[5] && c[8] * 8 + c[7] * 7 + c[6] * 6 + c[5] * 5 <= n; c[5]++)
        for (c[4] = 0; c[4] <= d[4] && c[8] * 8 + c[7] * 7 + c[6] * 6 + c[5] * 5  + c[4] * 4 <= n; c[4]++)
        for (c[3] = 0; c[3] <= d[3] && c[8] * 8 + c[7] * 7 + c[6] * 6 + c[5] * 5  + c[4] * 4  + c[3] * 3 <= n; c[3]++)
        for (c[2] = 0; c[2] <= d[2] && c[8] * 8 + c[7] * 7 + c[6] * 6 + c[5] * 5  + c[4] * 4  + c[3] * 3  + c[2] * 2 <= n; c[2]++)
        {
            c[1] = n - (c[8] * 8 + c[7] * 7 + c[6] * 6 + c[5] * 5  + c[4] * 4  + c[3] * 3  + c[2] * 2);
            if (c[1] >= 0 && c[1] <= d[1]) ans++;
        }
        printf("%d\n", ans);
	}
}