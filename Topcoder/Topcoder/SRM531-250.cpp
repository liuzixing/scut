#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class UnsortedSequence{
public: 
	vector <int> getUnsorted(vector <int> s){
		sort(s.begin(),s.end());
		if (s.size() == 1){
			s.clear();
			return s;
		}
		int i;
		for (i = s.size() - 2;i >= 0;i--)
			if (s[i] != s[i + 1]){
				swap(s[i],s[i + 1]);
				break;
			}
		if (i < 0)
			s.clear();
		return s;
	}
}a;
int main(){
	
}
