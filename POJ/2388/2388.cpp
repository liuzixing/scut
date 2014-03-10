#include <iostream>
#include <algorithm>
using namespace std;
int cmp (const void *a,const void *b)
{
	return *(int *)a - * (int *) b;
}
int main()
{
	int n,i;
	int a[10001];
	cin >> n;
	for (i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	qsort(a,n,sizeof(a[0]),cmp);
	cout << a[n / 2] << endl;
}