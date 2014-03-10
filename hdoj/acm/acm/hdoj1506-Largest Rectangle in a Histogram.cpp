#include <iostream>
#include <cstdio>

using namespace std;
int i,n,t;
const int N = 100005;
__int64 a[N],l[N],r[N],ans;
int main()
{
	while (cin >> n && n)
	{
		for (i = 0;i < n;i++)
		{
			scanf("%I64d",&a[i]);
		}
		l[0] = 0;
		r[n - 1] = n - 1;
		for (i = 1;i < n;i++)
		{
			t = i;
			while (t > 0 && a[i] <= a[t - 1])
				t = l[t - 1];
			l[i] = t;
		}
		for (i = n - 2;i >= 0;i--)
		{
			t = i;
			while (t < n - 1 && a[i] <= a[t + 1])
				t = r[t + 1];
			r[i] = t;
		}
		ans = 0;
		for (i = 0;i < n;i++)
			if ((r[i] - l[i] + 1) * a[i] > ans)
				ans = (r[i] - l[i] + 1) * a[i];
		printf("%I64d\n",ans);

	}

}