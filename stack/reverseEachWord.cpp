#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string S)
    {
        //code here.
        stack<char> s;
        string out = "";
        for (auto it : S)
        {
            if (it == '.')
            {
                while (!s.empty())
                    out += s.top(), s.pop();
                out += '.';
            }
            else
                s.push(it);
        }

        // out = out.substr(0,out.length()-1);
        while (!s.empty())
            out += s.top(), s.pop();
        return out;
    }
};

int main()
{

    return 0;
}