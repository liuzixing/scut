#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int NMAX=10000;

int Cal(int ans[NMAX],int multip)
{
    int i,temp;
    for(i = 1;i <= ans[0];i++)
    {
        ans[i] *= multip;
    }
    for(i = 1;i <= ans[0];i++)
    {
        temp = ans[i];
        if(temp > 9999)
        {
            ans[i] =temp % 10000;
            if(i + 1 > ans[0])
            {   
				ans[0] = i + 1;
				ans[i + 1] = 0;
			}
            ans[i + 1] += temp / 10000;
        }
    }
    return 0;
}

int main()
{
    int n,i;
    int ans[NMAX]={0};
    while(cin >> n && (n >= 0 && n <= NMAX))
    {
        if(n==0)
        {    
			cout<< 1 <<endl;
			continue;
		}
        ans[0] = 1;
		ans[1] = 1;
        for(i  = 2;i <= n;i++)
        {
            Cal(ans,i);
        }
        for(i = ans[0];i >= 1;i--)
        {
            if(i == ans[0])
            {
                cout << ans[ans[0]];
            }
            else
            {
                if(ans[i] >= 1000)
                {   cout << ans[i];}
                else
                {
                    if(ans[i] >= 100)
                    {   cout << "0" << ans[i];}
                    else
                    {
                        if(ans[i] >= 10)
                        {   cout << "00" << ans[i];}
                        else
                        {   cout << "000" << ans[i];}
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}