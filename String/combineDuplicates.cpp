#include <bits/stdc++.h>
using namespace std;

void sol(string s)
{
    string out = "";
    for (int i = 0; i < s.length(); i++)
    {
        int cnt = 1;
        while (s[i] == s[i + 1])
            cnt++, i++;
        char value = cnt + '0';
        out = out + value + s[i];
    }
    cout << out<<endl;
}

int main()
{

    string s;
    cin >> s;
    sol(s);
    return 0;
}