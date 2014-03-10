// 1207.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
using namespace std;
int main()
{
 long max=0,cishu=0;
 long minj,maxj,i,number,tep;
 while(cin>>minj>>maxj)
 {
  tep=0;
  max=0;
  if(minj>maxj)
  {
   long temp;
   temp = minj;
   minj = maxj;
   maxj = temp;
   tep = 1;
  }
  for(i = minj;i <= maxj;i++)
  {
   number = i;
   cishu = 1;
   while(number != 1)
   {
    if(number % 2)
     number = 3 * number + 1;
    else
     number = number / 2;
    cishu++;
  
   }
   if(cishu > max)
    max = cishu;
  }
  if(tep == 1)
   cout<< maxj << " " << minj << " ";
  else
   cout<< minj << " " << maxj << " ";

   cout<< max << endl;
 }
 return 0;

}