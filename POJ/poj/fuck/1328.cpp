#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <fstream>
using namespace std;
struct coordinate
{
	double x,y;
}g[1001], interval[1001];
int cmp(const void *a, const void *b)
{
	return(*(coordinate *)a).x > (*(coordinate *)b).x ? 1 : -1;
}
int main()
{
	/*ofstream fout ("test.out");
	ifstream fin ("test.in");*/
	int n = -1, i,j = 0, ans;
	double d;
	do 
	{
		cin >> n >> d;
		if (n == 0 && d == 0)
		{
			break;
		}
		j++;
		bool ok = true;
		i = 0;
		while (i < n)
		{
			cin >> g[i].x >> g[i].y;
			if (g[i].y > d)
			{
				ok = false;
			}
			i++;
		}
		if (!ok)
		{
			cout << "Case " << j << ": -1" << endl;
			continue;
		}
		ans = 1;
		for (i = 0;i < n;i++)
		{
			interval[i].y = sqrt(pow(d,2) - pow(g[i].y,2)) + g[i].x;
		    interval[i].x = g[i].x - sqrt(pow(d,2) - pow(g[i].y,2));
		}
		qsort (interval,n,sizeof(interval[0]),cmp);
		for (i = 1;i < n;i++)
		{
			if (interval[0].y  < interval[i].x)
			{
				ans++;
				interval[0].x = interval[i].x;
			    interval[0].y = interval[i].y;
			}
			else
			{
				if (interval[0].x < interval[i].x)
				{
					interval[0].x = interval[i].x;
				}
				if (interval[0].y > interval[i].y)
				{
					interval[0].y = interval[i].y;
				}
			}
            
		}
		cout << "Case " << j << ": " << ans << endl;
	}while(1);
	

}