#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const char pdwhite[5] = {'K','Q','R','B','N'};
const char pdblack[5] = {'k','q','r','b','n'};
struct condition
{
	bool worb;
	char what;
	
} g[8][8];
 char egde[50];
 int i, j, nblackp = 0,nwhitep = 0, k;
 ifstream fin ("test.in");
void init ()
{
	int i, j; 
	char c,c1,c2,c3;
	 for (i = 0; i < 8;i++)
 {
	 cin >> c;
	 for(j = 0;j < 8;j++)
	 {
		 cin >> c1 >> c2 >> c3;
		 g[i][j].what = c2;
		 if (c2 <= 'Z' && c2 >= 'A' )
		 {
			 g[i][j].worb = true;
			 if (c2 == 'P')
			 {
				 nwhitep++;
			 }
		 }
		 else
		 {
			 g[i][j].worb = false;
			 if (c2 == 'p')
			 {
				 nblackp++;
			 }
		 }
		cin >> c;
	 }
	 cin >> egde;
 }
}
int main()
{
 cin >> egde;
 init();
 cout << "White: ";
 for (k = 0; k < 5;k++)
 {
	 for (j = 0; j < 8;j++)
	 {
		 for (i = 0; i < 8; i++)
		 {
			 if (g[i][j].what == pdwhite[k] && g[i][j].worb)
			 {
				 cout << pdwhite[k] << char('a'+j) << 8 - i << ",";
			 }
		 }
	 }
 }
 k = 0;
	 for (i = 7; i >= 0; i--)
	 {
		 for (j = 0; j < 8;j++)
		 {
			 if (g[i][j].what == 'P' && g[i][j].worb)
			 {
				 k++;
				 if (k == nwhitep)
				 {
					 cout <<char('a'+j) << 8 - i << endl;
				 }
				 else
				 {
					 cout <<char('a'+j) << 8 - i <<",";
				 }
			 }
		 }
	 }

  cout << "Black: ";
 for (k = 0; k < 5;k++)
 {
	 for (i = 0; i < 8;i++)
	 {
		 for (j = 0; j < 8 ;j++)
		 {
			 if (g[i][j].what == pdblack[k] && !g[i][j].worb)
			 {
				 cout << pdwhite[k] << char('a'+j) << 8 - i << ",";
			 }
		 }
	 }
 }
 k = 0;
	 for (j = 0; j < 8;j++)
	 {
		 for (i = 0; i < 8; i++)
		 {
			 if (g[i][j].what== 'p' && !g[i][j].worb)
			 {
				 k++;
				 if (k == nblackp)
				 {
					 cout <<char('a'+j) << 8 - i <<endl;
				 }
				 else
				 {
					 cout << char('a'+j) << 8 - i << ",";
				 }
			 }
		 }
	 }
}