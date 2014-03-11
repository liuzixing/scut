#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string.h>
using namespace std;

int x[256];
char a[10],b[10],tem[20];
int flag = 0;
bool check(int k){
	for (int i = 0;i < strlen(tem);i++)
		if (tem[i] != ':' && k <= x[tem[i]])
			return false;
	int ia = 0,ib = 0,ab = 1,bb = 1;
	int j = 0;
	while (x[a[j]] == 0 && j < strlen(a))
		j++;
	for (int i = strlen(a) - 1;i >= j;i--){
		ia += ab * x[a[i]];
		ab *= k;
	}
	if (ia > 23) return false;
	j = 0;
	while (x[b[j]] == 0 && j < strlen(b))
		j++;
	for (int i = strlen(b) - 1;i >= j;i--)
	{
		ib += bb * x[b[i]];
		bb *= k;
	}
	if (ib > 59)
		return false;
	return true;
}
bool check2(){
	int j = 0;
	while (x[a[j]] == 0 && j < strlen(a))
		j++;
	int i = 0;
	while (x[b[i]] == 0 && i < strlen(b))
		i++;
	if (j >= strlen(a) - 1 && i >= strlen(b) - 1 &&  x[a[j]] < 24)
		return true;
	else return false;
}
int main()
{
	for (int i = 0;i < 10;i++)
		x['0' + i] = i;
	for (int i = 10;i < 36;i++)
		x['A' + i - 10] = i;
	scanf("%s",tem);
	int ii;
	for (ii = 0;ii < strlen(tem);ii++){
		if (tem[ii] != ':')
			a[ii] = tem[ii];
		else break;
	}
	for (int i = ii + 1;i < strlen(tem);i++)
		b[i - ii - 1] = tem[i];
	if (check2()) flag = 2;
	for (int i = 2;i < 70 && flag != 2;i++){
		if (check(i)){
			if (flag == 0)
				printf("%d",i);
			else
				printf(" %d",i);
			flag = 1;
		}
	}
	switch(flag){
	case 1:printf("\n");break;
	case 2:printf("-1\n");break;
	case 0:printf("0\n");break;
	}
	return 0;
}