#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> s;
void solve(string input, int i)
{
    if (i == input.length())
    {
        s.insert(input);
        return;
    }

    for (int j = i; j < input.length(); j++)
    {
        swap(input[i], input[j]);
        solve(input, i + 1);
        swap(input[i], input[j]);
    }
    return;
}
int main()
{
    string str;
    cin >> str;
    solve(str, 0);
    for (auto x : s)
    {
        cout << x << "\n";
    }

    return 0;
}