#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //Function to find maximum of minimums of every window size.
    vector<int> maxOfMin(int arr[], int n)
    {
        // Your code here
        int left[n];
        int right[n];

        for (int i = 0; i < n; i++)
            left[i] = -1, right[i] = n;

        stack<int> s;
        for (int i = 0; i < n; i++)
        {

            while (!s.empty() and arr[s.top()] >= arr[i])
                s.pop();

            if (!s.empty())
                left[i] = s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() and arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty())
                right[i] = s.top();
            s.push(i);
        }

        vector<int> ans(n + 1);
        for (int i = 0; i < n; i++)
        {
            int len = right[i] - left[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }
        for (int i = n - 1; i >= 1; i--)
            ans[i] = max(ans[i], ans[i + 1]);

        ans.erase(ans.begin());
        return ans;
    }
};

int main()
{
    return 0;
}