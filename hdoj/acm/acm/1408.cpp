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
				//���һ�β���D�������򻨷ѵ�ʱ��Ҳ��һ��
				//���������(v-d*k)>0.0����AC 
				break;
			} 
		}
		printf("%d\n",i);
	} 
	return 0; 
}
