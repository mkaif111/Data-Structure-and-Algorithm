#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;
    deque<int> q(k);
    int i = 0;
    for (; i < k; i++)
    {

        while (!q.empty() and arr[i] >= arr[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }

    for (; i < n; i++)
    {
        cout << arr[q.front()] << " ";
        while ((!q.empty()) and (q.front() <= i - k))
        {
            q.pop_front();
        }
        while ((!q.empty()) and (arr[i] >= arr[q.back()]))
        {
            q.pop_back();
        }
        q.push_back(i);
    }

    cout << arr[q.front()] << endl;

    return 0;
}