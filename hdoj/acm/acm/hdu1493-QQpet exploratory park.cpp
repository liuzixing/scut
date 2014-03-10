#include <iostream>
#include <cstdio>
using namespace std;

int t;
double p[7];
double f[61][11];
int main(){
	scanf("%d",&t);
	while (t--){
		for (int i = 1;i < 7;i++)
			scanf("%lf",&p[i]);
		memset(f,0,sizeof f);
		f[0][0] = 1;
		for (int i = 1; i < 61;i++)
			for (int k = 1;k <= 10;k++)
				for (int j = 1;j < 7;j++)
					if (i - j >= 0)
						f[i][k] += f[i - j][k - 1] * p[j];
		for (int i = 1;i < 61;i++)
			for (int k = 1;k <= 10;k++)
				f[i][0] += f[i][k];
		printf("5: %.1lf%%\n",f[5][0] * 100);
		printf("12: %.1lf%%\n",f[12][0] * 100);
		printf("22: %.1lf%%\n",f[22][0] * 100);
		printf("29: %.1lf%%\n",f[29][0] * 100);
		printf("33: %.1lf%%\n",f[33][0] * 100);
		printf("38: %.1lf%%\n",f[38][0] * 100);
		printf("42: %.1lf%%\n",f[42][0] * 100);
		printf("46: %.1lf%%\n",f[46][0] * 100);
		printf("50: %.1lf%%\n",f[50][0] * 100);
		printf("55: %.1lf%%\n",f[55][0] * 100);
		if (t)
			printf("\n");
	}
}