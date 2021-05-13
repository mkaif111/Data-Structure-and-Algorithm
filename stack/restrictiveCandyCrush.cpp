#include <bits / stdc++.h>
using namespace std;
class Solution
{
public:
    string Reduced_String(int k, string S)
    {
        // Your code goes here
        int n = S.length();
        if (k == 1)
            return "";
        stack<pair<char, int>> s;
        for (int i = 0; i < n; i++)
        {
            if (s.empty())
                s.push({S[i], 1});
            else
            {
                if (s.top().first == S[i])
                {
                    s.push({S[i], s.top().second + 1});
                    if (s.top().second >= k)
                    {
                        int x = k;
                        while (x--)
                            s.pop();
                    }
                }
                else
                    s.push({S[i], 1});
            }
        }

        string output = "";
        while (!s.empty())
            output += s.top().first, s.pop();

        reverse(output.begin(), output.end());

        return output;
    }
};