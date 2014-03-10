#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;


struct node{
	int s,t,p,g;
	string name;
}f[100001];
int n,tt = -1,pp = -1,gg = -1;
string tem;
int check(string x){
	if ((x[0] == x[1])&&(x[1] == x[3])&& (x[3] == x[4])&& (x[4] == x[6])&&(x[6] == x[7]))
		return 0;
	if ((x[0] > x[1])&& (x[1] > x[3])&&(x[3] > x[4])&&(x[4] > x[6])&&(x[6] > x[7]))
		return 1;
	return 2;
}

int main(){
	cin >> n;
	for (int i = 0;i < n;i++){
		cin >> f[i].s >> f[i].name;
		for (int j = 0;j < f[i].s;j++){
			cin >> tem;
			switch(check(tem)){
				case 0:f[i].t++;break;
				case 1:f[i].p++;break;
				case 2:f[i].g++;break;
			}
		}
		tt = max(tt,f[i].t);
		pp = max(pp,f[i].p);
		gg = max(gg,f[i].g);
	}
	
	cout << "If you want to call a taxi, you should call: ";
	int j = 0;
	for (int i = 0;i < n;i++)
		if (tt == f[i].t)
			if (j)
				cout << ", " << f[i].name;
			else{
				cout << f[i].name;
				j = 1;
			}
	cout << "." << endl;
	cout << "If you want to order a pizza, you should call: ";
	j = 0;
	for (int i = 0;i < n;i++)
		if (pp == f[i].p)
			if (j)
				cout << ", " << f[i].name;
			else{
				cout << f[i].name;
				j = 1;
			}
	cout << "." << endl;
	cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
	j = 0;
	for (int i = 0;i < n;i++)
		if (gg == f[i].g)
			if (j)
				cout << ", " << f[i].name;
			else{
				cout << f[i].name;
				j = 1;
			}
	cout << "." << endl;
}