#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
 int main()
 {
	 int t,n,w,i,max,mt;
	 bool flag;
	 ifstream fin("test.in");
	 cin >>t;
	 while (t)
	 {
		 t--;
		 scanf("%d %d",&n,&w);
		 int a[6] ={0},x[6];
		 flag = true;
		 while (n)
		 {
			 n--;
			 int judge = 0,h;
            
		     scanf("%d %d %d %d %d %d",&x[0],&x[1],&x[2],&x[3],&x[4],&x[5]);
             for(i = 0;i < 6 ;i++)
			  {
				  if (x[i] == 3)
				  {
					  judge++;
					  a[i]++;
				  }
				  if (x[i] == 1)
				  {
					  h = i;
				  }
			  }
			 if (judge)
			 {
                a[h] +=3;
			 }
			 
		     if (flag)
			 {
			 max = 0;
		     for (i = 0;i < 6;i++)
		     {
		     	if (max < a[i])
		    	{
		    		max =a[i];
		    		mt = i;
		     	}
	    	 }
	    	 if (max >= w)
	    	 {
	    		 cout << mt+1 << endl;
				 flag = false;
		     }
			 }
		 }
		 if ( max < w)
		 {
			 cout <<"they sucks" << endl;
		 }
	 }
 }