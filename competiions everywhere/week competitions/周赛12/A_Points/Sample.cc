//  PR, meant to be immediate

#include <iostream>
#include <assert.h>
#include <stdlib.h>

using namespace std;

#define MAXN 200000

int x[MAXN], y[MAXN];

int main () {
  int n;
  while (1) {
    cin >> n;
    if (!n) break;
    assert(0 < n && n%2 && n <= MAXN);
    int nn = (n-1)/2;
    int xb, yb;
    for(int i=0;i<n;i++) {
      cin >> x[i] >> y[i];
      if (i == nn) {
	xb = x[i]; yb = y[i];
      }
    }
    int ss = 0, os = 0;
    for (int i = 0; i<n; i++) {
      if (x[i] < xb && y[i] < yb || x[i] > xb && y[i] > yb) ss++;
      if (x[i] < xb && y[i] > yb || x[i] > xb && y[i] < yb) os++;
    }
    cout << ss << " " << os << "\n";
  }
  return 0;
}
