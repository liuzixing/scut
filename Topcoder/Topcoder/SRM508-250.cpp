#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int n;
class CandyShop
{
public:
	int countProbablePlaces (vector <int> x,vector <int> y,vector <int> r)
	{
		int i,j,k,ans = 0;
		bool flag ;
		for (i = 0;i <= 200;i++)
		{
			for (j = 0;j <= 200;j++)
			{
				flag = 0;
				for (k = 0;k < n && !flag;k++)
				{
					if (abs(i - x[k]) + abs(j - y[k]) <= r[k])
						continue;
					else
						flag = 1;
				}
				if (!flag)
					ans++;
			}
		}
		return ans;
	}
};
int main()
{
	int i;
	cout << "input the number of elements" << endl;
	cin >> n;
	vector <int> x(n + 1),y(n + 1),r(n + 1);
	cout << "input the elements in X" << endl;
	for (i = 0;i < n;i++)
	{
		scanf("%d",&x[i]);
		x[i] += 100;
	}
	cout << "input the elements in Y" << endl;
	for (i = 0;i < n;i++)
	{
		scanf("%d",&y[i]);
		y[i] += 100;
	}
	cout << "input the elements in R" << endl;
	for (i = 0;i < n;i++)
		scanf("%d",&r[i]);
	CandyShop a;
	printf("%d\n",a.countProbablePlaces(x,y,r));
	return 0;
}