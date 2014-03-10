#ifndef _THELAS
#define _THELAS

#include "getpoint.h"

//先在所有的位置上填满3个数，之后调用这个函数补齐数字，并优化

void thefirstupdate(node b[n][n], int x1,int x2,int y1,int y2){

	for (int i = x1;i <= x2;i++)
		for (int j = y1;j <= y2;j++){
			int next = 0,now;
			int p = num[i][j];
			node &tem1 = b[i][j];
			for (int k = tem1.length;k < p;k++){
				now = -10000;
				int lastdig;
				for (int t = 1;t <= 30;t++){
					tem1.a[k] = t;
					next = getpoint(b,i,j,k);
					if ( next < now)
						tem1.a[k] = lastdig;
					else{
						now = next;
						lastdig = t;
					}
				}
			}
		}
}

void thelastupdate(node b[n][n], int x1,int x2,int y1,int y2){

	for (int i = x1;i <= x2;i++)
		for (int j = y1;j <= y2;j++){
			int next = 0,now;
			int p = num[i][j];
			node &tem1 = b[i][j];
			for (int k = 0;k < p;k++){
				now = -10000;
				int lastdig;
				for (int t = 1;t <= 30;t++){
					tem1.a[k] = t;
					next = getpoint(b,i,j,k);
					if ( next < now)
						tem1.a[k] = lastdig;
					else{
						now = next;
						lastdig = t;
					}
				}
			}
		}
}
int updateof2point(node b[n][n],int x1,int y1,int n1,int x2,int y2,int n2)
{
	int maxvalue = getpoint(b,x1,y1,n1);
	maxvalue += getpoint(b,x2,y2,n2);

	int orvalue = maxvalue;
	int p1 = b[x1][y1].a[n1],p2 = b[x2][y2].a[n2];
	node& tem1 = b[x1][y1];
	node& tem2 = b[x2][y2];
	for(int num1 = 1 ; num1 <= 30 ; num1 ++)
	{
		tem1.a[n1] = num1;
		for(int num2 = 1; num2 <= 30 ; num2++)
		{
			tem2.a[n2] = num2;
			int tempvalue = getpoint(b,x1,y1,n1);
			tempvalue += getpoint(b,x2,y2,n2);

			if(tempvalue > maxvalue)
			{
				maxvalue = tempvalue;
				p1 = num1;
				p2 = num2;
			}
		}
	}

	tem1.a[n1] = p1; tem2.a[n2] = p2;
	return (maxvalue - orvalue);
}
#endif
