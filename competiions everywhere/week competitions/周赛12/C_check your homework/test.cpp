#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 10000 + 10;

int v[N];
int preSum[N], sfxSum[N];
int minPreSum[N], minSfxSum[N];
int lSum[N], rSum[N];
int maxLSum[N], maxRSum[N];

void calcLeftMin(int v[], int n, int minVal[])
{
	minVal[0] = 0;
	for (int i = 1; i <= n; i++)
		minVal[i] = min(minVal[i-1], v[i]);
}
void calcLeftMax(int v[], int n, int maxVal[])
{
	maxVal[0] = 0;
	maxVal[1] = v[1];
	for (int i = 2; i <= n; i++)
		maxVal[i] = max(maxVal[i-1], v[i]);
}
void calcRightMin(int v[], int n, int minVal[])
{
	minVal[n+1] = 0;
	for (int i = n; i >= 1; i--)
		minVal[i] = min(minVal[i+1], v[i]);
}
void calcRightMax(int v[], int n, int maxVal[])
{
	maxVal[n+1] = 0;
	maxVal[n] = v[n];
	for (int i = n-1; i >= 1; i--)
		maxVal[i] = max(maxVal[i+1], v[i]);
}
int Solve(int v[], int n)
{
	preSum[0] = 0;
	for (int i = 1; i <= n; i++)
		preSum[i] = preSum[i-1] + v[i];
	calcLeftMin(preSum, n, minPreSum);

	sfxSum[n+1] = 0;
	for (int i = n; i >= 1; i--)
		sfxSum[i] = sfxSum[i+1] + v[i];
	calcRightMin(sfxSum, n, minSfxSum);

	for (int i = 1; i <= n; i++)
		lSum[i] = preSum[i] - minPreSum[i-1];
	calcLeftMax(lSum, n, maxLSum);

	for (int i = n; i >= 1; i--)
		rSum[i] = sfxSum[i] - minSfxSum[i+1];
	calcRightMax(rSum, n, maxRSum);

	int ret = -999999999;
	for (int i = 1; i <= n-1; i++)
		ret = max(ret, maxLSum[i]+maxRSum[i+1]);
	return ret;
}
bool HasTwoNonNegtive(int v[], int n)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (v[i] >= 0)
			cnt++;
	return cnt >= 2;
}
int main()
{
	freopen("test.in", "r", stdin);

	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &v[i]);

		int ret = Solve(v, n);

		if (HasTwoNonNegtive(v, n))
		{
			int sum = preSum[n];
			for (int i = 1; i <= n; i++)
				v[i] = -v[i];
			int tmp = sum + Solve(v, n);
			ret = max(ret, tmp);
		}

		printf("%d\n", ret);
	}
}	