#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
using namespace std;
#define MAX 101
#define BASE 10000
void multiply(int a[],int len,int b)
{
    for(int i=len-1,carry=0;i>=0;--i)
    {
        carry+=b*a[i];
        a[i]=carry%BASE;
        carry/=BASE;
    }
}
void divide(int a[],int len,int b)
{
    for(int i=0,div=0;i<len;++i)
    {
        div=div*BASE+a[i];
        a[i]=div/b;
        div%=b;
    }
}
int main()
{
    int i,j,h[102][MAX];
    memset(h[1],0,MAX*sizeof(int));
    for(i=2,h[1][MAX-1]=1;i<=101;++i)
    {
        memcpy(h[i],h[i-1],MAX*sizeof(int));//h[i]=h[i-1];
        multiply(h[i],MAX,4*i-6);//h[i]*=(4*i-6);
        divide(h[i],MAX,i);//h[i]/=i;
    }
    while(cin>>i)
    {
        for(j=0;j<MAX&&h[i + 1][j]==0;++j);
        for(printf("%d",h[i + 1][j++]);j<MAX;++j)
         printf("%04d",h[i + 1][j]);printf("\n");
    }
    return 0;
}
