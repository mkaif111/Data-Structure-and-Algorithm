#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> Anagrams(vector<string> &string_list)
{
    // Your Code Here
    unordered_map<string, vector<string>> m;
    for (auto it : string_list)
    {
        string temp = it;
        sort(temp.begin(), temp.end());
        m[temp].push_back(it);
    }

    vector<vector<string>> ans;
    for (auto it : m)
    {
        ans.push_back(it.second);
    }

    return ans;
}