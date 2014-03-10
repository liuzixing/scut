#include<iostream>
using namespace std;
int main()
{
	int sum,n,x,count;
	cin>>x;
	sum=0;
	count=0;
	for(n=0;sum<=x;n++)
	{
	    sum+=n;
		if((x-sum)%(n+1)==0&&(x-sum)/(n+1)!=0)
		{
		    count++;
		}
	}
	cout<<count;
}