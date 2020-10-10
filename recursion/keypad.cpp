#include <iostream>
#include <map>
using namespace std;
int count = 0;
void generate_str(string s, string output, int index, map<int, string> m)
{
    if (index >= s.length())
    {
        count++;
        cout << output << " ";
        return;
    }
    int d = s[index] - '0';
    if (d == 0)
    {
        generate_str(s, output, index + 1, m);
    }
    else
    {
        string c = m[d];
        for (int i = 0; i < c.length(); i++)
        {
            generate_str(s, output + c[i], index + 1, m);
        }
    }

    return;
}
int main()
{
    string s;
    cin >> s;
    map<int, string> m;
    m[1] = "abc";
    m[2] = "def";
    m[3] = "ghi";
    m[4] = "jkl";
    m[5] = "mno";
    m[6] = "pqrs";
    m[7] = "tuv";
    m[8] = "wx";
    m[9] = "yz";
    generate_str(s, "", 0, m);
    cout << endl;
    cout << count << endl;
    return 0;
}