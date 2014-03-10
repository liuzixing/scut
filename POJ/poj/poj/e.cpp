#include<iostream>
using namespace std;
char *A( char *a,char *b )
{ char *p = a;
  while( *p != '\0' ) p++;
  *p = *b;
  do { p++; 
       b++;
       *p = *b; 
} while( *b != '\0' );
  return( a );
}
int main()
{ char a[50], b[50];
  cout << "input a:"; 
cin >> a;
  cout << "input b:";  
cin >> b;
  cout << "a+b=" << A( a,b) << endl;
}