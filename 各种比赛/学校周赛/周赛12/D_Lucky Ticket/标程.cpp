#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[3];
int main()
{
	int n;
	while(scanf("%d" , &n) != EOF)
	{
		int i , x;
		memset(a , 0 , sizeof(a));
		for(i = 0;i < n;i++)
		{
			scanf("%d" , &x);
			a[x % 3]++;
		}
		printf("%d\n" , a[0] / 2 + min(a[1] , a[2]));
	}
	return 0;
}