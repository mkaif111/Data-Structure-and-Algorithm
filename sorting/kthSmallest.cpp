#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    //code here
    priority_queue<int> p;
    for (int i = l; i <= r; i++)
    {
        p.push(arr[i]);
        if (p.size() > k)
        {
            p.pop();
        }
    }

    int ans = p.top();
    return ans;
}
int main()
{

    return 0;
}