#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> prevSmaller(vector<int> &A)
{
    int n = A.size();
    stack<int> s;
    vector<int> ans;
    ans.push_back(-1);
    s.push(A[0]);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() and A[i] <= s.top())
        {
            s.pop();
        }
        int res = (s.empty()) ? -1 : s.top();
        ans.push_back(res);
        s.push(A[i]);
    }

    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        A.push_back(d);
    }

    vector<int> ans = prevSmaller(A);
    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
}