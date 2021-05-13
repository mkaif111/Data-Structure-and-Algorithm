#include <iostream>
#include <stack>
using namespace std;

void sol(int arr[], int n)
{
    int cir[n];
    for (int i = 0; i < n; i++)
        cir[i] = -1;
    stack<int> s;
    for (int i = 0; i < 2 * n; i++)
    {
        while (!s.empty() and arr[s.top()] < arr[i % n])
            cir[s.top()] = arr[i % n], s.pop();
        s.push(i % n);
    }
    for (int i = 0; i < n; i++)
        cout << cir[i] << " ";
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sol(arr, n);
    return 0;
}