#include <iostream>
using namespace std;
const int maxnum = 10000;
void create (int sum[],int n)
{
	int i = 1,t,j;
	t = 0;
	sum [0] = 0;
	while (i <= maxnum)
	{
		t++;
		for (j = i;j < i + t && j <= maxnum;j++)
		{
			sum [j] = sum[j - 1] + t;
		}
		i = i + t;
	}
}
int main()
{
	int sum[10001],n;
	create(sum,maxnum);
	cin >> n;
	while (n)
	{
		cout << n << " " << sum [n] << endl;
		cin >> n;
	}
}