#include <iostream>
#include <stdio.h>
using namespace std;

int ans;
const int N = 100001;
int c[N];
void sortandcount(int a[N],int l,int r)
{
	int tem;
	if (r - l == 0)
	{
		return;
	}
	if (r - l == 1)
	{
		if (a[l] > a[r])
		{
			ans++;
			tem = a[l];
			a[l] = a[r];
			a[r] = tem;
		}
		return;
	}
	int mid = (l + r) / 2;
	int i,j,t;
	sortandcount(a,l,mid);
	sortandcount(a,mid+1,r);
    i = l;j = mid + 1;t = l;
    while (i <= mid && j <= r)
	{
		if (a[i] > a[j])
		{
			c[t] = a[j];
			ans += (mid - i + 1);
			j++;
			t++;
		}
		else
		{
			c[t] = a[i];
			t++;
			i++;
		}
		if (i == mid + 1)
		{
			while (j <= r)
			{
				c[t] = a[j];
				j++;
				t++;
			}
		}
		if (j == r + 1)
		{
			while (i <= mid)
			{
				c[t] = a[i];
				i++;
				t++;
			}
		}
	}
	for (i = l;i <= r;i++)
    {
		 a[i] = c[i];
	}
    return;
}
int main()
{
	int a[N],i,n;
	while (cin >> n)
	{
		for (i = 0; i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		ans = 0;
		sortandcount(a,0,n - 1);
		/*for (i = 0;i < n;i++)
		{
			printf("%d ",a[i]);

		}*/
		cout << ans << endl;
	}
}