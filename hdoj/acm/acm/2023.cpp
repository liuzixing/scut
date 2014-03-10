#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,t;
	double studentaverage[50],lessonaverage[5];
	int a[50][5];
	double n,m;
	while (cin >> n >> m)
	{
		memset(studentaverage,0,sizeof(studentaverage));
		memset(lessonaverage,0,sizeof(lessonaverage));
		for (i = 0;i < n;i++)
		{
			for (j = 0;j < m;j++)
			{
				scanf("%d",&a[i][j]);
				studentaverage[i] += a[i][j];
				lessonaverage[j] += a[i][j];
			}
		}
		t = 0;
		//学生平均成绩。
		for (i = 0;i < n - 1;i++)
		{
			studentaverage[i] /= m;
			printf("%.2lf ",studentaverage[i]);
		}
		studentaverage[i] /= m;
		printf("%.2lf\n",studentaverage[i]);
	    //学科平均成绩
		for (j = 0;j < m - 1;j++)
		{
			lessonaverage[j] /= n;
			printf("%.2lf ",lessonaverage[j]);
		}
		lessonaverage[j] /= n;
		printf("%.2lf\n",lessonaverage[j]);
		//计算优生人数
		for (i = 0;i < n;i++)
		{
			bool flag = true;
			for (j = 0;j < m;j++)
			{
				if (lessonaverage[j] > a[i][j])
				{
					flag = false;
	                break;
				}
			}
			if (flag)
			{
				t++;
			}
		}
		printf("%d\n\n",t);
	}
}