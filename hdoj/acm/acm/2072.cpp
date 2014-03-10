#include <set>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    set <string> st;
    string s = "";
    char c;

    while ((c = getchar()) != '#')
    {
        s += c;
        while (c != '\n')
        {
            while ((c = getchar()) != ' ' && c != '\n')
			{
                s += c;
			}
            if (s.length()) 
			{
				st.insert(s);
			}
            s = "";
        }
        cout << st.size() << endl;
        st.clear();
    }

}