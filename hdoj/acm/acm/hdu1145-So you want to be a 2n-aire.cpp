//假设f[i]表示我此时有1元，还有i个问题需要作答时的期望收益。
//
//假设现在概率低于x选择不作答，高于x选择作答，可以列出方程
//
//f[i] = (x-t)/(1-t) + (1-x)/(1-t)*((1+x)*f[i-1])
//
//每次t确定，f[i-1]确定后，f[i]是关于x的一元二次方程，x∈[t,1]，找到方程的最大值赋给f[i]。
//
//整理得f[i] = ax^2 + bx + c
//
//其中a = f[i-1]/(t-1), b = 1/(1-t), c = (f[i-1]-t)/(1-t)
//
//根据抛物线的规律可知f[i]最大值或者在x = t, x = 1两点中的一点上(顶点x坐标不在[t,1]区间上)，或者在x = -b/2a上(顶点坐标在[t,1]区间上)。
//
//


#include <iostream>
#include <cstdio>
using namespace std;

int n;
double t;
double f[35] = {1};

double calc(double a,double b,double c){
	double top = -0.5 * b / a;
	if (top >= t && top <= 1) return c - 0.25*b*b/a;
	return max(a*t*t+b*t+c,a+b+c);
}
int main(){
	while (~scanf("%d %lf",&n,&t)){
		if (n == 0 && t == 0)
			break;
		for (int i = 1;i <= n;i++)
			f[i] = calc(f[i - 1]/(t - 1),1.0/(1-t),(f[i-1]-t)/(1-t));
		printf("%.3lf\n",f[n]);
	}
}