#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <string.h>
#include <stack>

using namespace std;

bool a[256][256];
string s;
char ss[2];
int i,j,k,l,ans;
int main(){
	cin >> s;
	cin >> l;
	for (i = 0;i < l;i++){
		scanf("%s",ss);
		a[ss[0]][ss[1]] = a[ss[1]][ss[0]] = 1;
	}
	if (s.size() < 3){
		if (s.size() > 1 && a[s[0]][s[1]] == 1)
			printf("1\n");
		else 
			printf("0\n");
		return 0;
	}
	i = 0;j = 1;
	while (i < s.size() - 1 && j < s.size()){
		if (a[s[i]][s[j]]){
			ans++;
			if (j  < s.size() - 1 && a[s[i]][s[j + 1]])
				i = j;
			j++;
			continue;
		}
		i = j;
		j++;
	}
	printf("%d\n",ans);
}