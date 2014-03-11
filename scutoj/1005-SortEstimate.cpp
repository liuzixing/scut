#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double c,t,l,r;
const double e = 1e-7;
int main(){
	while (~scanf("%lf%lf",&c,&t)){
		l = e;
		r =  100000000;
		c = t / c;
		double m,tem;
		while (r - l > e){
			m = (l + r) / 2;
			tem = m * log(m) /log(2.0);
			if (c >  tem && c - tem <= e){
				
				break;
			}
			if (c > tem)
				l = m;
			else r = m;
		}
		printf("%.4lf\n",m);
	}
}