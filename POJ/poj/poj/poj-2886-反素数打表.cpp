#include <iostream>
#include <cstdio>
__int64 bestnum,bestsum,n,prime[7] = {2,3,5,7,11,13,17};
void make(__int64 num,__int64 k,__int64 sum,int limit) 
//��ǰö�ٵ�������ö�ٵ��ĵ�K��������ӣ�������Լ�������������Ӹ������ޡ�
{  
	int i;  __int64 temp;  
	if (sum > bestsum)  
	{   
		bestsum=sum;   
		bestnum=num;  
		//���Լ���������࣬�����Ž����Ϊ��ǰ����  
	}  
	if (sum == bestsum && bestnum > num)
		bestnum=num;  //���Լ��������ͬ�������Ž����Ϊ��С������   
	if (k > 6)
		return;  
	temp = num;  
	for(i = 1;i <= limit;i++)//��ʼö��ÿ�������ӵĸ����� 
	{    
		if (temp * prime[k] > n) 
			break;    
		temp = temp * prime[k];  //�۳˵���ǰ����
		make(temp,k + 1,sum * (i + 1),i);
		//������һ��������  
	}
}
__int64 log2(__int64 n)//����ڵ���log2��n������С����
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