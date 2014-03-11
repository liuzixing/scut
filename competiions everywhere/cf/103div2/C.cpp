#include <cstdio>
#include <cmath>
#include <string.h>

using namespace std;

char s[100005],p[100005];
int snum[27],pnum[26],ans,ls,lp;
void adda(char a)
{
	if (a == '?')
		snum[26]++;
	else
		snum[a - 'a']++;
}
void suba(char a)
{
	if (a == '?')
		snum[26]--;
	else
		snum[a - 'a']--;
}
int main(){
	while (~scanf("%s",&s)){
		scanf("%s",&p);
		ls = strlen(s);
		lp = strlen(p);
		if (ls < lp){
			printf("0\n");
			continue;
		}
		memset(snum,0,sizeof snum);
		memset(pnum,0,sizeof pnum);
		for (int i = 0;i < lp;i++)
			pnum[p[i] - 'a']++;
		for (int i = 0;i < lp;i++)
			adda(s[i]);
		int gap = 0,i;
		for (i = 0;i < 26;i++)
			if (snum[i] <= pnum[i])
				gap += pnum[i] - snum[i];
			else break;
		if (i == 26 && gap == snum[26])
			ans = 1;
		else
			ans = 0;
		for (i = 1;i <= ls - lp;i++){
			adda(s[i + lp - 1]);
			suba(s[i - 1]);
			int j;
			for (j = gap = 0;j < 26;j++)
				if (snum[j] <= pnum[j])
					gap += pnum[j] - snum[j];
				else break;
			if (j == 26 && gap == snum[26])
				ans++;
		}
		printf("%d\n",ans);
	}
}