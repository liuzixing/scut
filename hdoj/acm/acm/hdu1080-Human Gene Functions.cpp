#include <iostream>
#include <cstdio>
using namespace std;

//1、i , j 匹配，结果是a[i-1][j-1]+c(i,j)
//2、i, - 匹配 ，i-1之前的和j之前的匹配，结果是a[i-1][j]+c(i,-)
//3、-, j 匹配，j-1及其前面的字符和i及其前面的匹配，结果a[i][j-1]+c(-,j)
const int c[5][5]={
	5,-1,-2,-1,-3,
	-1,5,-3,-2,-4,
	-2,-3,5,-2,-2,
	-1,-2,-2,5,-1,
	-3,-4,-2,-1,-10000
};
int f[201][201],t,l2,l1,i,j,tem;
char s1[201],s2[201];

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> l1 >> (s1 + 1) >> l2 >> (s2 + 1);
		for (i = 1;i <= l1;i++)
			switch(s1[i])
			{
			case 'A': s1[i]=0;break;
			case 'C': s1[i]=1;break;
			case 'G': s1[i]=2;break;
			case 'T': s1[i]=3;break;
			}
		for (i = 1;i <= l2;i++)
			switch(s2[i])
			{
			case 'A': s2[i]=0;break;
			case 'C': s2[i]=1;break;
			case 'G': s2[i]=2;break;
			case 'T': s2[i]=3;break;
			}

		f[0][0] = 0;
		for (i = 1;i <= l1;i++)
			f[i][0] = f[i - 1][0] + c[s1[i]][4];
		for (i = 1;i <= l2;i++)
			f[0][i] = f[0][i - 1] + c[4][s2[i]];
		for (i = 1;i <= l1;i++)
			for (j = 1;j <= l2;j++)
			{
				tem = f[i - 1][j - 1] + c[s1[i]][s2[j]];
				tem = max(tem,f[i - 1][j] + c[s1[i]][4]);
				tem = max(tem,f[i][j - 1] + c[4][s2[j]]);
				f[i][j] = tem;
			}
		printf("%d\n",f[l1][l2]);
	
	}
}