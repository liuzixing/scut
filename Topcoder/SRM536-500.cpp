#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

class RollingDiceDivTwo{
public:
	int minimumFaces(vector <string> rolls){
		int ans = 0,m;
		for (int i = 0;i < rolls.size();i++)
			for (int j = 0;j < rolls[i].length() - 1;j++)
				for (int k = j + 1;k < rolls[i].length();k++)
					if (rolls[i][j] > rolls[i][k])
						swap(rolls[i][j] , rolls[i][k]);
		for (int i = 0;i < rolls[0].length();i++){
			m = '0';
			for (int j = 0;j < rolls.size();j++)
				if (m < rolls[j][i])
					m = rolls[j][i];
			ans += m;
		}
		return ans;
	}
};