#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
const int N = 16;
const int INF = 0x7fffffff;
struct homework
{
	char name[101];
	int deadline;
	int time;
}a[N];
struct dpnode
{
	int time,score,last,pos;
}dp[1 << N];
int T,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 0;i < n;i++)
			scanf("%s %d %d",&a[i].name,&a[i].deadline,&a[i].time);
		int endState = 1 << n;
		int recent = 0,reduce = 0,past = 0;
		
		for (int s = 1;s < endState;s++)
		{
			dp[s].score = INF;
			for (int i = n - 1;i >= 0;i--)
			{
				recent = 1 << i;
				if (s & recent)
				{
					past = s - recent;
					reduce = dp[past].time + a[i].time - a[i].deadline;
					if (reduce < 0)
						reduce = 0;
					if (reduce + dp[past].score < dp[s].score)
					{
						dp[s].score = reduce + dp[past].score;
						dp[s].pos = i;
						dp[s].last = past;
						dp[s].time = dp[past].time + a[i].time;
					}
				}
			}
		}

		stack<int> path;
		recent = endState - 1;
		while (recent)
		{
			path.push(dp[recent].pos);
			recent = dp[recent].last;
		}
		printf("%d\n",dp[endState - 1].score);
		while (!path.empty())
		{
			int top = path.top();
			printf("%s\n",a[top].name);
			path.pop();
		}
	}
	return 0;
}