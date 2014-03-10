#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class PikachuEasy{
public:
	string check(string word){
		string a[3] = {"pi","ka","chu"};
		for (int i = 0;i < word.size();){
			bool flag = false;
			for (int j = 0;j < 3;j++){
				bool f2 = true;
				for (int k = 0;k < a[j].size();k++){
					if (i + k >= word.size() || word[i + k] != a[j][k])
						f2 = false;
				}
				if (f2){
					flag = true;
					if (j < 2)
						i += 2;
					else
						i += 3;
						break;
				}
			}
			if (!flag)
				return "NO";
		}
		return "YES";
	}
};
