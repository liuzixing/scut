#include <iostream>
#include <cstdio>
__int64 bestnum,bestsum,n,prime[7] = {2,3,5,7,11,13,17};
void make(__int64 num,__int64 k,__int64 sum,int limit) 
//当前枚举到的数；枚举到的第K大的质因子；该数的约数个数；质因子个数上限。
{  
	int i;  __int64 temp;  
	if (sum > bestsum)  
	{   
		bestsum=sum;   
		bestnum=num;  
		//如果约数个数更多，将最优解更新为当前数。  
	}  
	if (sum == bestsum && bestnum > num)
		bestnum=num;  //如果约数个数相同，将最优解更新为较小的数。   
	if (k > 6)
		return;  
	temp = num;  
	for(i = 1;i <= limit;i++)//开始枚举每个质因子的个数。 
	{    
		if (temp * prime[k] > n) 
			break;    
		temp = temp * prime[k];  //累乘到当前数。
		make(temp,k + 1,sum * (i + 1),i);
		//继续下一步搜索。  
	}
}
__int64 log2(__int64 n)//求大于等于log2（n）的最小整数
{ 
	__int64 i = 0;
	__int64 p = 1; 
	while(p < n) 
	{  
		p *= 2;  i++;
	} 
	return i;
}
int main()
{ 
	FILE * cfPtr = fopen("out.txt","w"); 
	n = 500000; 
	int i = 0; 
	while(n > 0) 
	{  
		bestnum = 1;  
		bestsum = 1; 
		make(1,0,1,log2(n));
		fprintf(cfPtr,"%d,",bestnum);
		fprintf(cfPtr,"%d,",bestsum); 
		n = bestnum - 1;  
		i++; 
	}
	fclose(cfPtr); 
	printf("%d\n",i); 
}