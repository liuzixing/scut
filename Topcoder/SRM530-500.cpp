#include <cstring>
#include <string.h>
#include <string>
#include <cstdio>
#include <vector>
#include<iostream>
using namespace std;

class GogoXCake{
public:
	string solve(vector <string> cake,vector <string> cutter){
		string y = "YES",n = "NO";
		if (cake.size() < cutter.size() || cake[0].length() < cutter[0].length())
			return "NO";
		for (int i = 0;i <= cake.size() - cutter.size();i++)
			for (int j =  0;j <= cake[0].length() - cutter[0].length();j++)
			{
				bool flag = true;
				for (int k = i;k < i + cutter.size();k++){
					if (!flag) break;
					for (int l = j;l < j + cutter[0].length();l++)
						if (cake[k][l] == 'X' && '.' == cutter[k - i][l - j])
						{
							flag = false;
							break;
						}
				}
				if (flag){
					for (int k = i;k < i + cutter.size();k++)
						for (int l = j;l < j + cutter[0].length();l++)
							if (cake[k][l] == '.' && cutter[k - i][l - j] == '.')
								cake[k][l] = 'X';
				}
			}
			for (int i = 0;i < cake.size();i++)
				for (int j = 0;j < cake[0].length();j++)
					if (cake[i][j]!='X')
						return "NO";
			return "YES";
	}
};
int main(){
	 GogoXCake a;
	 string t;
	 vector <string> b,c;
	 for (int i = 0;i < 3;i++){
		 cin >> t;
		 b.push_back(t);
	 }
	 for (int i = 0; i < 3;i++){
		 cin >> t;
		 c.push_back(t);
	 }
	 cout << a.solve(b,c) << endl;
}