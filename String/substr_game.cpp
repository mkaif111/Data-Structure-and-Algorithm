#include <iostream>
#include <string>
using namespace std;

string solve(string A)
{
    if (A.size() == 1)
        return "Bob";
    int h[26] = {0};
    for (int i = 0; i < A.size(); i++)
    {
        h[A[i] - 'a']++;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++)
        if (h[i] > 0)
            cnt++;
    if (cnt == 1)
        return "Bob";
    return "Alice";
}

int main()
{

    string s;
    cin >> s;
    cout << solve(s) << endl;
}