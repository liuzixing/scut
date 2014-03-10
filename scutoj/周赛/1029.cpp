#include <iostream> 
#include <algorithm> 
#include <cmath> 
#include <cstdio> 
using namespace std; 
struct node{ 
	int s,e; 
}a[51]; 
int n,t; 
bool cmp(node x, node y) 
{ 
	if (x.s == y.s) 
		return x.e > y.e; 
	return x.s < y.s; 
} 
double sq(double x,double y) 
{ 
	return  sqrt(2.0)*(x - y); 
} 
int main() 
{ 
	double ans; 
	while (cin >> n) 
	{ 
		for (int i = 0;i < n;i++) 
			cin >> a[i].s; 
		for (int j = 0;j < n;j++)
			cin >> a[j].e; 
		sort(a,a + n,cmp);
		ans = sq(a[0].e,a[0].s); 
		int y = a[0].e,x = a[0].s; 
		for (int i = 1;i < n;i++)
		if (y <= a[i].e)
		{ 
			ans += - sq(y,a[i].s) + sq(a[i].e,a[i].s) ; 
			y = a[i].e; 
			x = a[i].s;
		}
		printf("%.4lf\n",ans); 
	} 
	return 0; 
} 