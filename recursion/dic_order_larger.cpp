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
	bool flag = false;
    for (auto x : s)
    {   if (flag)
       { cout << x << "\n";
	   	}
		if(x==str)
			flag = true;
    }

    return 0;
}