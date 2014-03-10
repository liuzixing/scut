#include<iostream>
#include<cstdio>
#include<string.h>
#include<string>
using namespace std;
int main()
{
    int n,i,j;
    char s[10000];
    while(cin>>s)
    {
        i=0;
        for(j=0;j<strlen(s);j++)
        {
            if(i%2!= s[j]-'0')
                i++;
        }
        printf("%d\n",i);
    }
    return 0;
}
