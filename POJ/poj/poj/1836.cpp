#include <iostream>
#include <stdio.h>
 using namespace std;
 const int N = 1001; 
 int main()
 {
	 int n,left[N],right[N],i,j,max = -1;
	 double a[1001];
	 cin >> n;
	 for (i = 0;i < n;i++)
	 {
		 scanf("%lf",&a[i]);
		 left[i] = 1;
		 for (j = i - 1;j >= 0;j--)
		 {
			 if (a[i] > a[j])
			 {
				 left[i] = (left[j] + 1 > left[i])?left[j] + 1:left[i];
			 }
		 }	
	 }
	  for (i = n - 1;i >= 0;i--)
	 {
		 right[i] = 1;
		 for (j = i + 1;j < n;j++)
		 {
			 if (a[i] > a[j])
			 {
				 right[i] = (right[j] + 1 > right[i])?right[j] + 1:right[i];
			 }
		 }	
	 }

	  for (i = 0; i < n - 1;i++)
	  {
		  for (j = 1;i + j < n;j++)
	         {
		         max = (left[i] + right[i + j] > max)? left[i] + right[i + j] :max;
	         }
	  }
	 printf("%d",n - max);
 }