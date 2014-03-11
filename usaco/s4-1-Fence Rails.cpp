/*
ID: benbenq1
PROG: fence8
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

int board[51],sumboard,rail[1111],restboard[51],totalrest,n,m;
int minrail[1111],l,r,mid;

bool cmp(int a,int b)
{
	return a < b;
}

//step 是能切的木条的数目，pos对应board的位置
bool dfsid(int step,int pos)
{
	//什么都不切肯定能成功
	if (step < 1) 
		return 1;
	//对于切剩下的board（无法再切下rail），如果这个值大于board长度的总和减去rail长度的总和，一定无解
	if (totalrest > sumboard - minrail[mid])
		return 0;
	if (step > mid)
		return 0;
	int i;
	for (i = n;i >= pos;i--)
	{
		if(restboard[i] >= rail[step])
		{
			restboard[i] -= rail[step];
			if(restboard[i] < rail[1])
				totalrest += restboard[i];
			//若有rail[i]=rail[i - 1]，则rail[i]对应的board一定大于等于rail[i - 1]对应的board
			if (rail[step] == rail[step - 1])
			{
				if(dfsid(step - 1,i))
					return 1;
			}
			else if(dfsid(step - 1, 1))
				return 1;
			if (restboard[i] < rail[1])
				totalrest -= restboard[i];
			restboard[i] += rail[step];
		}
	}
	return 0;
}
int main()
{
	freopen("fence8.in","r",stdin);
	freopen("fence8.out","w",stdout);
	int i;
	scanf("%d",&n);
	for (i = 1;i <= n;i++)
	{
		scanf("%d",&board[i]);
		sumboard += board[i];
	}
	scanf("%d",&m);
	for (i = 1;i <= m;i++)
	{
		scanf("%d",&rail[i]);
	}
	//一定要先大后小！！！
	sort(board + 1,board + n + 1,cmp);
	//切小的要比切大的来的划算
	sort(rail + 1,rail + m + 1,cmp);
	for (i = 1;i <= m;i++)
	{
		minrail[i] = minrail[i - 1] + rail[i];
	}
	while (sumboard < minrail[m])
		m--;
	//二分答案 
	r = m;mid = (l + r) / 2;
	while(l <= r)
	{
		totalrest = 0;
		for (i = 1;i <= n;i++)
			restboard[i] = board[i];
		if(dfsid(mid,1))
			l = mid + 1;
		else
			r = mid - 1;
		mid = (l + r) / 2;
	}
	printf("%d\n",mid);
}
