/*
ID: benbenq1
PROG: heritage
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
char inorder[27],preorder[27];
void solve(int inl,int inr,int prel,int prer)
{
	int root;
	if (inl > inr && prel > prer)
		return;
	for (int i = inl;i <= inr; i++)
		if (inorder[i] == preorder[prel])
		{
			root = i;
			break;
		}
	solve(inl,root - 1,prel + 1,prel + root - inl);
	solve(root + 1,inr,prel + root - inl + 1,prer);
	printf("%c",inorder[root]);
}
int main()
{
	freopen("heritage.in","r",stdin);
	freopen("heritage.out","w",stdout);
	
	scanf("%s%s",inorder,preorder);
	solve(0,strlen(inorder) - 1,0,strlen(preorder) - 1);
	printf("\n");
}