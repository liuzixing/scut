/*
ID: benbenq1
PROG: lgame
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

int charnum[26] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
int nums[26];
int temp[26],temp2[26];
struct STR
{
	char s[10];
	int len;
	int score;
}str[40000];
char s[10];
int ans[40000][2];
int n,len,t,maxs,m,maxg,sum,sum2;
int main()
{
	FILE *fin = fopen("lgame.in","r");
	FILE *fout = fopen("lgame.out","w");
	FILE *dict = fopen("lgame.dict","r");
	int i,j,k;
	memset(ans,-1,sizeof(ans));
	fscanf(fin,"%s",s);
	len = strlen(s);
	for (i = 0;i < strlen(s);i++)
	{
		nums[s[i] - 'a']++;
		maxg += charnum[s[i] - 'a'];
	}
	i = 0;

	while (fscanf(dict,"%s",&str[i].s) != EOF)
	{
		if (str[i].s[0] == '.') break;
		memset(temp,0,sizeof(temp));
		str[i].len = strlen(str[i].s);
		if (str[i].len > len)
			continue;
		for (j = 0;j < str[i].len;j++)
			if (nums[str[i].s[j] - 'a'] == 0)
			{
				i--;
				break;
			}
			else
			{
				temp[str[i].s[j] - 'a']++;
				if (temp[str[i].s[j] - 'a'] > nums[str[i].s[j] - 'a'])
				{
					i--;
					break;
				}
			}
		i++;
	}
	
	fclose(dict);
	fclose(fin);
	n = i;

	for (i = 0;i < n;i++)
	{
		memcpy(temp,nums,sizeof(nums));
		sum = 0;
		for (j = 0;j < str[i].len;j++)
		{
			sum += charnum[str[i].s[j] - 'a'];
			temp[str[i].s[j] - 'a']--;
		}
		if (sum > maxs)
		{
			maxs = sum;
			m = 0;
			ans[0][0] = i;
		}
		else if (sum == maxs)
		{
			ans[++m][0] = i;
			ans[m][1] = -1;
		}
		if (sum == maxg) continue;
		for (j = i + 1;j < n;j++)
		{
			memcpy(temp2,temp,sizeof(temp));  
			sum2 = sum;
			if (str[i].len + str[j].len > strlen(s)) continue;
			for (k = 0;k < str[j].len;k++)
			{
				sum2 += charnum[str[j].s[k] - 'a'];
				temp2[str[j].s[k] - 'a']--;
			}
			t = 1;

			for (k = 0;k < 26;k++)
				if (temp2[k] < 0)
				{
					t = 0;
					break;
				}
			if (t == 0) continue;
			if (sum2 > maxs)
			{
				maxs = sum2;
				m = 0;
				ans[m][0] = i;
				ans[m][1] = j;
			}
			else if (sum2 == maxs)
			{
				ans[++m][0] = i;
				ans[m][1] = j;
			}
		}
	}
	
	fprintf(fout,"%d\n",maxs);
	for(i = 0;i <= m;i++)   
		if(ans[i][1] == -1)
			fprintf(fout,"%s\n",str[ans[i][0]].s);
		else 
			fprintf(fout,"%s %s\n",str[ans[i][0]].s,str[ans[i][1]].s);
	fclose(fout);
	return 0;
}

