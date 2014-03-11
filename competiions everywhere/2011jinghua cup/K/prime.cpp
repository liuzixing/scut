#include<stdio.h>
#include<memory.h>
#include<math.h>
bool flag[20];
short Num[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
short Ring[20];
short n;
inline bool IsPrime(int m)
{
	int i;
	if(m>2 && (!(m%2)))
		return false;
	else if(m == 2)
		return true;
	for(i=3;i<=sqrt(m);i+=2)
		if(!(m%i))
			return false;
	return true;
}
void Out()
{
	int i;
	for(i=1;i< n;i++)
		printf("%d ",Ring[i]);
	//    printf("\n");
	printf("%d\n",Ring[n]);
}
void Search(int index)
{
	int i=2;
	if(index == n)
		for(;i<=n;i++){
			if(!flag[i])
				if(IsPrime(Num[i]+Ring[index-1]) && IsPrime(Num[i]+1)){
					Ring[index] = Num[i];
					Out();
				}
		}
	else
		for(i=2;i<=n;i++){
			if(!flag[i])
				if(IsPrime(Num[i]+Ring[index-1])){
					Ring[index] = Num[i];
					flag[i] = true;
					Search(index+1);
					flag[i] = false;
				}
		}
}
int main()
{
	int i = 1;
	while(scanf("%d",&n) != EOF){
		memset(Ring,0,sizeof(short)*20);
		memset(flag,false,sizeof(bool)*20);
		Ring[1] = 1;
		if(n%2 == 0){
			printf("Case %d:\n",i);
			Search(2);
			i++;
			printf("\n");
		}
		else{
			printf("Case %d:\n\n",i);
			i++;
		}
	}
	return 0;
}
