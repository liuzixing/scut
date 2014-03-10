#include <stdio.h>
#define eps 1e-8 
int main() 
{ 
	double v,d; 
	int i,j;
	while(scanf("%lf %lf",&v,&d)!=EOF) 
	{ 
		for(i=0,j=1;;i+=j+1,j++) 
		{ 
			if(v > d * j) 
			{ 
				v = v - d * j;
			}
			else 
			{
				int k = (int)(v / d);
				i += k; 
				if((v - d * k) > eps)
				{
					i++;
				}
				//最后一滴不到D毫升，则花费的时间也算一秒
				//上面如果是(v-d*k)>0.0不能AC 
				break;
			} 
		}
		printf("%d\n",i);
	} 
	return 0; 
}
