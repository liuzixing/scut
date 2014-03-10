#include <iostream>
using namespace std;
int num1[51];
int num2[51];
int main ()
{
    int T;
    while ( cin >> T )
    {
           while ( T -- )
           {
                   memset ( num1, 0 , sizeof ( num1 ) );
                   memset ( num2, 0 , sizeof ( num2 ) );
                   num1[0] = 1;
                   for ( int i = 1; i <= 26; ++ i )
                   {
                         int n ;
                         cin >> n;
                         if ( n == 0 )
                         {
                              continue; 
                         }
                         for ( int j = 0; j <= 50 ; ++ j )
                         {
                               for ( int k = 0; k <= n && k * i + j <= 50;  k ++ ) 
                               {
                                     num2[ k * i + j ] += num1[j]; 
                               }
                         } 
                         for ( int j = 0; j <= 50; ++ j )
                         {
                               num1[j] = num2[j];
                               num2[j] = 0; 
                         }
                   } 
                   int sum = 0; 
                   for ( int i = 1; i <= 50; ++ i )
                   {
                         sum += num1[i]; 
                   }
                   cout << sum << endl;
           } 
    }
    return 0; 
} 

