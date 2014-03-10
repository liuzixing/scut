#include<iostream>
#include <cstdio>
using namespace std;

double cal(double p){
	if (p < 60)
		return 0;
	if (p < 70)
		return 1;
	if (p < 80)
		return 2;
	if (p < 90)
		return 3;
	return 4;
}
int main(){
	int n;
	double ans,s,p,sum;
	while (~scanf("%d",&n)){
		ans = sum = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%lf%lf",&s,&p);
			if (p != -1){
				ans += s * cal(p);
				sum += s;
			}
		}
		if (sum != 0)
			printf("%.2lf\n",ans / sum);
		else 
			printf("-1\n");
	}
}