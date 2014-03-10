//����f[i]��ʾ�Ҵ�ʱ��1Ԫ������i��������Ҫ����ʱ���������档
//
//�������ڸ��ʵ���xѡ�����𣬸���xѡ�����𣬿����г�����
//
//f[i] = (x-t)/(1-t) + (1-x)/(1-t)*((1+x)*f[i-1])
//
//ÿ��tȷ����f[i-1]ȷ����f[i]�ǹ���x��һԪ���η��̣�x��[t,1]���ҵ����̵����ֵ����f[i]��
//
//�����f[i] = ax^2 + bx + c
//
//����a = f[i-1]/(t-1), b = 1/(1-t), c = (f[i-1]-t)/(1-t)
//
//���������ߵĹ��ɿ�֪f[i]���ֵ������x = t, x = 1�����е�һ����(����x���겻��[t,1]������)��������x = -b/2a��(����������[t,1]������)��
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