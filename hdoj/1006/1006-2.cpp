#include <cstdio>
#include <iostream>
using namespace std;
double max(double a,double b,double c)
{
if(a >= b && a >= c)
  return a;
else if(a < b && b >= c)
  return b;
return c;
}
double min(double a,double b,double c)
{
if(a <= b && a <= c)
  return a;
else if(a > b && b <= c)
  return b;
return c;
}
int main()
{
double hdans;
double dsm[1444],dsh[1444],dmh[26];
//dsm存放秒针与分针之间的角度，dsh存放秒针与时针之间的角度
//dmh存放分针与时针之间的角度。
double s,m,h;
s=3600.0000/59;
m=43200.0000/719;
h=43200.0000/11;
while(cin >> hdans && hdans !=-1)
{
  int i,j;
  int sp[2],mp[2],hp[2];
  double sum=0;
  double x=0,y=0;
  dsm[0] = (10*hdans)/59;
  dsh[0] = (120*hdans)/719;
  dmh[0] = (120*hdans)/11;
  dsm[1] = s-dsm[0];
  dsh[1] = m-dsh[0];
  dmh[1] = h-dmh[0];
  for(i=2,j=3;;i+=2,j+=2)
  {
    dsm[i] = dsm[i-2]+s;
    dsm[j] = dsm[j-2]+s;
    if(dsm[i]>43200 && dsm[j]>43200)
      break;
  }
  for(i=2,j=3;;i+=2,j+=2)
  {
    dsh[i] = dsh[i-2]+m;
    dsh[j] = dsh[j-2]+m;
    if(i==1436)
      i=1436;
    if(dsh[i]>43200 && dsh[j]>43200)
      break;
  }
  for(i=2,j=3;;i+=2,j+=2)
  {
    dmh[i] = dmh[i-2]+h;
    dmh[j] = dmh[j-2]+h;
    if(dmh[i]>43200 && dmh[j]>43200)
      break;
  }
  //以上代码用来根据hdans初始化dsm，dsh，dmh；
  sp[0]=mp[0]=hp[0]=0;
  sp[1]=mp[1]=hp[1]=1;
  //sp,mp,hp分别为dsm，dsh，dmh的上下界指针。
  while(y<=43200 && x<=43200)
  {
    x=max(dsm[sp[0]],dsh[mp[0]],dmh[hp[0]]);
    y=min(dsm[sp[1]],dsh[mp[1]],dmh[hp[1]]);
    if(x<y)
      sum+=y-x;
    if(y==dsm[sp[1]]){sp[0]+=2;sp[1]+=2;}
    if(y==dsh[mp[1]]){mp[0]+=2;mp[1]+=2;}
    if(y==dmh[hp[1]]){hp[0]+=2;hp[1]+=2;}
  }
  printf("%.5f\n",sum/432);
}
return 0;
}