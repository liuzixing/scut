#include<cstdio>
#include<cstring>
const int inf = 0x3fffffff;

int a[10100];
int left[10100];
int right[10100];
void swap(int &a , int &b)
{
	int t = a;
	a = b;
	b = t;
}
int maxsubqueue(int n)
{
	int i;
	left[0] = a[0];
	for(i = 1;i < n;i++)
	{
		if(left[i - 1] + a[i] > a[i]) 
			left[i] = left[i - 1] + a[i];
		else 
			left[i] = a[i];
	}
	for(i = 1;i < n;i++)
	{
		if(left[i] < left[i - 1]) left[i] = left[i - 1];
	}
	right[n - 1] = a[n - 1];
	for(i = n - 2;i >= 0;i--)
	{
		if(right[i + 1] + a[i] > a[i])
			right[i] = right[i + 1] + a[i];
		else
			right[i] = a[i];
	}
	for(i = n - 2;i >= 0;i--)
	{
		if(right[i] < right[i + 1]) right[i] = right[i + 1];
	}
	int maxsum = -inf;
	for(i = 1;i < n;i++)
	{
		if(maxsum < left[i - 1] + right[i])
			maxsum = left[i - 1] + right[i];
	}
	return maxsum;
}

int main()
{
//	freopen("2.txt" , "w" , stdout);
	int t;
	scanf("%d" , &t);
	while(t--)
	{
		int n;scanf("%d" , &n);
		int i;
		int sum = 0;
		int s = 0;
		for(i = 0;i < n;i++)
		{
			scanf("%d" , &a[i]);
			if(a[i] > 0) s++;
			sum += a[i];
		}
		if(s <= 2)
		{
			int max1 = a[0];
			int max2 = a[1];
			if(max1 < max2) swap(max1 , max2);
			for(i = 2;i < n;i++)
			{
				if(a[i] > max2)
				{
					max2 = a[i];
					if(max1 < max2) swap(max1 , max2);
				}
			}
			printf("%d\n" , max1 + max2);
		}
		else
		{
			int ret = maxsubqueue(n);
			for(i = 0;i < n;i++)
			{
				a[i] = -a[i];
			}
			sum += maxsubqueue(n);
			if(sum > ret) printf("%d\n" , sum);
			else printf("%d\n" , ret);
		}
	}
	return 0;
}