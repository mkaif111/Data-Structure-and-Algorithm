#include <bits/stdc++.h>
using namespace std;
bool ispar(string x)
{
    // Your code here
    stack<char> s;
    for (auto it : x)
    {
        if (it == '{' or it == '[' or it == '(')
            s.push(it);
        else
        {
            if (it == '}')
            {
                if (!s.empty() and s.top() == '{')
                    s.pop();
                else
                    return false;
            }
            else if (it == ']')
            {
                if (!s.empty() and s.top() == '[')
                    s.pop();
                else
                    return false;
            }
            else if (it == ')')
            {
                if (!s.empty() and s.top() == '(')
                    s.pop();
                else
                    return false;
            }
        }
    }

    return s.empty();
}

int main()
{
    string s;
    cin >> s;
    cout << ispar(s) << endl;
    return 0;
}