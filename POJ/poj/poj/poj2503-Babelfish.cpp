#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

char t[25];
struct  node{
	char a[11],b[11];
}f[100007];
int n,l,r,mid;
bool cmp(node x,node y){
	return strcmp(x.b,y.b) < 0;
}
int main(){
	while (gets(t)){
		n = 1;
		sscanf(t,"%s%s",f[0].a,f[0].b);
		while (gets(t)){
			if (!strcmp(t,""))
				break;
			sscanf(t,"%s%s",f[n].a,f[n].b);
			n++;
		}
		sort(f,f + n,cmp);
		while (gets(t)){
			l = 0;r = n;
			while (l <= r){
				mid = (l + r) >> 1;
				if (strcmp(t,f[mid].b) <= 0)
					r = mid - 1;
				else l = mid + 1;
			}
			if (!strcmp(f[l].b,t))
				printf("%s\n",f[l].a);
			else printf("eh\n");
		}
	}
}
