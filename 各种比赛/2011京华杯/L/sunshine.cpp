#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
#define eps (1e-7)   
#define MAXN 1024
int eq(double a, double b)
{
    return abs(a-b)<=eps;
    }

int le(double a, double b)
{
    return a-b<-eps;
    }

struct Point
{
    double x[2],z;
    };

istream & operator >> (istream &in, Point &p)
{
    //printf("input x[0]:");
    in >> p.x[0] >> p.x[1] >> p.z;
    return in;
    }  

struct Segment
{
    Point s,e;
    };
    
struct Cone
{
    Point c;
    double h,r;
    };
    
istream & operator >> (istream &in, Cone &cone)
{
    in >> cone.h >> cone.r >> cone.c.x[0] >> cone.c.x[1];
    return in;
    }

//sg.s: sun
//sg.e: cbd
//t from 0 -> cone.h
int through( Segment sg, Cone cone )
{
    if(le(cone.h,sg.e.z)) return 0;
    
    //move down until CBD is on the ground
    double rpi = (cone.h - sg.e.z)*cone.r/cone.h;
    cone.h -= sg.e.z;
    cone.r = rpi;
    sg.s.z -= sg.e.z;
    sg.e.z = 0;
	//cout << cone.c.x[0] << " " << cone.c.x[1] << " " << "h:" << cone.h << "r:" << cone.r << endl; 
    
    //calculate the X'(Y')
    for( int i = 0 ; i < 2 ; i++ )
    {
        if( eq( sg.s.x[i], sg.e.x[i] ) ) continue;
        double tmp;
        tmp = (sg.s.z - cone.h)*(sg.e.x[i]-sg.s.x[i])/sg.s.z + sg.s.x[i];
        sg.s.x[i] = tmp;            
        }
    sg.s.z = cone.h;
	//cout << "z:" << sg.s.z << "x:" << sg.s.x[0] << "y:" << sg.s.x[1] << endl;
    
    //t2(C12+C22-R2/Z2) + 2(X0C1-C1Xc+Y0C2-C2Yc)t + (X02-2X0Xc+Xc2+ Y02-2Y0Yc+Yc2) < 0
    double c[2];
    double Z = cone.h;
    double R = cone.r;
    double X0,XC, Y0, YC, C1, C2;
    for( int i = 0 ; i < 2 ; i++ )
    {
        c[i] = (sg.e.x[i]-sg.s.x[i])/Z;
        }
    X0 = sg.s.x[0], Y0 = sg.s.x[1], XC = cone.c.x[0], YC = cone.c.x[1];
    C1 = c[0], C2 = c[1];
    double a,b,d; //ax^2 + bx + d
    a = c[0]*c[0] + c[1]*c[1] - R*R / (Z*Z);
    b = X0*C1-C1*XC + Y0*C2-C2*YC;
    b *= 2;
    d = X0*X0 - 2*X0*XC + XC*XC + Y0*Y0 - 2*Y0*YC + YC*YC;
    
    double delta = b*b - 4*a*d;
    //cout << "delta:" << delta << endl;
    //cout << "a:" << a << endl;
    //cout << "b:" << b << endl;
    //cout << "c:" << d << endl;
    double xLarger;
    if(le(a,0.0))
    {
        
        if(le(delta,0.0) || eq(delta,0.0)) return 1;
        xLarger = (-b - sqrt(delta))/(2*a);
        if( le(0.0,xLarger) && (le(xLarger,Z) || eq(xLarger,Z)) ) return 2;
        }
    else if(eq(a,0.0))
    {
        return 3;
        }
    else
    {
        if(le(0.0,delta)) 
        {
            xLarger = (-b + sqrt(delta))/(2*a);
            if( le(0.0,xLarger) && (le(xLarger,Z) || eq(xLarger,Z)) ) return 4;
        }    
        }    
   return 0;
} 
        
int N;
Point sun, cbd;
Cone c;

int main()
{
    while( cin >> sun )
    {
        cin >> cbd;
        cin >> N;
        int flag = 0;
        Segment tmp;
        tmp.s = sun;
        tmp.e = cbd;
        for( int i = 0 ; i < N ; i++ )
        {
            cin >> c;
            flag += through( tmp, c );
            }
        if( flag ) cout << 0 << endl;
        else cout << 1 << endl;
        }
    //while(1);

    
    return 0;
    }
