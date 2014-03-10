#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int N,C;
int trans[21][21],dp[10001];
void onezero_pack(int v,int c,int n){
    for (int i = 1;n > 0;i++){
        if (i > n) i = n;
        n-=i;
        int vv = v * i,cc = c * i;
        for (int j = C;j >= cc;j--)
            if (dp[j] < dp[j - cc] + vv)
                dp[j] = dp[j - cc] + vv;
    }
}
int main(){
    int vv,cc;
    char s[12];
    while (~scanf("%d %d",&N,&C)){
        memset(trans,0,sizeof trans);
        for (int i = 0;i < N;i++){
            scanf("%s %d %d",s,&vv,&cc);
            trans[vv][cc]++;
        }
        memset(dp,0,sizeof dp);
        for (int i = 1;i < 11;i++)
            for (int j = 1;j < 11;j++)
                if (trans[i][j])
                    onezero_pack(i,j,trans[i][j]);
        printf("%d\n",dp[C]);
    }
}
