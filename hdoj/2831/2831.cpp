#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int N = 1001;
struct node
{
	int num,rest;
} a[N];

bool cmp(node x,node y)
{
	return x.rest < y.rest;
}
int main()
{
	int n,t,d,v,i;
	while (scanf("%d%d",&n,&t) != EOF)
	{
         for (i = 0; i < n;i++)
		 {
			 scanf ("%d%d",&v,&d);
			 a[i].num = i + 1;
			 a[i].rest = v - d;
		 }
		 sort(a,a + n,cmp);

		 bool flag = false;
		 if (t != 0)
		 {
			 for (i = 0;i < n;i++)
		     {
			     if (a[i].rest <= 0 || a[i].rest / t < i + 1)
			     {
				     flag = true;
				     break;
			     }
		     } 
		 }
		 else
		 {
			 for (i = 0;i < n;i++)
		     {
			     if (a[i].rest < 0)
			     {
				     flag = true;
				     break;
			     }
		     } 
		 }
		 if (flag)
		 {
			 cout << "The zombies eat your brains!" << endl;
		 }
		 else
		 {
			 for (i = 0;i < n - 1;i++)
		     {
				 cout << a[i].num << " ";
			 }
			  cout << a[n - 1].num << endl;
		 }
	}
	
}