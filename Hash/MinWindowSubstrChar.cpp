#include <bits/stdc++.h>
using namespace std;

string sol(string s, string p)
{
    if (p.length() > s.length())
        return "No String";
    unordered_map<char, int> PF, FS;
    for (auto it : p)
        PF[it]++;
    int cnt = 0;
    int minLen = INT_MAX;
    int start = 0;
    int startIdx = -1;
    for (int i = 0; i < s.length(); i++)
    {
        FS[s[i]]++;
        if (PF[s[i]] != 0 and FS[s[i]] <= PF[s[i]])
            cnt++;
        if (cnt == p.length())
        {
            char temp = s[start];
            while (PF[temp] == 0 or FS[temp] > PF[temp])
            {
                FS[temp]--;
                start++;
                temp = s[start];
            }
            if (i - start + 1 < minLen)
            {
                startIdx = start;
                minLen = i - start + 1;
            }
        }
    }

    if (startIdx == -1)
        return "No String";
    string ans = s.substr(startIdx, minLen);
    return ans;
}
int main()
{
    string s, p;
    getline(cin, s);
    getline(cin, p);
    cout << sol(s, p) << endl;
    return 0;
}