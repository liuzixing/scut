/*
ID: benbenq1
PROG: calfflac
LANG: C++
*/
#include<fstream> 
#include<cstring>
#include<ctype.h>
#include<stdio.h>
using namespace std;
ifstream fin("calfflac.in");
ofstream fout("calfflac.out");
char a[20010],b[20010];
int n,maxl = 0,start;
void solve()
{
     for(int i = 0;i < n;i++)
	 {
       int j,k,s;
       j = i - 1;
	   k = i + 1;
	   s = 1;
       while(j >= 0 && k < n && b[j] == b[k])
	   {
		   j--;
		   k++;
		   s += 2;
	   }
       if(s > maxl)
	   {
		   maxl = s;
		   start = j + 1;
	   }
       j = i;
	   k = i + 1;
	   s = 0;
       while(j >= 0 && k < n && b[j] == b[k])
	   {
		   j--;
		   k++;
		   s += 2;
	   }
       if(s > maxl)
	   {
		   maxl = s;
		   start = j + 1;
	   }
     }
}
int main(){
    char *p,*q,c;
    p = a;
	q = b;
    while (!fin.eof())
	{
		c = fin.get();
		if(isalpha(c))
		{
			 *q++ = tolower(c);
		}
        *p++ = c;
    }
    *p = '\0';
	*q = '\0';
    n = strlen(b);
	int i;
	p = a;
    solve();
    for(i = 0;*p;p++)
	{
		if(isalpha(*p) && i++ == start)
		{
			break;
		}
	}
    fout << maxl << endl;
    for(i=0;i < maxl && *p;p++)
	{
		fout << *p;
		if(isalpha(*p))
		{
			i++;
		}
	}
	fout << endl;
}