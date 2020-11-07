#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

// You are given an array of numbers and a target number(T),
// print all unique combinations in the array whose sum equals the target number T.
// Note that each number in
//  the array may only be used once in the combination.

set<vector<int>> check;
void solve(int sum, int n, vector<int> v, vector<int> ans)
{
    if (n == 0)
        return;

    //base case
    if (sum == 0 and ans.size() > 0)
    {
        if (check.count(ans) > 0)
        {
            return;
        }
        // for(auto it: ans){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        check.insert(ans);
        return;
    }
    solve(sum, n - 1, v, ans);
    ans.push_back(v[n - 1]);
    solve(sum - v[n - 1], n - 1, v, ans);

    return;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        // int el;
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    vector<int> ans;
    int sum;
    cin >> sum;
    solve(sum, n, v, ans);
    for (auto it : check)
    {
        for (auto el : it)
        {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}