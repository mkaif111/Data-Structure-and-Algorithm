#include <bits/stdc++.h>
using namespace std;

void sol(string s)
{
    string t = "";
    string curr = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (curr.length() > t.length())
                t = curr;
            curr = "";
        }
        else
            curr = curr + s[i];
    }
    cout << t << endl;
}
int main()
{

    string s;
    getline(cin,s);
    sol(s);

    return 0;
    
}